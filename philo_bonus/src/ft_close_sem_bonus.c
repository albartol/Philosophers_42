/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_sem_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:08:17 by albartol          #+#    #+#             */
/*   Updated: 2024/02/22 17:08:25 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	ft_close_sem(t_philo *philo, int num_to_close)
{
	if (num_to_close >= 1)
		sem_close(philo->sem_forks);
	if (num_to_close >= 2)
		sem_close(philo->sem_deaths);
	if (num_to_close >= 3)
		sem_close(philo->sem_printf);
	if (num_to_close >= 4)
		sem_close(philo->sem_pairs);
	if (num_to_close >= 5)
		sem_close(philo->sem_num_eat);
}

/* void	ft_close_sem(t_philo *philo, int num_to_close)
{
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
	if (num_to_close >= 4)
	{
		if (sem_close(philo->sem_pairs) == -1)
			ft_error("Error sem_close(SEM_PAIR)\n");
	}
	if (philo->num_to_eat > 0 && num_to_close >= 5)
	{
		if (sem_close(philo->sem_num_eat) == -1)
			ft_error("Error sem_close(SEM_EAT)\n");
	}
}
 */