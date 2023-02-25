/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sort_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:43:42 by mtrautne          #+#    #+#             */
/*   Updated: 2023/02/20 01:54:32 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	small_stack_sort(t_node **stack_a, t_node **stack_b)
{
	if (list_len(stack_a) == 2)
	{
		swap_x(stack_a);
		ft_putstr_fd("sa\n", 1);
	}
	else if (list_len(stack_a) == 3)
		sort_3(stack_a);
	else if (list_len(stack_a) == 4)
		sort_4(stack_a, stack_b);
	else
		sort_5(stack_a, stack_b);
}

// hardcode for sorting 3 arguments
void	sort_3(t_node **stack_x)
{
	if ((*stack_x)->index < (*stack_x)->next->index && \
		(*stack_x)->next->index < (*stack_x)->next->next->index)
		return ;
	else if ((*stack_x)->index < (*stack_x)->next->index && \
			(*stack_x)->index < (*stack_x)->next->next->index)
	{
		swap_x(stack_x);
		ft_putstr_fd("sa\n", 1);
		rotate_stack(stack_x);
		ft_putstr_fd("ra\n", 1);
	}
	else
		helper_sort_3(stack_x);
}

void	helper_sort_3(t_node **stack_x)
{
	if ((*stack_x)->index > (*stack_x)->next->index && \
				(*stack_x)->index > (*stack_x)->next->next->index)
	{
		rotate_stack(stack_x);
		ft_putstr_fd("ra\n", 1);
		if ((*stack_x)->index > (*stack_x)->next->index)
		{
			swap_x(stack_x);
			ft_putstr_fd("sa\n", 1);
		}
	}
	else
	{
		if ((*stack_x)->index < (*stack_x)->next->index)
		{
			reverse_rotate_stack(stack_x);
			ft_putstr_fd("rra\n", 1);
		}
		else
		{
			swap_x(stack_x);
			ft_putstr_fd("sa\n", 1);
		}
	}
}

// sorting 4 arguments
void	sort_4(t_node **stack_a, t_node **stack_b)
{
	while (((*stack_a)->index) != 1)
	{
		rotate_stack(stack_a);
		ft_putstr_fd("ra\n", 1);
	}
	push_stack(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
	sort_3(stack_a);
	empty_stack_b(stack_a, stack_b);
}

// sorting 5 arguments
void	sort_5(t_node **stack_a, t_node **stack_b)
{
	while (((*stack_a)->index) != 1 && ((*stack_a)->index) != 2)
	{
		rotate_stack(stack_a);
		ft_putstr_fd("ra\n", 1);
	}
	push_stack(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
	while (((*stack_a)->index) != 1 && ((*stack_a)->index) != 2)
	{
		rotate_stack(stack_a);
		ft_putstr_fd("ra\n", 1);
	}
	push_stack(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
	sort_3(stack_a);
	reverse_sort_2(stack_b);
	empty_stack_b(stack_a, stack_b);
}
