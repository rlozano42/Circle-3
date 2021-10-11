/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:15:13 by rlozano           #+#    #+#             */
/*   Updated: 2021/09/30 14:16:15 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	free_all(pthread_t *p_thread, int *philo_id)
{
	int	aux;

	aux = 0;
	while (aux < g_rules.n_philos)
	{
		pthread_join(p_thread[aux++], NULL);
	}
	aux = 0;
	while (aux < g_rules.n_philos)
	{
		pthread_mutex_destroy(&g_t_forks[aux++]);
	}
	if (g_time_manager)
		free(g_time_manager);
	if (p_thread)
		free(p_thread);
	if (g_t_forks)
		free(g_t_forks);
	if (philo_id)
		free(philo_id);
}

int	philo_create(pthread_t *p_thread, int *philo_id)
{
	int	aux;

	aux = 0;
	while (aux < g_rules.n_philos)
	{
		philo_id[aux] = aux;
		if (pthread_create(&p_thread[aux], NULL,
				&philo_cicle_init, &philo_id[aux]))
			return (false);
		usleep(1000);
		aux++;
	}
	return (true);
}

void	simulation_manager(void)
{
	int		aux;
	long	c_time;

	while (true)
	{
		c_time = millisec_current_time();
		aux = 0;
		while (aux < g_rules.n_philos)
		{
			if (c_time - g_time_manager[aux] > g_rules.t_die)
			{
				g_end_simulation = true;
				printf("%ld %d died\n", c_time - g_rules.t_start, aux + 1);
				return ;
			}
			else if (g_rules.n_eat != -1 && all_eaten())
			{
				g_end_simulation = true;
				return ;
			}
			aux++;
		}
	}
}

int	main(int argc, char **argv)
{
	pthread_t	*p_thread;
	int			*philo_id;

	if (error_arg(argc, argv) != 0)
		return (1);
	assign_table_rules(argv, argc);
	if (init_table_values(&p_thread, &philo_id)
		&& (g_rules.n_eat != 0 && g_rules.n_philos > 0)
		&& (philo_create(p_thread, philo_id)))
	{
		simulation_manager();
	}
	free_all(p_thread, philo_id);
	return (0);
}
