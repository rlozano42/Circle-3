/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:26:32 by rlozano           #+#    #+#             */
/*   Updated: 2021/09/30 14:20:44 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	forks_assign(int philo_id, pthread_mutex_t *lr_forks[2])
{
	if (philo_id == 0)
	{
		lr_forks[0] = &g_t_forks[g_rules.n_philos - 1];
		lr_forks[1] = &g_t_forks[0];
	}
	else
	{
		lr_forks[0] = &g_t_forks[philo_id - 1];
		lr_forks[1] = &g_t_forks[philo_id];
	}
}

void	eat(int philo_id, pthread_mutex_t *lr_forks[2])
{
	pthread_mutex_lock(lr_forks[0]);
	print_status(philo_id + 1, take_fork);
	pthread_mutex_lock(lr_forks[1]);
	print_status(philo_id + 1, take_fork);
	g_time_manager[philo_id] = millisec_current_time();
	print_status(philo_id + 1, eating);
	msleep(g_rules.t_eat);
	g_n_eaten[philo_id]++;
}

void	drop_sleep(int philo_id, pthread_mutex_t *lr_forks[2])
{
	print_status(philo_id + 1, sleeping);
	pthread_mutex_unlock(lr_forks[0]);
	pthread_mutex_unlock(lr_forks[1]);
	msleep(g_rules.t_sleep);
}

void	*philo_cicle_init(void *id)
{
	const int		philo_id = *(int *)id;
	pthread_mutex_t	*lr_forks[2];

	g_time_manager[philo_id] = millisec_current_time();
	if (g_rules.n_philos == 1)
	{
		printf("%ld Philosopher %d has taken a fork\n",
			g_time_manager[philo_id] - g_rules.t_start, philo_id + 1);
		return (NULL);
	}
	forks_assign(philo_id, lr_forks);
	while (true)
	{
		eat(philo_id, lr_forks);
		drop_sleep(philo_id, lr_forks);
		print_status(philo_id + 1, thinking);
		if (g_end_simulation)
			return (NULL);
	}
	return (NULL);
}
