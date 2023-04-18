/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:11:02 by mtrautne          #+#    #+#             */
/*   Updated: 2023/04/04 17:05:17 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// initialise all stack-allocated elements of table
void	subfct_init_table(t_table *table, int ac, char **av)
{
	table->nbr_philos = philo_atoi(av[1]);
	table->t_die = philo_atoi(av[2]);
	table->t_eat = philo_atoi(av[3]);
	table->t_sleep = philo_atoi(av[4]);
	table->nbr_meals = -1;
	if (ac == 6)
		table->nbr_meals = philo_atoi(av[5]);
	table->dead_id = 0;
	table->sig_seated = 0;
	table->sig_stop = 0;
	table->sig_meals = 0;
}

// initialise the mutexes for event signals
int	init_signal_mutexes(t_table *table)
{
	if (pthread_mutex_init(&table->stop_mtx, NULL))
		return (1);
	if (pthread_mutex_init(&table->meals_mtx, NULL))
	{
		pthread_mutex_destroy(&table->stop_mtx);
		return (2);
	}
	if (pthread_mutex_init(&table->msg_mtx, NULL))
	{
		pthread_mutex_destroy(&table->stop_mtx);
		pthread_mutex_destroy(&table->meals_mtx);
		return (3);
	}	
	if (pthread_mutex_init(&table->ts_mtx, NULL))
	{
		pthread_mutex_destroy(&table->stop_mtx);
		pthread_mutex_destroy(&table->meals_mtx);
		pthread_mutex_destroy(&table->msg_mtx);
		return (4);
	}
	if (subfct_init_signal_mutexes(table))
		return (5);
	return (0);
}

// clunky subfunction to initialise all the mutexes
int	subfct_init_signal_mutexes(t_table *table)
{
	if (pthread_mutex_init(&table->start_mtx, NULL))
	{
		pthread_mutex_destroy(&table->stop_mtx);
		pthread_mutex_destroy(&table->meals_mtx);
		pthread_mutex_destroy(&table->msg_mtx);
		pthread_mutex_destroy(&table->ts_mtx);
		return (5);
	}
	if (pthread_mutex_init(&table->seated_mtx, NULL))
	{
		pthread_mutex_destroy(&table->stop_mtx);
		pthread_mutex_destroy(&table->meals_mtx);
		pthread_mutex_destroy(&table->msg_mtx);
		pthread_mutex_destroy(&table->ts_mtx);
		pthread_mutex_destroy(&table->start_mtx);
		return (6);
	}
	return (0);
}

// initialise all stack-allocated elements of philos
void	subfct_init_philos(t_philo **philos, int i, t_table *table)
{
	philos[i]->id = i + 1;
	philos[i]->meals_to_eat = table->nbr_meals;
	philos[i]->fork_l = i;
	philos[i]->fork_r = (i + 1) % table->nbr_philos;
	philos[i]->table = table;
	philos[i]->ts_lst_meal = 0;
	philos[i]->t_die = table->t_die;
	philos[i]->ts_start = -1;
	philos[i]->ts_dead = table->t_die;
	philos[i]->table->philos = philos;
	pthread_mutex_init(&philos[i]->philo_ts_mtx, NULL);
}
