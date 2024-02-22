/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unlink_sem_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:06:17 by albartol          #+#    #+#             */
/*   Updated: 2024/02/22 17:08:56 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	ft_unlink_sem(void)
{
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_DEAD);
	sem_unlink(SEM_PRINT);
	// sem_unlink(SEM_PAIR);
	sem_unlink(SEM_EAT);
}

/* void	ft_unlink_sem(t_philo *philo, int num_to_unlink)
{
	if (num_to_unlink >= 1)
	{
		if (sem_unlink(SEM_FORK) == -1)
			ft_error("Error sem_unlink(SEM_FORK)\n");
	}
	if (num_to_unlink >= 2)
	{
		if (sem_unlink(SEM_DEAD) == -1)
			ft_error("Error sem_unlink(SEM_DEAD)\n");
	}
	if (num_to_unlink >= 3)
	{
		if (sem_unlink(SEM_PRINT) == -1)
			ft_error("Error sem_unlink(SEM_PRINT)\n");
	}
	if (num_to_unlink >= 4)
	{
		if (sem_unlink(SEM_PAIR) == -1)
			ft_error("Error sem_unlink(SEM_PAIR)\n");
	}
	if (philo->num_to_eat > 0 && num_to_unlink >= 5)
	{
		if (sem_unlink(SEM_EAT) == -1)
			ft_error("Error sem_unlink(SEM_EAT)\n");
	}
} */
