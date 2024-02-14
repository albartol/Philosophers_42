/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:17:16 by albartol          #+#    #+#             */
/*   Updated: 2024/02/14 17:17:36 by albartol         ###   ########.fr       */
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
	}
	return (EXIT_SUCCESS);
}

int	ft_msleep(unsigned int time_in_ms)
{
	if (ft_usleep(time_in_ms * 1000))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
