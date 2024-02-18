/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:41:15 by albartol          #+#    #+#             */
/*   Updated: 2024/02/17 17:30:18 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	ft_take_forks(t_phi *phi)
{
	pthread_mutex_lock(&phi->fork);
	if (phi->philo->num_dead == 0)
		ft_print_status(phi->philo, phi->id, FORK);
	pthread_mutex_lock(phi->left_fork);
	if (phi->philo->num_dead == 0)
		ft_print_status(phi->philo, phi->id, FORK);
}

static void	ft_leave_forks(t_phi *phi)
{
	pthread_mutex_unlock(&phi->fork);
	pthread_mutex_unlock(phi->left_fork);
	pthread_mutex_lock(&phi->access_lock);
	phi->eating = 0;
	phi->num_eaten++;
	pthread_mutex_unlock(&phi->access_lock);
}

void	ft_eat(t_phi *phi)
{
	if (phi->philo->num_dead == 0)
		ft_take_forks(phi);
	pthread_mutex_lock(&phi->access_lock);
	phi->eating = 1;
	// phi->dies += phi->philo->tt_die + phi->philo->tt_eat;
	phi->dies = phi->philo->tt_die + ft_get_time_ms();
	pthread_mutex_unlock(&phi->access_lock);
	if (phi->philo->num_dead == 0)
	{
		ft_print_status(phi->philo, phi->id, EAT);
		ft_msleep(phi->philo->tt_eat);
	}
	ft_leave_forks(phi);
}
