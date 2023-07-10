/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:17:58 by eramusho          #+#    #+#             */
/*   Updated: 2023/07/05 23:03:52 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	check_prev_cmnd_exists(int *prev_pipe_fds, t_cmd *cmnd,
	int prev_cmnd_exists)
{
	if (prev_cmnd_exists)
	{
		dup2(prev_pipe_fds[READ], STDIN_FILENO);
		close(prev_pipe_fds[READ]);
		close(prev_pipe_fds[WRITE]);
	}
	else
	{
		if (cmnd->input_fd != 0)
		{
			dup2(cmnd->input_fd, STDIN_FILENO);
			close(cmnd->input_fd);
		}
	}
}

void	redir_child_io(int *prev_pipe_fds, int *next_pipe_fds,
			t_cmd *cmnd, int prev_cmnd_exists)
{
	check_prev_cmnd_exists(prev_pipe_fds, cmnd, prev_cmnd_exists);
	if (cmnd->next != NULL)
	{
		if (next_pipe_fds[READ] != -6)
			close(next_pipe_fds[READ]);
		dup2(next_pipe_fds[WRITE], STDOUT_FILENO);
		close(next_pipe_fds[WRITE]);
	}
	else
	{
		if (next_pipe_fds[READ] != -6)
			close(next_pipe_fds[READ]);
		if (cmnd->output_fd != 1)
		{
			dup2(cmnd->output_fd, STDOUT_FILENO);
			close(cmnd->output_fd);
		}
		if (next_pipe_fds[WRITE] != -6)
			close(next_pipe_fds[WRITE]);
	}
}

void	redir_parent_io(int *prev_pipe_fds, int *next_pipe_fds,
	t_cmd *cmnd)
{
	if (cmnd->num != 0)
	{
		close(prev_pipe_fds[WRITE]);
		close(prev_pipe_fds[READ]);
	}
	else
	{
		if (cmnd->input_fd != 0)
		{
			close(cmnd->input_fd);
		}
	}
	if (cmnd->next != NULL)
	{
		prev_pipe_fds[READ] = next_pipe_fds[READ];
		prev_pipe_fds[WRITE] = next_pipe_fds[WRITE];
	}
}

int	setup_pipe_builtin(t_cmd *cmnd, int *prev_pipe_fds, int *next_pipe_fds, \
	int redirect_needed)
{
	if (cmnd->next)
	{
		if (pipe(next_pipe_fds))
		{
			ft_exit_status("Could not create pipe\n", 1, "execution");
			return (0);
		}
		if (redirect_needed)
			redir_parent_io(prev_pipe_fds, next_pipe_fds, cmnd);
	}
	return (1);
}
