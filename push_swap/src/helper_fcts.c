/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fcts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 00:21:51 by mtrautne          #+#    #+#             */
/*   Updated: 2023/02/18 22:42:10 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//prints to stderror...maybe replace by putstr_fd
int	ft_putstr_stderr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (i);
}

//neccessary for input in a single argument string
int	count_input_args(char *str)
{
	int		i;
	int		count;
	char	**temp_arr;

	i = 0;
	temp_arr = ft_split(str, ' ');
	while (temp_arr[i])
		i++;
	count = i;
	while (i >= 0)
	{
		free(temp_arr[i]);
		i--;
	}
	free(temp_arr);
	return (count);
}

//converts string to long type
long	ft_atol(char *str)
{
	int		i;
	long	factor;
	long	num;

	i = 0;
	factor = 1;
	num = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '-')
		factor = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i++] - '0';
	}
	return (num * factor);
}

//checks if linked list is sorted
void	is_stack_sorted(t_node **stack_a)
{
	int		sorted;
	t_node	*temp_1;
	t_node	*temp_2;

	sorted = 1;
	temp_1 = *stack_a;
	while (temp_1->next != NULL)
	{
		temp_2 = temp_1->next;
		if (temp_1->index > temp_2->index)
			sorted = 0;
		temp_1 = temp_2;
	}
	if (sorted == 1)
	{
		free_list(stack_a);
		exit(0);
	}
}
