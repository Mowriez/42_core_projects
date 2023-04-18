/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:07:19 by mtrautne          #+#    #+#             */
/*   Updated: 2023/04/04 16:39:20 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// initialize the table, meaning all the basic rules for the project
t_table	*init_table_struct(int ac, char **av)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	subfct_init_table(table, ac, av);
	if (check_int_values(table))
		return (NULL);
	if (init_signal_mutexes(table))
	{
		free(table);
		return (NULL);
	}
	table->forks = init_forks(table->nbr_philos);
	if (!table->forks)
	{
		free (table);
		destroy_table_mutexes(table);
		return (NULL);
	}
	return (table);
}

// intitialize the struct for philos
t_philo	**init_philos(t_table *table, pthread_t *tk)
{
	int		i;
	t_philo	**philos;

	philos = malloc(table->nbr_philos * (sizeof(t_philo *)));
	if (!philos)
		return (NULL);
	i = 0;
	while (i < table->nbr_philos)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
		{
			free_retrace_ph(philos, i, table, tk);
			return (NULL);
		}
		subfct_init_philos(philos, i, table);
		philos[i]->thread = init_philo_thread(philos[i]);
		if (!philos[i]->thread)
		{
			free_retrace_thr(philos, i, table, tk);
			return (NULL);
		}
		i++;
	}
	return (philos);
}

// intitialize the fork mutexes
pthread_mutex_t	**init_forks(int nbr_forks)
{
	pthread_mutex_t	**forks;
	int				i;

	forks = malloc(nbr_forks * sizeof(pthread_mutex_t *));
	if (!forks)
		return (NULL);
	i = 0;
	while (i < nbr_forks)
	{
		forks[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(forks[i], NULL);
		i++;
	}
	return (forks);
}

// initialises individual philosopher threads
pthread_t	*init_philo_thread(t_philo *philo)
{
	pthread_t	*thread;

	thread = (pthread_t *)malloc(sizeof(pthread_t));
	if (!thread)
		return (NULL);
	if (pthread_create(thread, NULL, &routine_philos, philo) != 0)
		return (NULL);
	return (thread);
}

// initialises the timekeeper thread that checks for dead philos
pthread_t	*init_timekeeper(t_table *table)
{
	pthread_t	*timekeeper;

	timekeeper = (pthread_t *)malloc(sizeof(pthread_t));
	if (!timekeeper)
		return (NULL);
	if (pthread_create(timekeeper, NULL, &rt_timekeeper, table) != 0)
	{
		free (timekeeper);
		return (NULL);
	}
	return (timekeeper);
}
