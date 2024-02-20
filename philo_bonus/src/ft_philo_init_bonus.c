/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_init_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:22:40 by albartol          #+#    #+#             */
/*   Updated: 2024/02/20 01:24:49 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

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

int	ft_philo_init(t_philo *philo, int argc, char **argv)
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
	philo->num_eaten = 0;
	philo->dead = 0;
	philo->eating = 0;
	philo->num_eaten = 0;
	return (EXIT_SUCCESS);
}
