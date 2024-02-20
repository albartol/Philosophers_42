/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_sem_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:36:17 by albartol          #+#    #+#             */
/*   Updated: 2024/02/20 19:17:04 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	ft_open_sem(t_philo *philo)
{
	philo->sem_forks = sem_open(SEM_FORK, 0);
	if (SEM_FAILED == philo->sem_forks)
		return (ft_error("Error sem_open(SEM_FORK)\n"));
	philo->sem_deaths = sem_open(SEM_DEAD, 0);
	if (SEM_FAILED == philo->sem_deaths)
	{
		ft_close_sem(philo, 1);
		return (ft_error("Error sem_open(SEM_DEAD)\n"));
	}
	philo->sem_printf = sem_open(SEM_PRINT, O_CREAT, SEM_PER, 1);
	if (SEM_FAILED == philo->sem_printf)
	{
		ft_close_sem(philo, 2);
		return (ft_error("Error sem_open(SEM_PRINT)\n"));
	}
	if (philo->num_to_eat == -1)
		return (EXIT_SUCCESS);
	philo->sem_num_eat = sem_open(SEM_EAT, 0);
	if (SEM_FAILED == philo->sem_num_eat)
	{
		ft_close_sem(philo, 3);
		return (ft_error("Error sem_open(SEM_EAT)\n"));
	}
	return (EXIT_SUCCESS);
}
