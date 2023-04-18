/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:45:31 by mtrautne          #+#    #+#             */
/*   Updated: 2023/04/04 20:20:40 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// prints message after picking up a fork
int	fork_msg_1(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->msg_mtx);
	if (self_check_philos(philo))
	{
		pthread_mutex_unlock(&philo->table->msg_mtx);
		return (1);
	}
	printf("%ld %i has taken a fork\n", get_ts_rel(philo), philo->id);
	pthread_mutex_unlock(&philo->table->msg_mtx);
	return (0);
}

// prints message after picking up a second fork
int	fork_msg_2(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->msg_mtx);
	if (self_check_philos(philo))
	{
		pthread_mutex_unlock(&philo->table->msg_mtx);
		return (1);
	}
	printf("%ld %i has taken a fork\n", get_ts_rel(philo), philo->id);
	pthread_mutex_unlock(&philo->table->msg_mtx);
	return (0);
}

// prints message when eating
int	eat_msg(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->msg_mtx);
	if (self_check_philos(philo))
	{
		pthread_mutex_unlock(philo->table->forks[philo->fork_r]);
		pthread_mutex_unlock(philo->table->forks[philo->fork_l]);
		pthread_mutex_unlock(&philo->table->msg_mtx);
		return (1);
	}
	printf("%ld %i is eating\n", philo->ts_lst_meal, philo->id);
	pthread_mutex_unlock(&philo->table->msg_mtx);
	return (0);
}

// prints message when sleeping
int	sleep_msg(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->msg_mtx);
	if (self_check_philos(philo))
	{
		pthread_mutex_unlock(&philo->table->msg_mtx);
		return (1);
	}
	printf("%ld %i is sleeping\n", get_ts_rel(philo), philo->id);
	pthread_mutex_unlock(&philo->table->msg_mtx);
	return (0);
}

// prints message when thinking
int	think_msg(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->msg_mtx);
	if (self_check_philos(philo))
	{
		pthread_mutex_unlock(&philo->table->msg_mtx);
		return (1);
	}
	printf("%ld %i is thinking\n", get_ts_rel(philo), philo->id);
	pthread_mutex_unlock(&philo->table->msg_mtx);
	return (0);
}
