/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:45:32 by mtrautne          #+#    #+#             */
/*   Updated: 2023/07/01 02:16:06 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*initialises the linked list for our env-variables and populates it with the
variables of the system env*/
void	init_env_list(t_ms *ms_struct, char **envp)
{
	int		i;
	int		len_arr;
	t_env	*head;
	t_env	*new_node;

	i = 0;
	len_arr = 0;
	head = NULL;
	while (envp[len_arr])
		len_arr++;
	while (i < len_arr)
	{
		new_node = make_new_node(envp[i]);
		add_env_node_end(&head, new_node);
		i++;
	}
	ms_struct->env_ll = head;
}

/*initialises a new environment node and populates it with the env string 
argument provided to the function.*/
t_env	*make_new_node(char *str)
{
	t_env	*new_node;
	char	**str_arr;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	str_arr = ft_split_env(str);
	new_node->string = ft_strdup(str);
	new_node->key = ft_strdup(str_arr[0]);
	new_node->value = ft_strdup(str_arr[1]);
	free(str_arr[0]);
	free(str_arr[1]);
	free(str_arr);
	new_node->next = NULL;
	return (new_node);
}

/*manipulates the linked lists and nodes pointers to add the node to the
end of the list*/
void	add_env_node_end(t_env **head, t_env *new_node)
{
	t_env	*current;

	current = *head;
	if (*head == NULL)
		*head = new_node;
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}

/*makes an array from the current state of the env_ll for
execve*/
char	**init_env_arr(t_env *env_head)
{
	t_env	*temp;
	char	**arr;
	int		i;

	temp = env_head;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	arr = malloc((i + 1) * sizeof(char *));
	temp = env_head;
	i = 0;
	while (temp)
	{
		arr[i++] = ft_strdup(temp->string);
		temp = temp->next;
	}
	arr[i] = NULL;
	return (arr);
}
