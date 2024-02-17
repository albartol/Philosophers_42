/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_pthreads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:22:40 by albartol          #+#    #+#             */
/*   Updated: 2024/02/17 17:24:49 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	*checker(void *arg)
{
	t_phi		*phi;

	phi = (t_phi *)arg;
	while (phi->philo->num_dead == 0)
	{
		pthread_mutex_lock(&phi->access_lock);
		if (ft_get_time_ms() >= phi->dies && phi->eating == 0)
		{
			pthread_mutex_lock(&phi->philo->access_lock);
			phi->philo->num_dead++;
			pthread_mutex_unlock(&phi->philo->access_lock);
			ft_print_status(phi->philo, phi->id, DEAD);
		}
		if (phi->num_eaten == phi->philo->num_to_eat)
		{
			pthread_mutex_lock(&phi->philo->access_lock);
			phi->philo->num_eaten++;
			pthread_mutex_unlock(&phi->philo->access_lock);
			phi->num_eaten++;
		}
		pthread_mutex_unlock(&phi->access_lock);
	}
	return (0);
}

static void	*start(void *arg)
{
	t_phi		*phi;

	phi = (t_phi *)arg;
	phi->dies = phi->philo->tt_die + phi->philo->start;
	pthread_create(&phi->check_thr, NULL, &checker, &phi);
	while (phi->philo->num_dead == 0)
	{
		ft_eat(phi);
		ft_print_status(phi->philo, phi->id, THINK);
	}
	pthread_join(phi->check_thr, NULL);
	return (0);
}

int	ft_start_pthreads(t_philo *philo)
{
	int	i;

	philo->start = ft_get_time_ms();
	if (philo->start == -1)
		return (EXIT_FAILURE);
	i = 0;
	while (i < philo->num_phi)
	{
		pthread_create(&philo->philos[i].thr, NULL, &start, &philo->philos[i]);
		i++;
		ft_usleep(1);
	}
	i = 0;
	while (i < philo->num_phi)
	{
		pthread_join(philo->philos[i].thr, NULL);
		i++;
	}
	return (EXIT_SUCCESS);
}
