/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_sem_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:56:17 by albartol          #+#    #+#             */
/*   Updated: 2024/02/20 18:17:04 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	ft_create_sem(t_philo *philo)
{
	philo->sem_forks = sem_open(SEM_FORK, O_CREAT, SEM_PER, philo->num_phi);
	if (SEM_FAILED == philo->sem_forks)
		return (ft_error("Error create_sem(SEM_FORK)\n"));
	philo->sem_deaths = sem_open(SEM_DEAD, O_CREAT, SEM_PER, 0);
	if (SEM_FAILED == philo->sem_deaths)
	{
		ft_close_sem(philo, 1);
		ft_unlink_sem(philo, 1);
		return (ft_error("Error create_sem(SEM_DEAD)\n"));
	}
	philo->sem_printf = sem_open(SEM_PRINT, O_CREAT, SEM_PER, 1);
	if (SEM_FAILED == philo->sem_deaths)
	{
		ft_close_sem(philo, 2);
		ft_unlink_sem(philo, 2);
		return (ft_error("Error create_sem(SEM_PRINT)\n"));
	}
	if (philo->num_to_eat == -1)
	{
		if (ft_close_sem(philo, 3))
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	philo->sem_num_eat = sem_open(SEM_EAT, O_CREAT, SEM_PER, philo->num_to_eat);
	if (SEM_FAILED == philo->sem_num_eat)
	{
		ft_close_sem(philo, 3);
		ft_unlink_sem(philo, 3);
		return (ft_error("Error create_sem(SEM_EAT)\n"));
	}
	if (ft_close_sem(philo, 4))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
