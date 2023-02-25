/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:43:07 by mtrautne          #+#    #+#             */
/*   Updated: 2023/02/19 20:51:42 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_input_shallow(argc, argv);
	build_stack_a(argc, argv, &stack_a);
	is_stack_sorted(&stack_a);
	sort_stack(&stack_a, &stack_b);
	free_list(&stack_a);
}

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	if (list_len(stack_a) <= 5)
		small_stack_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

// function to print a stack to terminal

// void	print_stack(char stack, t_node **stack_x)
// {
// 	int		i;
// 	t_node	*temp1;

// 	i = 0;
// 	temp1 = (*stack_x);
// 	while ((temp1 != NULL))
// 	{
// 		pf("stack_%c[%i]: i: %i\n", stack, i, temp1->index);
// 		temp1 = temp1->next;
// 		i++;
// 	}
// }
