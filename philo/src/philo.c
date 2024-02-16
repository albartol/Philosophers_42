/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:56:17 by albartol          #+#    #+#             */
/*   Updated: 2024/02/16 15:57:04 by albartol         ###   ########.fr       */
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
	if (ft_start_pthreads(&philo))
		return (EXIT_FAILURE);
	ft_clean(&philo);
	return (EXIT_SUCCESS);
}
