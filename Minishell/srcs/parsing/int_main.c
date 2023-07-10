/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:22:11 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/05 13:34:09 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*takes the linked-list created by the lexer and iterates over it to create
the linked list with commands that are processed by the execution & 
builtin functions. cntr triggers cmd path population with every first token
in a set (between pipes).*/
void	interpreter(t_token **token_ll, t_ms *ms_struct)
{
	t_token	*token;
	t_cmd	*cmd_node;
	int		cmd_num;
	int		cntr;

	token = *token_ll;
	cmd_node = malloc(sizeof(t_cmd));
	ms_struct->cmd_ll = cmd_node;
	cmd_num = 0;
	while (token != NULL)
	{
		cntr = 0;
		init_cmd_node(ms_struct, cmd_node, &token, cmd_num);
		token = iterate_lex_ll(cmd_node, &token, &cntr);
		if (token != NULL && token->type == PIPE)
		{
			cmd_num = cmd_num + 1;
			cmd_node->next = new_cmd_node();
			cmd_node = cmd_node->next;
			token = token->next;
		}
	}
}

/* Mallocs and initialises the first node in the command linked list. One node 
is used for all input that is not seperated by a pipe-character.*/
void	init_cmd_node(t_ms *ms_struct, t_cmd *cmd_node, t_token **token, \
							int cmd_num)
{
	int	i;
	int	args_num;

	i = 0;
	args_num = count_str_nbr(*token);
	cmd_node->cmd_arr = malloc((args_num + 1) * sizeof(char *));
	cmd_node->cmd = NULL;
	while (i < args_num + 1)
	{
		cmd_node->cmd_arr[i] = NULL;
		i++;
	}
	cmd_node->num = cmd_num;
	cmd_node->ms_struct = ms_struct;
	cmd_node->input_fd = STDIN_FILENO;
	cmd_node->output_fd = STDOUT_FILENO;
	cmd_node->next = NULL;
}

/* Counts the amount of string tokens for the current cmd-node to allocate
enough space for the cmd array. (Basically all the string-tokens until the
next pipe or null-terminator)*/
int	count_str_nbr(t_token *token)
{
	int		nbr;
	t_token	*temp;

	nbr = 0;
	temp = token;
	while (temp != NULL && temp->type != PIPE)
	{
		if (temp->type == STRING)
			nbr++;
		temp = temp->next;
	}
	return (nbr);
}

/* In the case of pipe, initialises a new cmd node
and returns it prefilled.*/
t_cmd	*new_cmd_node(void)
{
	t_cmd	*new_cmd;

	new_cmd = malloc(sizeof(t_cmd));
	return (new_cmd);
}
