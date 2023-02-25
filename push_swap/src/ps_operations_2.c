/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:51:35 by mtrautne          #+#    #+#             */
/*   Updated: 2023/02/19 18:34:24 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// Swap the first 2 elements at the top of stack x. Do nothing if there is 
// only one or no elements.
void	swap_x(t_node **stack_x)
{
	t_node	*temp_1;
	t_node	*temp_2;

	if ((*stack_x) == NULL || (*stack_x)->next == NULL)
		return ;
	temp_1 = (*stack_x);
	temp_2 = (*stack_x)->next->next;
	(*stack_x) = (*stack_x)->next;
	(*stack_x)->next = temp_1;
	temp_1->next = temp_2;
}

void	swap_both(t_node **stack_a, t_node **stack_b)
{
	swap_x(stack_a);
	swap_x(stack_b);
}

void	rotate_push(t_node **stack_a, t_node **stack_b)
{
	rotate_stack(stack_a);
	ft_putstr_fd("ra\n", 1);
	push_stack(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}
