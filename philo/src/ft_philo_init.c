/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:57:30 by albartol          #+#    #+#             */
/*   Updated: 2024/02/13 18:36:40 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_check_argv(t_philo *philo)
{
	if (philo->num_phi < 0)
		return (EXIT_FAILURE);
	if (philo->tt_die < 0)
		return (EXIT_FAILURE);
	if (philo->tt_eat < 0)
		return (EXIT_FAILURE);
	if (philo->tt_sleep < 0)
		return (EXIT_FAILURE);
	if (philo->num_to_eat < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_philo_init(t_philo *philo, int argc, char **argv)
{
	philo->num_phi = ft_atoi(argv[1]);
	philo->tt_die = ft_atoi(argv[2]);
	philo->tt_eat = ft_atoi(argv[3]);
	philo->tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->num_to_eat = ft_atoi(argv[5]);
	else
		philo->num_to_eat = 0;
	if (ft_check_argv(philo))
		return (EXIT_FAILURE);
	if (gettimeofday(&philo->time, NULL) == -1)
		return (EXIT_FAILURE);
	philo->start = philo->time.tv_sec * 1000 + philo->time.tv_usec / 1000;
	return (EXIT_SUCCESS);
}
