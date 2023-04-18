/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timekeeper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:46:10 by mtrautne          #+#    #+#             */
/*   Updated: 2023/04/04 20:20:53 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// tk fct that starts the execution and checks for dead philos.
void	*rt_timekeeper(void *void_table)
{
	t_table	*table;
	long	ts_start;
	int		j;

	table = (t_table *)void_table;
	pthread_mutex_lock(&table->start_mtx);
	while (!all_seated(table))
		usleep(100);
		ts_start = get_ts_absolute();
	pthread_mutex_lock(&table->ts_mtx);
	set_ts_start(table->philos, ts_start);
	pthread_mutex_unlock(&table->ts_mtx);
	pthread_mutex_unlock(&table->start_mtx);
	j = 0;
	while (1)
	{
		if (tk_check_philos(table))
			return (NULL);
		else
			usleep(4000);
	}
	return (NULL);
}

// subfunction that checks for dead philos.
int	tk_check_philos(t_table *table)
{
	int	j;

	j = -1;
	while (++j < table->nbr_philos)
	{
		pthread_mutex_lock(&table->stop_mtx);
		if (table->sig_stop == 2)
		{
			pthread_mutex_unlock(&table->stop_mtx);
			return (2);
		}
		pthread_mutex_unlock(&table->stop_mtx);
		pthread_mutex_lock(&table->philos[j]->philo_ts_mtx);
		if (get_ts_rel(table->philos[j]) >= table->philos[j]->ts_dead)
		{
			pthread_mutex_lock(&table->stop_mtx);
			table->sig_stop = 1;
			pthread_mutex_unlock(&table->stop_mtx);
			death_msg(table->philos[j]);
			pthread_mutex_unlock(&table->philos[j]->philo_ts_mtx);
			return (1);
		}
		pthread_mutex_unlock(&table->philos[j]->philo_ts_mtx);
	}
	return (0);
}

// subfct that sets the starting timestamp in the philos to the global 0.
void	set_ts_start(t_philo **philos, long ts_start)
{
	int	i;
	int	nbr_philos;

	i = 0;
	nbr_philos = philos[i]->table->nbr_philos;
	while (i < nbr_philos)
	{
		philos[i]->ts_start = ts_start;
		i++;
	}	
}

// subfunction that checks if all philo-threads are created.
int	all_seated(t_table *table)
{
	pthread_mutex_lock(&table->seated_mtx);
	if (table->sig_seated == table->nbr_philos)
	{
		pthread_mutex_unlock(&table->seated_mtx);
		return (1);
	}
	pthread_mutex_unlock(&table->seated_mtx);
	return (0);
}

// prints message for dead philo.
void	death_msg(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->msg_mtx);
	printf("%ld %i died\n", get_ts_rel(philo), philo->id);
	pthread_mutex_unlock(&philo->table->msg_mtx);
}
