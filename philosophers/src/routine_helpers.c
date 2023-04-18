/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:17:15 by mtrautne          #+#    #+#             */
/*   Updated: 2023/04/04 20:00:26 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// subroutine for philo-routines to correctly pick up forks.
int	pickup_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->table->forks[philo->fork_r]);
	if (fork_msg_1(philo))
	{
		pthread_mutex_unlock(philo->table->forks[philo->fork_r]);
		return (1);
	}
	pthread_mutex_lock(philo->table->forks[philo->fork_l]);
	if (fork_msg_2(philo))
	{
		pthread_mutex_unlock(philo->table->forks[philo->fork_r]);
		pthread_mutex_unlock(philo->table->forks[philo->fork_l]);
		return (2);
	}
	return (0);
}

// manipulates the individual and global counters for meals eaten.
int	set_counter_meals(t_philo *philo)
{
	if (philo->meals_to_eat > 1)
		philo->meals_to_eat--;
	else if (philo->meals_to_eat == 1)
	{
		philo->meals_to_eat = -1;
		pthread_mutex_lock(&philo->table->meals_mtx);
		philo->table->sig_meals++;
		if (philo->table->sig_meals == philo->table->nbr_philos)
		{
			pthread_mutex_lock(&philo->table->stop_mtx);
			philo->table->sig_stop = 2;
			pthread_mutex_unlock(&philo->table->stop_mtx);
			pthread_mutex_unlock(&philo->table->meals_mtx);
			return (1);
		}
		pthread_mutex_unlock(&philo->table->meals_mtx);
	}
	return (0);
}

// checks in the philo-routine, if all philos ate all their meals or one died.
int	self_check_philos(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->stop_mtx);
	if (philo->table->sig_stop)
	{
		pthread_mutex_unlock(&philo->table->stop_mtx);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->stop_mtx);
	return (0);
}

// set absolute timestamp (rel_time = 0) after last philosopher is created.
long	get_ts_absolute(void)
{
	struct timeval	cur_time;
	long			ts_msec;

	gettimeofday(&cur_time, NULL);
	ts_msec = (cur_time.tv_sec * 1000) + (cur_time.tv_usec / 1000);
	return (ts_msec);
}

// get the elapsed time between ts_start and current time.
long	get_ts_rel(t_philo *philo)
{
	struct timeval	cur_time;
	long			ts_rel_msec;

	gettimeofday(&cur_time, NULL);
	ts_rel_msec = (cur_time.tv_sec * 1000) + (cur_time.tv_usec / 1000) - \
		philo->ts_start;
	return (ts_rel_msec);
}
