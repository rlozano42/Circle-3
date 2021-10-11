/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:15:07 by rlozano           #+#    #+#             */
/*   Updated: 2021/09/30 14:15:08 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef enum e_bool
{
	false,
	true
}		t_bool;

typedef enum philo_status
{
	take_fork,
	eating,
	sleeping,
	thinking
}			t_philo_status;

typedef struct s_table
{
	int			t_die;
	int			t_eat;
	int			t_sleep;
	int			n_eat;
	int			n_philos;
	long		t_start;
}				t_table;

pthread_mutex_t		*g_t_forks;
pthread_mutex_t		g_print_mutex;
t_table				g_rules;
t_bool				g_end_simulation;
long				*g_time_manager;
int					*g_n_eaten;

int					ft_atoi(const char *str);
int					error_arg(int argc, char **argv);
void				assign_table_rules(char **argv, int argc);
long				millisec_current_time(void);
void				*philo_cicle_init(void *id);
void				msleep(int miliseconds);
void				print_status(int philo_id, t_philo_status status);
t_bool				init_table_values(pthread_t **p_thread, int **philo_id);
t_bool				all_eaten(void);

#endif
