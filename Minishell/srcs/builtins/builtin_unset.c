/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:53:44 by eramusho          #+#    #+#             */
/*   Updated: 2023/07/05 15:45:46 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

//unset PATH -> ls doesn't work anymnore, cause PATH is deleted 
void	free_node(t_env *node)
{
	free(node->string);
	free(node->key);
	free(node->value);
	free(node);
}
// frees the entire node

int	is_valid_var_name(char *key)
{
	int	index;

	index = 1;
	if (!ft_isalpha(key[0]) && key[0] != '_')
		return (0);
	while (key[index])
	{
		if (!ft_isalnum(key[index]) && key[index] != '_')
			return (0);
		index++;
	}
	return (1);
}
// checks if the variable name is valid

void	delete_var_env(t_ms *data, char *key)
{
	t_env	*current;
	t_env	*prev;
	int		key_size;

	key_size = ft_strlen(key);
	current = data->env_ll;
	prev = NULL;
	while (current != NULL)
	{
		if (ft_strncmp(current->key, key, key_size) == 0
			&& current->key[key_size] == '\0')
		{
			if (prev == NULL)
				data->env_ll = current->next;
			else
				prev->next = current->next;
			free_node(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}
// deletes the var in env and frees it

void	builtin_unset(t_ms *data, char **args)
{
	int	index;

	index = 1;
	while (args[index])
	{
		if (is_valid_var_name(args[index]) == 1)
		{
			delete_var_env(data, args[index]);
			g_exit = 0;
		}
		else
			ft_putstr_fd("Invalid parameter name\n", 2);
		index++;
	}
}
