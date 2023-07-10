/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:24:58 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/05 03:08:16 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*helper function which visualizes the env linked list*/
void	print_env_ll(t_env *head)
{
	t_env	*current;
	int		i;

	i = 0;
	current = head;
	while (current->next != NULL)
	{
		ft_printf("env_node [%i]:\n", i);
		ft_printf("string: %s\n", current->string);
		ft_printf("key: %s\n", current->key);
		ft_printf("value: %s\n", current->value);
		current = current->next;
		i++;
	}
	ft_printf("env_node [%i]:\n", i);
	ft_printf("string: %s\n", current->string);
	ft_printf("key: %s\n", current->key);
	ft_printf("value: %s\n", current->value);
}

/*helper function which visualizes the lexer token linked list*/
void	print_token_ll(t_token *head)
{
	t_token	*current;
	int		i;

	i = 0;
	current = head;
	while (current->next != NULL)
	{
		ft_printf("---- token %i ----\n", i);
		ft_printf("value: %s\n", current->value);
		ft_printf("type: %s\n\n", translate_type(current->type));
		current = current->next;
		i++;
	}
	ft_printf("---- token %i ----\n", i);
	ft_printf("value: %s\n", current->value);
	ft_printf("type: %s\n", translate_type(current->type));
	ft_printf("------------------\n");
}

/*translates the Makro-Numbers for the types back into their string values*/
char	*translate_type(int type)
{
	if (type == 1)
		return ("STRING");
	else if (type == 2)
		return ("DIV");
	else if (type == 3)
		return ("PIPE");
	else if (type == 4)
		return ("I_REDIR");
	else if (type == 5)
		return ("O_REDIR");
	else if (type == 6)
		return ("APPEND_REDIR");
	else if (type == 7)
		return ("H_DOC");
	else
		return ("undefined");
}

/*helper function which visualizes the cmd*/
void	print_cmd_ll(t_cmd *head)
{
	t_cmd	*current;
	int		i;
	int		j;

	i = 0;
	current = head;
	while (current != NULL)
	{
		j = 0;
		ft_printf("\n---- cmd %i ----\n", i);
		ft_printf("cmd: %s\n", current->cmd);
		ft_printf("cmd_num: %i\n", current->num);
		while (current->cmd_arr[j])
		{
			ft_printf("arr[%i]: %s\n", j, current->cmd_arr[j]);
			j++;
		}
		ft_printf("input_fd: %i\n", current->input_fd);
		ft_printf("output_fd: %i\n", current->output_fd);
		ft_printf("next_ptr: %p\n", current->next);
		current = current->next;
		i++;
	}
}
