/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:17:16 by albartol          #+#    #+#             */
/*   Updated: 2024/02/15 15:39:20 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_usleep(unsigned int time_in_us)
{
	long long	now;
	long long	target;

	now = ft_get_time_us();
	if (now == -1)
		return (EXIT_FAILURE);
	target = now + time_in_us;
	while (now < target)
	{
		now = ft_get_time_us();
		if (now == -1)
			return (EXIT_FAILURE);
		usleep(time_in_us / 10);
	}
	return (EXIT_SUCCESS);
}

int	ft_msleep(unsigned int time_in_ms)
{
	long long	now;
	long long	target;

	now = ft_get_time_ms();
	if (now == -1)
		return (EXIT_FAILURE);
	target = now + time_in_ms;
	while (now < target)
	{
		now = ft_get_time_ms();
		if (now == -1)
			return (EXIT_FAILURE);
		usleep(time_in_ms);
	}
	return (EXIT_SUCCESS);
}
