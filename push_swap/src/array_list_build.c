/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_list_build.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 00:55:47 by mtrautne          #+#    #+#             */
/*   Updated: 2023/02/18 22:40:34 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// a single argument string contains all numbers.
void	build_array_single(long *arr, char *str)
{
	long	i;
	char	**str_args;

	i = 0;
	str_args = ft_split(str, ' ');
	while (str_args[i])
	{
		arr[i] = ft_atol(str_args[i]);
		i++;
	}
	while (i >= 0)
	{
		free(str_args[i]);
		i--;
	}
	free(str_args);
}

// multiple argument strings contain the individual numbers.
void	build_array_multi(long *arr, int arg_cnt, char **arg_val)
{
	long	i;

	i = 0;
	while (i < (arg_cnt))
	{
		arr[i] = ft_atol(arg_val[i + 1]);
		i++;
	}
}

// tailored bubble sort? algorithm: instead of swapping 2 neigboring args it's
// just adding 1 to the index of the current num if it finds a smaller number.
// -> [30, -10, 20] becomes [3, 1, 2].
void	index_array(long *arr, int arr_len)
{
	long	i;
	long	j;
	long	*index_arr;

	i = 0;
	index_arr = malloc(arr_len * sizeof(long));
	while (i < arr_len)
	{
		index_arr[i] = 1;
		j = 0;
		while (j < arr_len)
		{
			if (arr[i] > arr[j])
				index_arr[i]++;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < arr_len)
	{
		arr[i] = index_arr[i];
		i++;
	}
	free(index_arr);
}

// build linked list from error free array.
void	build_list_a(long arr_len, long *ind_arr, t_node **stack_a)
{
	int		i;
	t_node	*new_node;

	i = 0;
	while (i < arr_len)
	{
		new_node = make_new_node(ind_arr[i]);
		add_node_end(stack_a, new_node);
		i++;
	}
}

// tests input, creates array, tests array, builds linked list stack a
void	build_stack_a(int arg_cnt, char **arg_val, t_node **stack_a)
{
	long	*input_arr;
	long	arr_len;

	if (arg_cnt == 2 && count_input_args(arg_val[1]) != 0)
	{
		arr_len = count_input_args(arg_val[1]);
		input_arr = malloc(arr_len * sizeof(long));
		build_array_single(input_arr, arg_val[1]);
	}
	else
	{
		arr_len = arg_cnt - 1;
		input_arr = malloc(arr_len * sizeof(long));
		build_array_multi(input_arr, arr_len, arg_val);
	}
	if (check_num_array(input_arr, arr_len) == 1)
		exit(1);
	index_array(input_arr, arr_len);
	build_list_a(arr_len, input_arr, stack_a);
	free(input_arr);
}
