/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthreads_cheker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:09:20 by albartol          #+#    #+#             */
/*   Updated: 2024/02/27 17:11:54 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_num_dead(t_phi *phi)
{
	if (phi->dead != 0)
		return ;
	pthread_mutex_lock(&phi->philo->mem_lock);
	if (phi->philo->num_dead != 0)
		phi->dead = 1;
	pthread_mutex_unlock(&phi->philo->mem_lock);
}

static void	ft_check_death(t_phi *phi)
{
	if (phi->dies <= ft_get_time_ms())
	{
		pthread_mutex_lock(&phi->philo->mem_lock);
		phi->philo->num_dead = 1;
		pthread_mutex_unlock(&phi->philo->mem_lock);
		ft_print_status(phi->philo, phi->id, DEAD);
	}
}

static void	ft_check_eaten(t_phi *phi)
{
	if (phi->num_eaten == phi->philo->num_to_eat)
	{
		pthread_mutex_lock(&phi->philo->mem_lock);
		phi->philo->num_eaten++;
		if (phi->philo->num_eaten >= phi->philo->num_phi)
			phi->philo->num_dead = 1;
		pthread_mutex_unlock(&phi->philo->mem_lock);
		phi->num_eaten++;
	}
}

void	*checker(void *arg)
{
	t_phi		*phi;

	phi = (t_phi *)arg;
	pthread_mutex_lock(&phi->philo->mem_lock);
	while (phi->philo->num_dead == 0)
	{
		pthread_mutex_unlock(&phi->philo->mem_lock);
		pthread_mutex_lock(&phi->mem_lock);
		ft_check_death(phi);
		ft_check_eaten(phi);
		pthread_mutex_unlock(&phi->mem_lock);
		pthread_mutex_lock(&phi->philo->mem_lock);
	}
	pthread_mutex_unlock(&phi->philo->mem_lock);
	return (0);
}

/* void	*checker(void *arg)
{
	t_phi		*phi;

	phi = (t_phi *)arg;
	pthread_mutex_lock(&phi->philo->mem_lock);
	while (phi->philo->num_dead == 0)
	{
		pthread_mutex_unlock(&phi->philo->mem_lock);
		pthread_mutex_lock(&phi->mem_lock);
		if (phi->dies <= ft_get_time_ms())
		{
			pthread_mutex_lock(&phi->philo->mem_lock);
			phi->philo->num_dead = 1;
			pthread_mutex_unlock(&phi->philo->mem_lock);
			ft_print_status(phi->philo, phi->id, DEAD);
		}
		if (phi->num_eaten == phi->philo->num_to_eat)
		{
			pthread_mutex_lock(&phi->philo->mem_lock);
			phi->philo->num_eaten++;
			if (phi->philo->num_eaten >= phi->philo->num_phi)
				phi->philo->num_dead = 1;
			pthread_mutex_unlock(&phi->philo->mem_lock);
			phi->num_eaten++;
		}
		pthread_mutex_unlock(&phi->mem_lock);
		pthread_mutex_lock(&phi->philo->mem_lock);
	}
	pthread_mutex_unlock(&phi->philo->mem_lock);
	return (0);
} */