/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:45:40 by albartol          #+#    #+#             */
/*   Updated: 2024/02/17 16:25:38 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_clean(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->num_phi)
	{
		pthread_mutex_destroy(&philo->philos[i].access_lock);
		pthread_mutex_destroy(&philo->philos[i].fork);
		i++;
	}
	pthread_mutex_destroy(&philo->access_lock);
	pthread_mutex_destroy(&philo->write_lock);
	if (philo->philos)
		free(philo->philos);
}

/* void	ft_clean(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->num_phi)
	{
		pthread_mutex_destroy(&philo->philos[i].access_lock);
		pthread_mutex_destroy(&philo->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->access_lock);
	pthread_mutex_destroy(&philo->write_lock);
	if (philo->philos)
		free(philo->philos);
} */
