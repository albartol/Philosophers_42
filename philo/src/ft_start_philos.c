/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:57:19 by albartol          #+#    #+#             */
/*   Updated: 2024/02/17 16:40:54 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* static int	ft_start_forks(t_philo *philo)
{
	int	i;

	i = 0;
	philo->forks = ft_calloc(sizeof(pthread_mutex_t), philo->num_phi + 1);
	if (!philo->forks)
		return (EXIT_FAILURE);
	while (i < philo->num_phi)
	{
		pthread_mutex_init(&philo->forks[i], NULL);
		i++;
	}
	philo->philos[0].left_fork = &philo->forks[philo->num_phi - 1];
	philo->philos[0].fork = &philo->forks[0];
	i = 0;
	while (++i < philo->num_phi)
	{
		philo->philos[i].left_fork = &philo->forks[i - 1];
		philo->philos[i].fork = &philo->forks[i];
	}
	return (EXIT_SUCCESS);
}

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
		philo->philos[i].num_eaten = 0;
		philo->philos[i].philo = philo;
		pthread_mutex_init(&philo->philos[i].access_lock, NULL);
		i++;
	}
	if (ft_start_forks(philo))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
} */

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
		philo->philos[i].eating = 0;
		philo->philos[i].num_eaten = 0;
		philo->philos[i].philo = philo;
		pthread_mutex_init(&philo->philos[i].access_lock, NULL);
		pthread_mutex_init(&philo->philos[i].fork, NULL);
		i++;
	}
	philo->philos[0].left_fork = &philo->philos[philo->num_phi - 1].fork;
	i = 0;
	while (++i < philo->num_phi)
		philo->philos[i].left_fork = &philo->philos[i - 1].fork;
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
