/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_routine_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:22:40 by albartol          #+#    #+#             */
/*   Updated: 2024/02/28 13:52:31 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static void	*check_death(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	i = 0;
	if (sem_wait(philo->sem_deaths) == 0)
	{
		philo->dead = 1;
		sem_post(philo->sem_num_eat);
		while (i++ < philo->num_phi)
			sem_post(philo->sem_deaths);
	}
	return (0);
}

static void	*ft_thread_checker(void *arg)
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
		// if (philo->dies <= ft_get_time_ms() && philo->eating == 0)
		if (philo->dies <= ft_get_time_ms())
		{
			philo->dead = 1;
			sem_post(philo->sem_deaths);
			ft_print_status(philo, DEAD);
		}
		else if (philo->num_eaten == philo->num_to_eat)
		{
			sem_post(philo->sem_num_eat);
			philo->num_eaten++;
		}
	}
	pthread_join(philo->check_deaths, NULL);
	return (0);
}

static int	start(t_philo *philo)
{
	philo->dies = philo->tt_die + philo->start;
	if (pthread_create(&philo->check_thr, NULL, &ft_thread_checker, philo))
	{
		philo->dead = 1;
		return (ft_error("Failed to create thread\n"));
	}
	while (philo->dead == 0)
	{
		if (philo->dead == 0)
			ft_eat(philo);
		if (philo->dead == 0)
			ft_rest(philo);
	}
	pthread_join(philo->check_thr, NULL);
	return (EXIT_SUCCESS);
}

static void	ft_one_philo(t_philo *philo)
{
	ft_print_status(philo, FORK);
	ft_msleep(philo->tt_die);
	ft_print_status(philo, DEAD);
	exit(EXIT_SUCCESS);
}

void	ft_child_start(t_philo *philo, int i)
{
	int		status;

	philo->id = i;
	if (philo->num_phi == 1)
		ft_one_philo(philo);
	status = start(philo);
	ft_close_sem(philo, 5);
	if (status)
		exit (EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
