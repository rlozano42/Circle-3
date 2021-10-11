/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:26:27 by rlozano           #+#    #+#             */
/*   Updated: 2021/09/30 12:52:35 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			neg;
	int			res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (res > 2147483647 )
		{
			printf("Error\n");
			exit(0);
		}
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * neg);
}

void	msleep(int miliseconds)
{
	const long	start = millisec_current_time();
	const long	end = start + miliseconds;
	long		current;

	current = start;
	while (!g_end_simulation && current < end)
	{
		if (end - current > 100)
			usleep(100000);
		else
			usleep((end - current) * 1000);
		current = millisec_current_time();
	}
}

t_bool	all_eaten(void)
{
	int	aux;

	aux = 0;
	while (aux < g_rules.n_philos)
	{
		if (g_n_eaten[aux] < g_rules.n_eat)
			return (false);
		aux++;
	}
	usleep(1000);
	aux = 0;
	while (g_n_eaten[aux])
	{
		printf("The philosopher %d has eaten %d times\n",
			 aux + 1, g_n_eaten[aux]);
		aux++;
	}
	printf("They  all have eaten at least %d times\n", g_rules.n_eat);
	return (true);
}

void	print_status(int philo_id, t_philo_status status)
{
	const long	c_time = millisec_current_time() - g_rules.t_start;

	if (g_end_simulation)
		return ;
	pthread_mutex_lock(&g_print_mutex);
	if (status == take_fork)
	{
		printf("%ld Philosopher %d has taken the fork\n", c_time, philo_id);
	}
	else if (status == eating)
	{
		printf("%ld Philosopher %d is eating\n", c_time, philo_id);
	}
	else if (status == thinking)
	{
		printf("%ld Philosopher %d is thinking\n", c_time, philo_id);
	}
	else if (status == sleeping)
	{
		printf("%ld Philosopher %d is sleeping\n", c_time, philo_id);
	}
	pthread_mutex_unlock(&g_print_mutex);
}
