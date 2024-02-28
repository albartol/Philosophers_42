/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:17:16 by albartol          #+#    #+#             */
/*   Updated: 2024/02/28 13:14:50 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	ft_usleep(unsigned int time_in_us)
{
	long long	now;
	long long	target;

	now = ft_get_time_us();
	if (now == -1)
		return (EXIT_FAILURE);
	target = now + time_in_us;
	usleep(time_in_us / 2);
	while (now < target)
	{
		now = ft_get_time_us();
		if (now == -1)
			return (EXIT_FAILURE);
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
	usleep(time_in_ms * 100);
	while (now < target)
	{
		usleep(time_in_ms);
		now = ft_get_time_ms();
		if (now == -1)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}