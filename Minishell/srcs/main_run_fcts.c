/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_run_fcts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:47:19 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/05 21:06:52 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_eof(t_ms *ms_struct)
{
	ft_putstr_fd("exit\n", 1);
	free_ms_struct(ms_struct);
	rl_clear_history();
	exit(g_exit);
}

/*main run function which calls the parser, executer and references to the
builtins*/
int	run_shell(t_ms *ms_struct)
{
	signal_interactive();
	if (input_prompt(ms_struct) == -1)
		return (-1);
	if (!ms_struct->rl_input[0])
	{
		g_exit = 0;
		return (1);
	}
	if (check_rl_input(ms_struct) == -1)
		return (1);
	if (parser(ms_struct) == -1)
		return (1);
	run_commands(ms_struct->cmd_ll);
	clean_up_run(ms_struct);
	return (1);
}

/*calls the readline function to prompt the user.*/
int	input_prompt(t_ms *ms_struct)
{
	ms_struct->rl_input = readline("Minishell$ ");
	if (!ms_struct->rl_input)
		free_eof(ms_struct);
	if (ft_strlen(ms_struct->rl_input) > 0)
		add_history(ms_struct->rl_input);
	return (0);
}
