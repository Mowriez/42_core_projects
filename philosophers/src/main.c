/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:18:24 by mtrautne          #+#    #+#             */
/*   Updated: 2023/04/04 16:44:41 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_table		*table;
	t_philo		**philos;
	pthread_t	*guillaume;

	if (input_processing(ac, av))
		return (1);
	table = init_table_struct(ac, av);
	if (!table)
		return (1);
	guillaume = init_timekeeper(table);
	if (!guillaume)
		return (1);
	philos = init_philos(table, guillaume);
	if (!philos)
		return (1);
	join_threads(philos, guillaume);
	free_all(philos, table, guillaume);
	return (0);
}

void	join_threads(t_philo **philos, pthread_t *timekeeper)
{
	int	i;

	i = philos[0]->table->nbr_philos - 1;
	while (i >= 0)
	{
		if (pthread_join(*philos[i]->thread, NULL) != 0)
		{
			printf(RED"Error: Philo-thread[%i] joining not successful!\n"RES,
				(i + 1));
		}
		i--;
	}
	if (pthread_join(*timekeeper, NULL) != 0)
		printf(RED"Error: timekeeper thread joining not successful!\n"RES);
}
