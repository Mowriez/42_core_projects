/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 23:09:30 by eramusho          #+#    #+#             */
/*   Updated: 2023/07/05 19:03:02 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	heredoc_child_signal(void)
{
	signal(SIGINT, &heredoc_exit);
	signal(SIGQUIT, SIG_IGN);
}

void	heredoc_parent_signal(void)
{
	signal(SIGQUIT, &interactive_sigint);
	signal(SIGINT, SIG_IGN);
}

// represents the child process created for
// reading the heredoc input and writing it to the pipe
// to send the users input to the parent process
void	heredoc_child_process(int *pipe_fd, char *delimiter_str)
{
	char	*ret;

	close(pipe_fd[READ]);
	while (1)
	{
		heredoc_child_signal();
		ret = readline("heredoc> ");
		if (!ret)
		{
			close(pipe_fd[WRITE]);
			exit(0);
		}
		if (ft_strncmp(ret, delimiter_str, ft_strlen(delimiter_str)) == 0 && \
			ret[(int)ft_strlen(delimiter_str)] == 0)
		{
			free(ret);
			close(pipe_fd[WRITE]);
			exit(0);
		}
		write(pipe_fd[WRITE], ret, ft_strlen(ret));
		write(pipe_fd[WRITE], "\n", 1);
		free(ret);
	}
}

// manage the pipe communication and
// control flow based on the status of the child process.
int	heredoc_parent_process(pid_t pid, int *pipe_fd)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 23)
		{
			close(pipe_fd[WRITE]);
			if (pipe(pipe_fd) == -1)
				return (ft_strerror_status(errno, "close"));
			close(pipe_fd[WRITE]);
		}
	}
	return (0);
}

// manages whole heredoc process.
int	ft_heredoc(t_cmd *cmnd, char *delimiter_str)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (cmnd->input_fd != 0)
		close(cmnd->input_fd);
	if (pipe(pipe_fd) == -1)
		return (ft_strerror_status(errno, "pipe"));
	pid = fork();
	if (pid == -1)
		return (ft_strerror_status(errno, "pipe"));
	heredoc_parent_signal();
	if (pid == 0)
		heredoc_child_process(pipe_fd, delimiter_str);
	if (pid > 0)
	{
		if (heredoc_parent_process(pid, pipe_fd) == -1)
			return (-1);
		cmnd->input_fd = pipe_fd[READ];
	}
	close(pipe_fd[WRITE]);
	return (0);
}
