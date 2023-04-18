/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:54:49 by mtrautne          #+#    #+#             */
/*   Updated: 2023/04/04 12:07:11 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	input_processing(int ac, char **av)
{
	if (check_argc(ac))
		return (1);
	if (check_for_non_num(ac, av))
		return (1);
	return (0);
}

int	check_argc(int ac)
{
	if (ac < 5 || ac > 6)
	{
		printf(RED"Error: incorrect nbr of args, needs 5/6:\n "BLU"1: number_o"
			"f_philosophers\n 2: time_to_die\n 3: time_to_eat\n 4: time_to_sle"
			"ep\n 5: number_of_times_each_philosopher_must_eat (optional)\n"
			RES);
		return (1);
	}
	return (0);
}

int	check_for_non_num(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				printf(RED"Error: Non numerical or negative input.\n"
					BLU"Please check arg %i, char %i.\n"RES, i, j);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_int_values(t_table *table)
{
	if (table->t_die <= 0 || table->nbr_philos <= 0 || \
		(table->nbr_meals <= 0 && table->nbr_meals != -1))
	{
		printf(RED"Error: 0 for t_die, nbr_philos or nbr_meals will end up in"
			"undefined behaviour. Nobody wants that. Just try a proper value,"
			"please.\n"RES);
		free(table);
		return (1);
	}
	if (table->t_die == INT_MAX || table->t_sleep == INT_MAX || \
		table->t_eat == INT_MAX || table->nbr_philos == INT_MAX || \
		table->nbr_meals == INT_MAX)
	{
		printf(RED"Error: Inputs >= INT_MAX means no execution for you."
			"Please be reasonable!\n"RES);
		free(table);
		return (2);
	}
	return (0);
}
