/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exe_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 01:02:07 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/06 10:13:20 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	export_helper(t_cmd *cmnd)
{
	if (!ft_strncmp(cmnd->cmd_arr[0], "export", 7) && cmnd->cmd_arr[1] == NULL)
	{
		builtin_export(cmnd->ms_struct, cmnd->cmd_arr);
		return (1);
	}
	if (!ft_strncmp(cmnd->cmd_arr[0], "exit", 5) 
		&& cmnd->num != 0)
	{
		if (cmnd->cmd_arr[1] && ft_isnum(cmnd->cmd_arr[1]) 
			&& !cmnd->cmd_arr[2])
			g_exit = ft_atoi(cmnd->cmd_arr[1]);
		else if (cmnd->cmd_arr[1] && ft_isnum(cmnd->cmd_arr[1])
			&& cmnd->cmd_arr[2])
			ft_exit_status("too many arguments\n", 1, "exit");
		else
			g_exit = 0;
		return (1);
	}
	return (0);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
