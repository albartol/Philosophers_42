/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_sem_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:08:17 by albartol          #+#    #+#             */
/*   Updated: 2024/02/20 18:27:04 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	ft_close_sem(t_philo *philo, int num_to_close)
{
	if (num_to_close < 1 && num_to_close > 4)
		return (EXIT_SUCCESS);
	if (num_to_close >= 1)
	{
		if (sem_close(philo->sem_forks) == -1)
			ft_error("Error sem_close(SEM_FORK)\n");
	}
	if (num_to_close >= 2)
	{
		if (sem_close(philo->sem_deaths) == -1)
			ft_error("Error sem_close(SEM_DEAD)\n");
	}
	if (num_to_close >= 3)
	{
		if (sem_close(philo->sem_printf) == -1)
			ft_error("Error sem_close(SEM_PRINT)\n");
	}
	if (philo->num_to_eat == -1)
		return (EXIT_SUCCESS);
	if (num_to_close == 4)
	{
		if (sem_close(philo->sem_num_eat) == -1)
			ft_error("Error sem_close(SEM_EAT)\n");
	}
	return (EXIT_SUCCESS);
}
