/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:17:43 by eramusho          #+#    #+#             */
/*   Updated: 2023/07/10 22:24:11 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	wait_children(int pid, int *waitpid_status)
{
	while (pid > 0)
	{
		pid = wait(waitpid_status);
		if (WIFEXITED(*waitpid_status))
			g_exit = WEXITSTATUS(*waitpid_status);
	}
}

void	exe_child_proccess(int pid, int *prev_pipe_fds,
	int *next_pipe_fds, t_cmd *cmnd)
{
	char	**env_current;

	if (pid == 0)
	{
		signal_child_active();
		redir_child_io(prev_pipe_fds, next_pipe_fds, cmnd, cmnd->num);
		if (builtin_runable_child(cmnd))
			exit(g_exit);
		if (access(cmnd->cmd, X_OK) != 0)
		{
			ft_exit_status("command not found\n", 127, cmnd->cmd_arr[0]);
			exit(127);
		}
		else
		{
			env_current = copy_mod_env(cmnd->ms_struct->env_ll);
			execve(cmnd->cmd, cmnd->cmd_arr, env_current);
			free_double_arr(env_current);
			if (access(cmnd->cmd, F_OK) == 0)
				ft_exit_status("is a directory\n", 1, cmnd->cmd_arr[0]);
			else
				ft_exit_status("command not found\n", 127, cmnd->cmd_arr[0]);
			return ;
		}
	}
}

void	launch_child_handle_redir(int pid, int *prev_pipe_fds,
	int *next_pipe_fds, t_cmd *cmnd)
{
	exe_child_proccess(pid, prev_pipe_fds, next_pipe_fds, cmnd);
	redir_parent_io(prev_pipe_fds, next_pipe_fds, cmnd);
}

static void	init_run_struct(int *pid, int next_fds[2], int prev_fds[2])
{
	*pid = 0;
	next_fds[0] = -6;
	next_fds[1] = -6;
	prev_fds[0] = -6;
	prev_fds[1] = -6;
}

void	run_commands(t_cmd *cmnd)
{
	t_run	run;

	init_run_struct(&run.pid, run.next_fds, run.prev_fds);
	while (cmnd)
	{
		if (check_cmd_token_logic(cmnd))
		{
			cmnd = cmnd->next;
			continue ;
		}
		if (builtin_parent_only(cmnd))
		{
			if (!setup_pipe_builtin(cmnd, run.prev_fds, run.next_fds, 1))
				return ;
			cmnd = cmnd->next;
			continue ;
		}
		else if (!setup_pipe_builtin(cmnd, run.prev_fds, run.next_fds, 0))
			return ;
		if (fork_helper(&run.pid))
			return ;
		launch_child_handle_redir(run.pid, run.prev_fds, run.next_fds, cmnd);
		cmnd = cmnd->next;
	}
	wait_children(run.pid, &run.waitpid_status);
}
