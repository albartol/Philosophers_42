/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:56:17 by albartol          #+#    #+#             */
/*   Updated: 2024/02/20 00:57:04 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (argc < 5 || argc > 6)
		return (ft_error("There should be 4 or 5 arguments\n"));
	philo = (t_philo *)ft_calloc(1, sizeof(t_philo));
	if (!philo)
		return (ft_error("Failed to alloc memory in main\n"));
	if (ft_philo_init(philo, argc, argv))
	{
		free(philo);
		return (EXIT_FAILURE);
	}
	if (ft_start_forks(philo))
	{
		free(philo);
		return (ft_error("Error in ft_start_forks\n"));
	}
	free(philo);
	return (EXIT_SUCCESS);
}
