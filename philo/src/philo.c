/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:56:17 by albartol          #+#    #+#             */
/*   Updated: 2024/02/13 19:34:01 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc < 5 || argc > 6)
		return (EXIT_SUCCESS);
	if (ft_philo_init(&philo, argc, argv))
		return (EXIT_FAILURE);
	ft_usleep(philo.tt_die);
	ft_print_status(&philo, 1, DEAD);
	ft_usleep(philo.tt_die);
	ft_print_status(&philo, 1, EAT);
	ft_usleep(philo.tt_die);
	ft_print_status(&philo, 1, SLEEP);
	ft_usleep(philo.tt_die);
	ft_print_status(&philo, 1, THINK);
	ft_usleep(philo.tt_die);
	ft_print_status(&philo, 1, FORK);
	return (EXIT_SUCCESS);
}
