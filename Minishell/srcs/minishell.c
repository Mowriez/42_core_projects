/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:28:41 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/05 21:10:36 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	g_exit = 0;

int	main(int argc, char **argv, char **envp)
{
	t_ms		*ms_struct;
	int			status;

	check_args(argc, argv);
	ms_struct = init_ms_struct(envp);
	while (1)
	{
		status = run_shell(ms_struct);
		if (status == -1)
			break ;
	}
	free_cmd_ll(ms_struct->cmd_ll);
	free_ms_struct(ms_struct);
	return (g_exit);
}
