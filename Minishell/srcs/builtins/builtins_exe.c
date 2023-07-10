/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:30:48 by eramusho          #+#    #+#             */
/*   Updated: 2023/07/06 10:13:19 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_builtins(t_cmd *cmnd)
{
	if (!ft_strncmp(cmnd->cmd_arr[0], "exit", 5))
		return (1);
	if (!ft_strncmp(cmnd->cmd_arr[0], "env", 4))
		return (1);
	if (!ft_strncmp(cmnd->cmd_arr[0], "pwd", 4))
		return (1);
	if (!ft_strncmp(cmnd->cmd_arr[0], "echo", 5))
		return (1);
	if (!ft_strncmp(cmnd->cmd_arr[0], "cd", 3))
		return (1);
	if (!ft_strncmp(cmnd->cmd_arr[0], "unset", 6))
		return (1);
	if (!ft_strncmp(cmnd->cmd_arr[0], "export", 7))
		return (1);
	return (0);
}

int	check_execute(t_cmd *cmnd, char *cmd_name, int cmd_len,
						void (*builtin_func)(t_ms*, char**))
{
	if (!ft_strncmp(cmnd->cmd_arr[0], cmd_name, cmd_len))
	{
		if (cmnd->next)
			return (1);
		(*builtin_func)(cmnd->ms_struct, cmnd->cmd_arr);
		return (1);
	}
	return (0);
}

int	builtin_parent_only(t_cmd *cmnd)
{
	signal_not_interactive();
	if (cmnd->cmd_arr[1] && check_execute(cmnd, "export", 7, \
		&builtin_export) == 1)
		return (1);
	if (check_execute(cmnd, "unset", 6, &builtin_unset) == 1)
		return (1);
	if (check_execute(cmnd, "cd", 3, &builtin_cd) == 1)
		return (1);
	if (!ft_strncmp(cmnd->cmd_arr[0], "exit", 5) 
		&& cmnd->next == NULL && cmnd->num == 0)
	{
		builtin_exit(cmnd);
		return (1);
	}
	return (0);
}

static void	pwd_helper(t_cmd *cmnd)
{
	if (cmnd->cmd_arr[1])
	{
		ft_exit_status("no arguments\n", 1, "pwd");
		return ;
	}
	builtin_pwd(cmnd->ms_struct);
}

int	builtin_runable_child(t_cmd *cmnd)
{
	if (!ft_strncmp(cmnd->cmd_arr[0], "env", 4))
	{
		if (cmnd->cmd_arr[1])
		{
			ft_exit_status("no arguments\n", 1, "env");
			return (1);
		}
		output_env_ll(cmnd->ms_struct);
		return (1);
	}
	else if (!ft_strncmp(cmnd->cmd_arr[0], "echo", 5))
	{
		builtin_echo(cmnd->cmd_arr);
		return (1);
	}
	else if (!ft_strncmp(cmnd->cmd_arr[0], "pwd", 4))
	{
		pwd_helper(cmnd);
		return (1);
	}
	else if (export_helper(cmnd))
		return (1);
	return (0);
}
