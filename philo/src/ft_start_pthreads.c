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
			if (phi->philo->num_eaten >= phi->philo->num_phi)
				phi->philo->num_dead++;
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
	// phi->dies = phi->philo->tt_die + ft_get_time_ms();
	pthread_create(&phi->check_thr, NULL, &checker, arg);
	while (phi->philo->num_dead == 0)
	{
		if (phi->philo->num_dead == 0)
			ft_eat(phi);
		/* if (phi->num_eaten == phi->philo->num_to_eat)
		{
			pthread_mutex_lock(&phi->philo->access_lock);
			phi->philo->num_eaten++;
			if (phi->philo->num_eaten >= phi->philo->num_phi)
				phi->philo->num_dead++;
			pthread_mutex_unlock(&phi->philo->access_lock);
			phi->num_eaten++;
		} */
		if (phi->philo->num_dead == 0)
		{
			ft_print_status(phi->philo, phi->id, SLEEP);
			ft_msleep(phi->philo->tt_sleep);
		}
		if (phi->philo->num_dead == 0)
			ft_print_status(phi->philo, phi->id, THINK);
	}
	pthread_join(phi->check_thr, NULL);
	return (0);
}

/* static void	*eat_count(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->num_dead == 0)
	{
		if (philo->num_eaten >= philo->num_phi)
		{
			pthread_mutex_lock(&philo->access_lock);
			philo->num_dead++;
			pthread_mutex_unlock(&philo->access_lock);
		}
	}
	return (0);
} */

int	ft_start_pthreads(t_philo *philo)
{
	int	i;
	// pthread_t	thread;

	philo->start = ft_get_time_ms();
	if (philo->start == -1)
		return (EXIT_FAILURE);
	i = 0;
	// if (philo->num_to_eat > -1)
	// 	pthread_create(&thread, NULL, &eat_count, philo);
	while (i < philo->num_phi)
	{
		pthread_create(&philo->philos[i].thr, NULL, &start, &philo->philos[i]);
		i++;
		ft_usleep(1);
	}
	if (philo->num_phi == 1)
	{
		ft_msleep(philo->tt_die + 2);
		pthread_detach(philo->philos[0].thr);
		return (EXIT_SUCCESS);
	}
	i = 0;
	while (i < philo->num_phi)
	{
		pthread_join(philo->philos[i].thr, NULL);
		i++;
	}
	return (EXIT_SUCCESS);
}
