/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:48:39 by mtrautne          #+#    #+#             */
/*   Updated: 2023/02/18 22:33:05 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_node	*make_new_node(int index)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->index = index;
	new_node->next = NULL;
	return (new_node);
}

void	add_node_start(t_node **list, t_node *new_node)
{
	new_node->next = *list;
	*list = new_node;
}

void	add_node_end(t_node **list, t_node *new_node)
{
	t_node	*current;

	current = *list;
	if (*list == NULL)
		*list = new_node;
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}

long	list_len(t_node **list)
{
	long	count;
	t_node	*current;

	count = 1;
	current = *list;
	if (current == NULL)
		return (0);
	while (current->next != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}

void	free_list(t_node **list)
{
	t_node	*temp;

	while ((*list) != NULL)
	{
		temp = (*list)->next;
		free(*list);
		*list = temp;
	}
}
