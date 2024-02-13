/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:17:16 by albartol          #+#    #+#             */
/*   Updated: 2024/02/13 17:03:39 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_usleep(unsigned int time)
{
	struct timeval	time_now;
	unsigned long	now;
	unsigned long	target;

	if (gettimeofday(&time_now, NULL) == -1)
		return (-1);
	now = time_now.tv_sec * 1000000 + time_now.tv_usec;
	target = now + time;
	while (now < target)
	{
		if (gettimeofday(&time_now, NULL) == -1)
			return (-1);
		now = time_now.tv_sec * 1000000 + time_now.tv_usec;
	}
	return (0);
}
