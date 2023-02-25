/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sort_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:09:39 by mtrautne          #+#    #+#             */
/*   Updated: 2023/02/20 01:20:51 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	reverse_sort_2(t_node **stack_b)
{
	if ((*stack_b)->index < (*stack_b)->next->index)
	{
		swap_x(stack_b);
		ft_putstr_fd("sb\n", 1);
	}
}
