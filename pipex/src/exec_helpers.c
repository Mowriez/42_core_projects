/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 07:52:03 by mtrautne          #+#    #+#             */
/*   Updated: 2023/03/18 21:08:30 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	*path_to_exec(t_pipex *vars, char *cmd)
{
	int		i;
	char	*temp_str;
	char	*full_path;

	i = 0;
	if (cmd[0] == '/')
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
	}
	while (vars->path_dirs[i] != NULL)
	{
		temp_str = ft_strjoin(vars->path_dirs[i], "/");
		full_path = ft_strjoin(temp_str, cmd);
		free(temp_str);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	error_handling(3, vars, cmd);
	return (NULL);
}

char	**set_exec_arr(t_pipex *vars, int i)
{
	char	*exec_path;
	char	**exec_arr;

	exec_arr = set_up_arr(vars, i);
	exec_path = path_to_exec(vars, exec_arr[0]);
	if (exec_path == NULL)
	{
		dup2(vars->empty_fd, STDIN_FILENO);
		free(exec_path);
		free_arr(exec_arr);
		return (NULL);
	}
	free(exec_arr[0]);
	exec_arr[0] = ft_strdup(exec_path);
	free(exec_path);
	return (exec_arr);
}

void	exec_cmd(t_pipex *vars, int i, char **envp)
{
	int		pid;
	int		pipe_fd[2];
	char	**exec_arr;

	exec_arr = set_exec_arr(vars, i);
	if (!exec_arr)
		return ;
	perror_check(pipe(pipe_fd), "piping error: ", vars);
	pid = fork();
	perror_check(pid, "fo(r)king error: ", vars);
	if (pid == 0)
	{
		close(pipe_fd[0]);
		perror_check(dup2(pipe_fd[1], STDOUT_FILENO), "piping error:", vars);
		if (execve(exec_arr[0], exec_arr, envp) < 0)
			vars->error = 2;
	}
	waitpid(pid, NULL, WNOHANG);
	close(pipe_fd[1]);
	perror_check(dup2(pipe_fd[0], STDIN_FILENO), "piping error: ", vars);
	free_arr(exec_arr);
}

void	exec_last_cmd(t_pipex *vars, int output_fd, int i, char **envp)
{
	int		pid;
	char	**exec_arr;

	exec_arr = set_exec_arr(vars, i);
	if (exec_arr == NULL)
	{
		vars->error = 127;
		return ;
	}
	pid = fork();
	perror_check(pid, "fo(r)king error: ", vars);
	if (pid == 0)
	{
		if (dup2(output_fd, STDOUT_FILENO) == -1)
		{
			perror("output");
			vars->error = 6;
			return ;
		}
		if (execve(exec_arr[0], exec_arr, envp) < 0 && vars->error == 0)
			vars->error = 127;
	}
	waitpid(pid, NULL, WNOHANG);
	free_arr(exec_arr);
}
