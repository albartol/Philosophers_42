/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:57:30 by albartol          #+#    #+#             */
/*   Updated: 2024/02/14 17:13:44 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_check_values(t_philo *philo)
{
	if (philo->num_phi < 1)
		return (EXIT_FAILURE);
	if (philo->tt_die < 1)
		return (EXIT_FAILURE);
	if (philo->tt_eat < 1)
		return (EXIT_FAILURE);
	if (philo->tt_sleep < 1)
		return (EXIT_FAILURE);
	if (philo->num_to_eat < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_argv_init(t_philo *philo, int argc, char **argv)
{
	int	i;
	int	n;

	i = 1;
	while (i < argc)
	{
		n = 0;
		while (argv[i][n])
			n++;
		if (n > 9)
			return (EXIT_FAILURE);
		i++;
	}
	philo->num_phi = ft_atoi(argv[1]);
	philo->tt_die = ft_atoi(argv[2]);
	philo->tt_eat = ft_atoi(argv[3]);
	philo->tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->num_to_eat = ft_atoi(argv[5]);
	else
		philo->num_to_eat = 0;
	if (ft_check_values(philo))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_philo_init(t_philo *philo, int argc, char **argv)
{
	if (ft_argv_init(philo, argc, argv))
		return (EXIT_FAILURE);
	philo->start = ft_get_time_ms();
	if (philo->start == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
