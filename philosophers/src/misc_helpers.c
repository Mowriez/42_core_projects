/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:48:27 by mtrautne          #+#    #+#             */
/*   Updated: 2023/04/04 16:46:16 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// recoded atoi-fct that can check for input>INT_MAX
int	philo_atoi(char *av)
{
	long	i;
	long	sign;
	long	usig_ret;

	i = 0;
	sign = 1;
	usig_ret = 0;
	while (av[i] && (av[i] == ' ' || av[i] == '\t' || av[i] == '\n'
			|| av[i] == '\r' || av[i] == '\v' || av[i] == '\f'))
		i++;
	if (av[i] == '-')
		sign = -1;
	if (av[i] == '-' || av[i] == '+')
		i++;
	while (av[i])
	{
		if (av[i] >= '0' && av[i] <= '9')
			usig_ret = (usig_ret * 10) + av[i] - '0';
		else
			return (usig_ret * sign);
		if (usig_ret * sign > INT_MAX)
			return (INT_MAX);
		i++;
	}
	return (usig_ret * sign);
}

// frees already created philosophers and table, in case that a later philo
// doesn't init. Also destroys mutexes.
void	free_retrace_ph(t_philo **philos, int i, t_table *table, \
	pthread_t *tk)
{
	int	j;

	pthread_join(*tk, NULL);
	while (i > -1)
	{
		free(philos[i]);
		i--;
	}
	free(philos);
	j = 0;
	while (j < table->nbr_philos)
	{
		pthread_mutex_destroy(table->forks[j]);
		free(philos[i]->thread);
		free(table->forks[j]);
		j++;
	}
	free(table->forks);
	destroy_table_mutexes(table);
	free(table);
}

// frees already created philosophers and table, in case that a later thread
// doesn't init. Also destroys mutexes.
void	free_retrace_thr(t_philo **philos, int i, t_table *table, \
	pthread_t *tk)
{
	int	j;

	pthread_join(*tk, NULL);
	while (i > -1)
	{
		pthread_join(*philos[i]->thread, NULL);
		pthread_mutex_destroy(&philos[i]->philo_ts_mtx);
		free(philos[i]->thread);
		free(philos[i]);
		i--;
	}
	free(philos);
	j = 0;
	while (j < table->nbr_philos)
	{
		pthread_mutex_destroy(table->forks[j]);
		free(table->forks[j]);
		j++;
	}
	free(table->forks);
	destroy_table_mutexes(table);
	free(table);
}

void	free_all(t_philo **philos, t_table *table, pthread_t *tk)
{
	int	i;
	int	j;

	i = 0;
	while (i < table->nbr_philos)
	{
		pthread_mutex_destroy(&philos[i]->philo_ts_mtx);
		free(philos[i]->thread);
		free(philos[i]);
		i++;
	}
	free(philos);
	j = 0;
	while (j < table->nbr_philos)
	{
		pthread_mutex_destroy(table->forks[j]);
		free(table->forks[j]);
		j++;
	}
	free(table->forks);
	destroy_table_mutexes(table);
	free(table);
	free(tk);
}

void	destroy_table_mutexes(t_table *table)
{
	pthread_mutex_destroy(&table->ts_mtx);
	pthread_mutex_destroy(&table->start_mtx);
	pthread_mutex_destroy(&table->stop_mtx);
	pthread_mutex_destroy(&table->seated_mtx);
	pthread_mutex_destroy(&table->meals_mtx);
	pthread_mutex_destroy(&table->msg_mtx);
}
