/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:41:15 by albartol          #+#    #+#             */
/*   Updated: 2024/02/26 18:09:45 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	ft_take_forks(t_phi *phi)
{
	pthread_mutex_lock(&phi->fork);
	ft_num_dead(phi);
	if (phi->dead == 0)
		ft_print_status(phi->philo, phi->id, FORK);
	pthread_mutex_lock(phi->left_fork);
	ft_num_dead(phi);
	if (phi->dead == 0)
		ft_print_status(phi->philo, phi->id, FORK);
}

static void	ft_leave_forks(t_phi *phi)
{
	pthread_mutex_unlock(&phi->fork);
	pthread_mutex_unlock(phi->left_fork);
	pthread_mutex_lock(&phi->mem_lock);
	phi->num_eaten++;
	pthread_mutex_unlock(&phi->mem_lock);
}

void	ft_eat(t_phi *phi)
{
	ft_num_dead(phi);
	if (phi->dead != 0)
		return ;
	ft_take_forks(phi);
	pthread_mutex_lock(&phi->mem_lock);
	phi->dies = phi->philo->tt_die + ft_get_time_ms();
	pthread_mutex_unlock(&phi->mem_lock);
	ft_num_dead(phi);
	if (phi->dead == 0)
		ft_print_status(phi->philo, phi->id, EAT);
	ft_num_dead(phi);
	if (phi->dead == 0)
		ft_msleep(phi->philo->tt_eat);
	ft_leave_forks(phi);
}
