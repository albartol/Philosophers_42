/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:41:15 by albartol          #+#    #+#             */
/*   Updated: 2024/02/20 01:30:18 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static void	ft_take_forks(t_philo *philo)
{
	sem_wait(philo->sem_pairs);
	sem_wait(philo->sem_forks);
	if (philo->dead == 0)
		ft_print_status(philo, FORK);
	sem_wait(philo->sem_forks);
	if (philo->dead == 0)
		ft_print_status(philo, FORK);
	sem_post(philo->sem_pairs);
}

/* static void	ft_take_forks(t_philo *philo)
{
	sem_wait(philo->sem_pairs);
	if (sem_wait(philo->sem_forks) == 0)
	{
		if (philo->dead == 0)
			ft_print_status(philo, FORK);
	}
	if (sem_wait(philo->sem_forks) == 0)
	{
		if (philo->dead == 0)
			ft_print_status(philo, FORK);
	}
	sem_post(philo->sem_pairs);
} */

static void	ft_leave_forks(t_philo *philo)
{
	philo->eating = 0;
	philo->num_eaten++;
	sem_post(philo->sem_forks);
	sem_post(philo->sem_forks);
}

void	ft_eat(t_philo *philo)
{
	if (philo->dead == 0)
		ft_take_forks(philo);
	philo->eating = 1;
	philo->dies = philo->tt_die + ft_get_time_ms();
	if (philo->dead == 0)
		ft_print_status(philo, EAT);
	if (philo->dead == 0)
		ft_msleep(philo->tt_eat);
	ft_leave_forks(philo);
}

/* void	ft_eat(t_philo *philo)
{
	if (philo->dead == 0)
		ft_take_forks(philo);
	philo->eating = 1;
	sem_wait(philo->sem_eat);
	philo->dies = philo->tt_die + ft_get_time_ms();
	if (philo->dead == 0)
	{
		sem_post(philo->sem_eat);
		ft_print_status(philo, EAT);
	}
	else
		sem_post(philo->sem_eat);
	if (philo->dead == 0)
		ft_msleep(philo->tt_eat);
	ft_leave_forks(philo);
} */
