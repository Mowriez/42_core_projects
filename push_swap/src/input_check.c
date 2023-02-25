/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:16:25 by mtrautne          #+#    #+#             */
/*   Updated: 2023/02/23 00:03:21 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//check string array for anything other than numerical chars or spaces.
void	check_input_shallow(int arg_cnt, char **arg_val)
{
	int	i;

	i = 0;
	if (arg_cnt < 2)
		exit (1);
	else if (arg_cnt == 2)
	{
		while (arg_val[1][i] == ' ' && arg_val[1][i + 1] != '\0')
			i++;
		if (arg_val[1][i] == '\0')
			error_print();
		i = 0;
		while (arg_val[1][i] != 0)
		{
			if (arg_val[1][i] != ' ' && arg_val[1][i] != '-' && \
				(arg_val[1][i] < '0' || arg_val[1][i] > '9'))
				error_print();
			else if (arg_val[1][i] == '-' && (arg_val[1][i + 1] == '-' \
			|| (arg_val[1][i + 1] == ' ') || (arg_val[1][i + 1] == '\0')))
				error_print();
			i++;
		}
	}
	else if (check_multi(arg_cnt, arg_val) == 1)
		error_print();
}

//write Error and Exit
void	error_print(void)
{
	ft_putstr_stderr("Error\n");
	exit (1);
}

//check if input in multiple strings
int	check_multi(int arg_cnt, char **arg_val)
{
	int	i;
	int	k;

	i = 1;
	while (i < arg_cnt)
	{
		k = 0;
		while (arg_val[i][k])
		{
			if (arg_val[i][k] != '-' && \
				(arg_val[i][k] < '0' || arg_val[i][k] > '9'))
				return (1);
			else if (arg_val[i][k] == '-' && \
				(arg_val[i][k + 1] < '0' || arg_val[i][k + 1] > '9'))
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

// check for non int values and duplicates.
int	check_num_array(long *arr, long arr_len)
{
	long	i;
	int		error;

	i = 0;
	error = check_for_duplicates(arr, arr_len);
	while (i < arr_len)
	{
		if (arr[i] > 2147483647 || arr[i] < -2147483648)
			error = 1;
		i++;
	}
	if (error == 1)
	{
		free(arr);
		ft_putstr_stderr("Error\n");
		return (1);
	}
	return (0);
}

// check for duplicate numbers in array
int	check_for_duplicates(long *arr, long arr_len)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < arr_len)
	{
		k = i + 1;
		while (k < arr_len)
		{
			if (arr[i] == arr[k])
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}
