/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_pthreads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:22:40 by albartol          #+#    #+#             */
/*   Updated: 2024/02/26 18:09:54 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	thread_fail(t_philo *philo)
{
	pthread_mutex_lock(&philo->mem_lock);
	philo->num_dead = 1;
	pthread_mutex_unlock(&philo->mem_lock);
	ft_print_status(philo, 0, "Failed to create thread\n");
}

static void	*start(void *arg)
{
	t_phi		*phi;

	phi = (t_phi *)arg;
	phi->dies = phi->philo->tt_die + phi->philo->start;
	if (phi->id % 2 == 0)
	{
		// ft_num_dead(phi);
		// if (phi->dead != 0)
		// 	return (0);
		// ft_print_status(phi->philo, phi->id, THINK);
		ft_num_dead(phi);
		if (phi->dead != 0)
			return (0);
		ft_msleep(phi->philo->tt_eat - phi->philo->tt_eat / 5);
	}
	if (pthread_create(&phi->check_thr, NULL, &checker, arg))
	{
		phi->dead = 1;
		thread_fail(phi->philo);
		return (0);
	}
	while (phi->dead == 0)
	{
		ft_eat(phi);
		ft_rest(phi);
		ft_num_dead(phi);
	}
	pthread_join(phi->check_thr, NULL);
	return (0);
}

static int	ft_clean_threads(t_philo *philo)
{
	int	i;

	if (philo->num_phi == 1)
	{
		ft_msleep(philo->tt_die + 10);
		if (pthread_detach(philo->philos[0].thr))
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	i = 0;
	while (i < philo->num_phi)
	{
		if (pthread_join(philo->philos[i].thr, NULL))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_start_pthreads(t_philo *ph)
{
	int	i;

	ph->start = ft_get_time_ms();
	if (ph->start == -1)
		return (ft_error("Failed to get start time\n"));
	i = 0;
	while (i < ph->num_phi)
	{
		if (pthread_create(&ph->philos[i].thr, NULL, &start, &ph->philos[i]))
		{
			thread_fail(ph);
			break ;
		}
		i++;
		ft_usleep(5);
	}
	if (ft_clean_threads(ph))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
