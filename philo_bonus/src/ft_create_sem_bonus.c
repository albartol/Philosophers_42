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

static int	ft_clean_error(t_philo *philo, int num_to_clean, char *str)
{
	ft_close_sem(philo, num_to_clean);
	ft_unlink_sem();
	return (ft_error(str));
}

int	ft_create_sem(t_philo *philo)
{
	philo->sem_forks = sem_open(SEM_FORK, O_CREAT, SEM_PER, philo->num_phi);
	if (SEM_FAILED == philo->sem_forks)
		return (ft_error("Error create_sem(SEM_FORK)\n"));
	philo->sem_deaths = sem_open(SEM_DEAD, O_CREAT, SEM_PER, 0);
	if (SEM_FAILED == philo->sem_deaths)
		return (ft_clean_error(philo, 1, "Error create_sem(SEM_DEAD)\n"));
	philo->sem_printf = sem_open(SEM_PRINT, O_CREAT, SEM_PER, 1);
	if (SEM_FAILED == philo->sem_printf)
		return (ft_clean_error(philo, 2, "Error create_sem(SEM_PRINT)\n"));
	philo->sem_pairs = sem_open(SEM_PAIR, O_CREAT, SEM_PER, philo->num_phi / 2);
	if (SEM_FAILED == philo->sem_pairs)
		return (ft_clean_error(philo, 3, "Error create_sem(SEM_PAIR)\n"));
	philo->sem_num_eat = sem_open(SEM_EAT, O_CREAT, SEM_PER, 0);
	if (SEM_FAILED == philo->sem_num_eat)
		return (ft_clean_error(philo, 4, "Error create_sem(SEM_EAT)\n"));
	return (EXIT_SUCCESS);
}

/* int	ft_create_sem(t_philo *philo)
{
	philo->sem_forks = sem_open(SEM_FORK, O_CREAT, SEM_PER, philo->num_phi);
	if (SEM_FAILED == philo->sem_forks)
		return (ft_error("Error create_sem(SEM_FORK)\n"));
	philo->sem_deaths = sem_open(SEM_DEAD, O_CREAT, SEM_PER, 0);
	if (SEM_FAILED == philo->sem_deaths)
		return (ft_clean_error(philo, 1, "Error create_sem(SEM_DEAD)\n"));
	philo->sem_printf = sem_open(SEM_PRINT, O_CREAT, SEM_PER, 1);
	if (SEM_FAILED == philo->sem_deaths)
		return (ft_clean_error(philo, 2, "Error create_sem(SEM_PRINT)\n"));
	if (philo->num_to_eat == -1)
		return (ft_close_sem(philo, 3));
	philo->sem_num_eat = sem_open(SEM_EAT, O_CREAT, SEM_PER, philo->num_to_eat);
	if (SEM_FAILED == philo->sem_num_eat)
		return (ft_clean_error(philo, 3, "Error create_sem(SEM_EAT)\n"));
	return (ft_close_sem(philo, 4));
} */
