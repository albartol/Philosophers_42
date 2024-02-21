/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthreads_routine_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:22:40 by albartol          #+#    #+#             */
/*   Updated: 2024/02/21 01:45:49 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static void	*check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (sem_wait(philo->sem_deaths) == 0)
	{
		philo->dead = 1;
		sem_post(philo->sem_deaths);
		sem_post(philo->sem_num_eat);
	}
	return (0);
}

void	*ft_thread_checker(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (pthread_create(&philo->check_deaths, NULL, &check_death, philo))
	{
		philo->dead = 1;
		ft_error("Failed to create thread\n");
		return (0);
	}
	while (philo->dead == 0)
	{
		if (philo->dies <= ft_get_time_ms() && philo->eating == 0)
		{
			philo->dead = 1;
			sem_post(philo->sem_deaths);
			ft_print_status(philo, DEAD);
			break ;
		}
		if (philo->num_eaten == philo->num_to_eat)
		{
			sem_post(philo->sem_num_eat);
			philo->num_eaten++;
		}
	}
	pthread_join(philo->check_deaths, NULL);
	return (0);
}

/* void	*ft_thread_checker(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (pthread_create(&philo->check_deaths, NULL, &check_death, philo))
	{
		philo->dead++;
		ft_error("Failed to create thread\n");
		return (0);
	}
	while (philo->dead == 0)
	{
		sem_wait(philo->sem_eat);
		if (philo->dies <= ft_get_time_ms() && philo->eating == 0)
		{
			kill(0, SIGTERM);
			sem_post(philo->sem_deaths);
			ft_print_status(philo, DEAD);
			sem_post(philo->sem_eat);
			break ;
		}
		sem_post(philo->sem_eat);
		if (philo->num_eaten == philo->num_to_eat)
		{
			sem_post(philo->sem_num_eat);
			philo->num_eaten++;
		}
	}
	pthread_join(philo->check_deaths, NULL);
	return (0);
} */