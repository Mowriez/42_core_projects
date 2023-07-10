/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:11:41 by eramusho          #+#    #+#             */
/*   Updated: 2023/07/05 19:58:03 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// check if number is a number and positive 
int	is_number(char *str)
{
	int	index;	

	index = 0;
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
			return (0);
		index++;
	}
	return (1);
}

/*exit function that sets the right exit codes and closes the program*/
void	builtin_exit(t_cmd *data)
{
	t_ms	*ms_struct;

	if (data->cmd_arr[1] && data->cmd_arr[2])
	{
		ft_putstr_fd("Error exit: too many arguments\n", 2);
		g_exit = 1;
	}
	else if (data->cmd_arr[1] && !is_number(data->cmd_arr[1]))
	{
		ft_putstr_fd("Error exit: numeric argument required\n", 2);
		g_exit = 255;
	}
	else if (data->cmd_arr[1])
		g_exit = ft_atoi(data->cmd_arr[1]);
	g_exit = g_exit % 256;
	ft_putstr_fd("exit\n", 1);
	ms_struct = data->ms_struct;
	free_cmd_ll(data->ms_struct->cmd_ll);
	free_ms_struct(ms_struct);
	rl_clear_history();
	exit(g_exit);
}
