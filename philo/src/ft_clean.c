/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:45:40 by albartol          #+#    #+#             */
/*   Updated: 2024/02/22 17:58:49 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_clean(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&philo->mem_lock);
	pthread_mutex_destroy(&philo->print_lock);
	if (philo->philos)
	{
		while (i < philo->num_phi)
		{
			pthread_mutex_destroy(&philo->philos[i].mem_lock);
			pthread_mutex_destroy(&philo->philos[i].fork);
			i++;
		}
		free(philo->philos);
	}
}

/* void	ft_clean(t_philo *philo)
{
	int	i;

	i = 0;
	if (pthread_mutex_destroy(&philo->mem_lock))
		ft_error("Failed to destroy mutex (philo->mem_lock)");
	if (pthread_mutex_destroy(&philo->print_lock))
		ft_error("Failed to destroy mutex (philo->print_lock)");
	if (philo->philos)
	{
		while (i < philo->num_phi)
		{
			if (pthread_mutex_destroy(&philo->philos[i].mem_lock))
				ft_error("Failed to destroy mutex (phi.mem_lock)");
			if (pthread_mutex_destroy(&philo->philos[i].fork))
				ft_error("Failed to destroy mutex (phi.fork)");
			i++;
		}
		free(philo->philos);
	}
} */