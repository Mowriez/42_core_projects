/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:25:57 by mtrautne          #+#    #+#             */
/*   Updated: 2023/04/04 20:14:16 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine_philos(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	pthread_mutex_lock(&philo->table->seated_mtx);
	philo->table->sig_seated++;
	pthread_mutex_unlock(&philo->table->seated_mtx);
	pthread_mutex_lock(&philo->table->start_mtx);
	pthread_mutex_unlock(&philo->table->start_mtx);
	if (philo->table->nbr_philos == 1)
		subroutine_one_philo(philo);
	else
		subroutine_multi_philos(philo);
	return (NULL);
}

void	subroutine_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->table->forks[philo->fork_r]);
	if (fork_msg_1(philo))
		return ;
	while (get_ts_rel(philo) < philo->ts_dead)
		usleep(1000);
	return ;
}

void	subroutine_multi_philos(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		think_msg(philo);
		if (philo->table->nbr_philos < 50)
			usleep(philo->table->nbr_philos * 20);
		else
			usleep(philo->table->nbr_philos * 10);
	}
	while (1)
	{
		if (eat(philo))
			return ;
		if (set_counter_meals(philo))
			return ;
		if (sleep_ph(philo))
			return ;
		if (think_msg(philo))
			return ;
	}
	return ;
}

int	eat(t_philo *philo)
{
	long	ts_stop_eating;

	if (pickup_forks(philo))
		return (1);
	philo->ts_lst_meal = get_ts_rel(philo);
	pthread_mutex_lock(&philo->philo_ts_mtx);
	philo->ts_dead = philo->ts_lst_meal + philo->t_die;
	pthread_mutex_unlock(&philo->philo_ts_mtx);
	if (eat_msg(philo))
		return (1);
	ts_stop_eating = philo->ts_lst_meal + philo->table->t_eat;
	usleep(philo->table->t_sleep * 0.95);
	while (get_ts_rel(philo) <= ts_stop_eating)
		usleep(200);
	pthread_mutex_unlock(philo->table->forks[philo->fork_r]);
	pthread_mutex_unlock(philo->table->forks[philo->fork_l]);
	if (self_check_philos(philo))
		return (1);
	return (0);
}

int	sleep_ph(t_philo *philo)
{
	long	ts_sleep;

	ts_sleep = philo->ts_lst_meal + \
		philo->table->t_eat + philo->table->t_sleep;
	if (sleep_msg(philo))
		return (1);
	usleep(philo->table->t_sleep * 0.95);
	while (get_ts_rel(philo) < ts_sleep)
		usleep(200);
	if (self_check_philos(philo))
		return (1);
	return (0);
}
