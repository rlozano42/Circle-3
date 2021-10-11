/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:26:25 by rlozano           #+#    #+#             */
/*   Updated: 2021/09/30 12:53:28 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_bool	init_table_values(pthread_t **p_thread, int **philo_id)
{
	int	aux;

	aux = 0;
	g_end_simulation = false;
	*p_thread = (pthread_t *)malloc(sizeof (pthread_t) * g_rules.n_philos);
	g_t_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* g_rules.n_philos);
	*philo_id = (int *)malloc(sizeof(int) * g_rules.n_philos);
	g_time_manager = (long *)malloc(sizeof(long) * g_rules.n_philos);
	g_n_eaten = (int *)malloc(sizeof(int) * g_rules.n_philos);
	if (!*p_thread || !g_t_forks || !*philo_id || !g_n_eaten || !g_time_manager)
		return (false);
	memset(g_n_eaten, 0, sizeof(int) * g_rules.n_philos);
	if (pthread_mutex_init(&g_print_mutex, NULL))
		return (false);
	while (aux < g_rules.n_philos)
	{
		g_time_manager[aux] = millisec_current_time();
		if (pthread_mutex_init(&g_t_forks[aux++], NULL))
			return (false);
	}
	g_rules.t_start = millisec_current_time();
	printf("The simulation has started\n");
	return (true);
}

void	assign_table_rules(char **argv, int argc)
{
	g_rules.n_eat = -1;
	g_rules.n_philos = ft_atoi(argv[1]);
	g_rules.t_die = ft_atoi(argv[2]);
	g_rules.t_eat = ft_atoi(argv[3]);
	g_rules.t_sleep = ft_atoi(argv[4]);
	if (argc > 5)
		g_rules.n_eat = ft_atoi(argv[5]);
}
