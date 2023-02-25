/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:25:09 by mtrautne          #+#    #+#             */
/*   Updated: 2023/02/18 22:41:58 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	j;
	int	max_index;
	int	bit_len;
	int	temp_index;

	i = 0;
	max_index = find_max_index(stack_a);
	bit_len = 0;
	while ((max_index >> bit_len) != 0)
		bit_len++;
	while (i < bit_len)
	{
		j = 0;
		while (j < max_index)
		{
			temp_index = (*stack_a)->index;
			sort_by_last_bit(temp_index, i, stack_a, stack_b);
			j++;
		}
		empty_stack_b(stack_a, stack_b);
		i++;
	}
}

void	sort_by_last_bit(int index, int i, t_node **stack_a, t_node **stack_b)
{
	if (((index >> i) & 1) == 1)
	{
		ft_putstr_fd("ra\n", 1);
		rotate_stack(stack_a);
	}
	else
	{	
		ft_putstr_fd("pb\n", 1);
		push_stack(stack_a, stack_b);
	}
}

int	find_max_index(t_node **stack_a)
{
	int		max;
	t_node	*temp;

	temp = (*stack_a);
	max = 0;
	while (temp->next != NULL)
	{	
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}

void	empty_stack_b(t_node **stack_a, t_node **stack_b)
{
	if (stack_b == NULL)
		return ;
	while ((*stack_b) != NULL)
	{
		ft_putstr_fd("pa\n", 1);
		push_stack(stack_b, stack_a);
	}
}
