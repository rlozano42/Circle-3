/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_and_status_manager.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:26:52 by rlozano           #+#    #+#             */
/*   Updated: 2021/09/28 16:26:53 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	millisec_current_time(void)
{
	struct timeval	tv;
	long			ms_parse;

	gettimeofday(&tv, NULL);
	ms_parse = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return (ms_parse);
}
