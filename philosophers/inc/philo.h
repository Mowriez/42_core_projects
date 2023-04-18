/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 00:59:10 by mtrautne          #+#    #+#             */
/*   Updated: 2023/04/04 20:13:43 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//SYSTEM LIBRARIES-------------------------------------------------------------

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

// COLOR_MACROS----------------------------------------------------------------

# define RED "\033[1;31m"
# define YEL "\033[0;33m"
# define BLU "\033[0;34m"
# define RES "\033[0m"

// STRUCT FOR GENERAL RULES AND SIGNAL VARIABLES-------------------------------

typedef struct s_philo	t_philo;

typedef struct s_table {
	int				nbr_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nbr_meals;

	int				dead_id;
	int				sig_seated;
	long			sig_stop;
	int				sig_meals;
	long			ts_start;
	t_philo			**philos;

	pthread_mutex_t	**forks;
	pthread_mutex_t	ts_mtx;
	pthread_mutex_t	start_mtx;
	pthread_mutex_t	seated_mtx;
	pthread_mutex_t	meals_mtx;
	pthread_mutex_t	msg_mtx;
	pthread_mutex_t	stop_mtx;

}	t_table;

//STRUCT FOR PHILOSOPHERS------------------------------------------------------

typedef struct s_philo {
	int				id;
	int				meals_to_eat;
	long			ts_start;
	int				t_die;
	int				fork_l;
	int				fork_r;
	t_table			*table;
	pthread_t		*thread;

	pthread_mutex_t	philo_ts_mtx;
	long			ts_lst_meal;
	long			ts_dead;
}	t_philo;

//FUNCTION PROTOTYPES----------------------------------------------------------

// init_helpers.c
void			subfct_init_table(t_table *table, int ac, char **av);
int				init_signal_mutexes(t_table *table);
int				subfct_init_signal_mutexes(t_table *table);
void			subfct_init_philos(t_philo **philos, int i, t_table *table);

// init.c
t_table			*init_table_struct(int ac, char **av);
t_philo			**init_philos(t_table *table, pthread_t *tk);
pthread_mutex_t	**init_forks(int nbr_forks);
pthread_t		*init_philo_thread(t_philo *philo);
pthread_t		*init_timekeeper(t_table *table);

// input_processing.c
int				input_processing(int ac, char **av);
int				check_argc(int ac);
int				check_for_non_num(int ac, char **av);
int				check_int_values(t_table *table);

// main.c
void			join_threads(t_philo **philos, pthread_t *timekeeper);

// messages.c
int				fork_msg_1(t_philo *philo);
int				fork_msg_2(t_philo *philo);
int				eat_msg(t_philo *philo);
int				sleep_msg(t_philo *philo);
int				think_msg(t_philo *philo);

// misc_helpers.c
int				philo_atoi(char *av);
void			free_retrace_ph(t_philo **philos, int i, t_table *table, \
					pthread_t *tk);
void			free_retrace_thr(t_philo **philos, int i, t_table *table, \
					pthread_t *tk);
void			free_all(t_philo **philos, t_table *table, pthread_t *tk);
void			destroy_table_mutexes(t_table *table);

//routine_helpers.c
int				pickup_forks(t_philo *philo);
int				set_counter_meals(t_philo *philo);
int				self_check_philos(t_philo *philo);
long			get_ts_absolute(void);
long			get_ts_rel(t_philo *philo);

// routines.c
void			*routine_philos(void *void_philo);
void			subroutine_one_philo(t_philo *philo);
void			subroutine_multi_philos(t_philo *philo);
int				eat(t_philo *philo);
int				sleep_ph(t_philo *philo);

// timekeeper.c
void			*rt_timekeeper(void *void_table);
int				tk_check_philos(t_table *table);
void			set_ts_start(t_philo **philos, long ts_start);
int				all_seated(t_table *table);
void			death_msg(t_philo *philo);

#endif