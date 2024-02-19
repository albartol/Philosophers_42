/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:57:30 by albartol          #+#    #+#             */
/*   Updated: 2024/02/17 15:03:23 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_check_values(t_philo *philo)
{
	if (philo->num_phi == 0 || philo->tt_die == 0)
		return (EXIT_FAILURE);
	if (philo->tt_sleep == 0 || philo->tt_eat == 0)
		return (EXIT_FAILURE);
	if (philo->num_to_eat == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_check_argv(int argc, char **argv)
{
	int	i;
	int	n;

	i = 1;
	while (i < argc)
	{
		n = 0;
		while (argv[i][n])
		{
			if (argv[i][n] < 48 || argv[i][n] > 57)
				return (ft_error("Arguments can only be positive numbers\n"));
			n++;
		}
		if (n > 9)
			return (ft_error("Arguments can't be longer than 9 numbers\n"));
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	ft_argv_init(t_philo *philo, int argc, char **argv)
{
	if (ft_check_argv(argc, argv))
		return (EXIT_FAILURE);
	philo->num_phi = ft_atoi(argv[1]);
	philo->tt_die = ft_atoi(argv[2]);
	philo->tt_eat = ft_atoi(argv[3]);
	philo->tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->num_to_eat = ft_atoi(argv[5]);
	else
		philo->num_to_eat = -1;
	if (ft_check_values(philo))
		return (ft_error("Arguments can't be 0\n"));
	return (EXIT_SUCCESS);
}

static int	ft_start_philos(t_philo *philo)
{
	int	i;

	i = 0;
	philo->philos = (t_phi *)ft_calloc(philo->num_phi, sizeof(t_phi));
	if (!philo->philos)
		return (ft_error("Failed to alloc memory in ft_start_philos\n"));
	while (i < philo->num_phi)
	{
		philo->philos[i].id = i + 1;
		philo->philos[i].eating = 0;
		philo->philos[i].num_eaten = 0;
		philo->philos[i].philo = philo;
		if (pthread_mutex_init(&philo->philos[i].mem_lock, NULL))
			return (ft_error("Failed to init mutex\n"));
		if (pthread_mutex_init(&philo->philos[i].fork, NULL))
			return (ft_error("Failed to init mutex\n"));
		i++;
	}
	philo->philos[0].left_fork = &philo->philos[philo->num_phi - 1].fork;
	i = 0;
	while (++i < philo->num_phi)
		philo->philos[i].left_fork = &philo->philos[i - 1].fork;
	return (EXIT_SUCCESS);
}

int	ft_philo_init(t_philo *philo, int argc, char **argv)
{
	if (ft_argv_init(philo, argc, argv))
		return (EXIT_FAILURE);
	philo->num_eaten = 0;
	philo->num_dead = 0;
	philo->philos = 0;
	if (pthread_mutex_init(&philo->mem_lock, NULL))
		return (ft_error("Failed to init mutex\n"));
	if (pthread_mutex_init(&philo->print_lock, NULL))
	{
		pthread_mutex_destroy(&philo->mem_lock);
		return (ft_error("Failed to init mutex\n"));
	}
	if (ft_start_philos(philo))
	{
		ft_clean(philo);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
