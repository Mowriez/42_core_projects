/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:16:30 by mtrautne          #+#    #+#             */
/*   Updated: 2023/02/18 22:31:37 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//Shift up all elements of stack x by 1. The first element becomes the last one.
void	rotate_stack(t_node **stack_x)
{
	t_node	*temp;
	t_node	*new_last;

	if (stack_x == NULL || (*stack_x)->next == NULL)
		return ;
	temp = *stack_x;
	new_last = *stack_x;
	*stack_x = (*stack_x)->next;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_last;
	new_last->next = NULL;
}

void	reverse_rotate_stack(t_node **stack_x)
{
	t_node	*temp;
	t_node	*new_last;
	t_node	*new_first;

	if (stack_x == NULL || (*stack_x)->next == NULL)
		return ;
	temp = *stack_x;
	new_last = *stack_x;
	new_first = *stack_x;
	while (new_last->next->next != NULL)
		new_last = new_last->next;
	new_first = new_last->next;
	new_last->next = NULL;
	*stack_x = new_first;
	(*stack_x)->next = temp;
}

void	rotate_both(t_node **stack_a, t_node **stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
}

void	reverse_rotate_both(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
}

void	push_stack(t_node **stack_x, t_node **stack_y)
{
	t_node	*temp;

	if (stack_x == NULL)
		return ;
	temp = (*stack_x);
	(*stack_x) = (*stack_x)->next;
	temp->next = (*stack_y);
	(*stack_y) = temp;
}
