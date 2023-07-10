/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 08:23:51 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/05 18:07:34 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*main function for the parsing part of minishell. Calls the elements of the
parser, mainly the lexer and interpreter.*/
int	parser(t_ms *ms_struct)
{
	char	*rl_input_exp;
	t_token	*head;

	head = NULL;
	rl_input_exp = expand_input(ms_struct);
	lexer(rl_input_exp, &head);
	free(rl_input_exp);
	interpreter(&head, ms_struct);
	free_token_ll(head);
	return (0);
}

/* Initialises the main struct (ms_struct)*/
t_ms	*init_ms_struct(char **envp)
{
	t_ms	*ms_struct;

	ms_struct = malloc(sizeof(t_ms));
	if (!ms_struct)
	{
		write(1, "Error: Main struct allocation failed.\n", 39);
		exit (1);
	}
	ms_struct->og_env = envp;
	init_env_list(ms_struct, envp);
	update_shlvl(ms_struct);
	ms_struct->rl_input = NULL;
	ms_struct->new_path = NULL;
	ms_struct->old_path = NULL;
	ms_struct->cmd_ll = NULL;
	return (ms_struct);
}
