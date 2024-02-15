/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:57:19 by albartol          #+#    #+#             */
/*   Updated: 2024/02/15 16:34:16 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_start_philos(t_philo *philo)
{
	int	i;

	i = 0;
	philo->philos = (t_phi *)ft_calloc(sizeof(t_phi), philo->num_phi + 1);
	if (!philo->philos)
		return (EXIT_FAILURE);
	while (i < philo->num_phi)
	{
		philo->philos[i].id = i + 1;
		philo->philos[i].dead = 0;
		philo->philos[i].eating = 0;
		philo->philos[i].sleeping = 0;
		philo->philos[i].num_eaten = 0;
		pthread_mutex_init(&philo->philos[i].lock, NULL);
		pthread_mutex_init(&philo->philos[i].fork, NULL);
		i++;
	}
	return (EXIT_SUCCESS);
}

/* int	ft_start_philos(t_philo *philo)
{
	int	i;

	i = 0;
	philo->philos = (t_phi *)ft_calloc(sizeof(t_phi), philo->num_phi + 1);
	if (!philo->philos)
		return (EXIT_FAILURE);
	while (i < philo->num_phi)
	{
		philo->philos[i].id = i + 1;
		philo->philos[i].dead = 0;
		philo->philos[i].eating = 0;
		philo->philos[i].sleeping = 0;
		philo->philos[i].num_eaten = 0;
		if (pthread_mutex_init(&philo->philos[i].lock, NULL))
            return (EXIT_FAILURE);
		if (pthread_mutex_init(&philo->philos[i].fork, NULL))
            return (EXIT_FAILURE);
		i++;
	}
    while (i--)
        printf("%d\n", philo->philos[i].id);
	return (EXIT_SUCCESS);
} */
