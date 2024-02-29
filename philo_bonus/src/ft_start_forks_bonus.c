/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_forks_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:22:40 by albartol          #+#    #+#             */
/*   Updated: 2024/02/29 17:42:59 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static void	ft_check_num_eat(t_philo *philo)
{
	int		i;

	i = philo->num_phi;
	while (i--)
		sem_wait(philo->sem_num_eat);
	kill(0, SIGTERM);
}

static void	ft_fork_fail(void)
{
	ft_error("Error in fork\n");
	kill(0, SIGTERM);
}

int	ft_start_forks(t_philo *philo)
{
	int	i;
	int	id;

	philo->start = ft_get_time_ms();
	if (philo->start == -1)
		return (ft_error("Failed to get start time\n"));
	i = 0;
	while (i++ < philo->num_phi)
	{
		id = fork();
		if (id == 0 || id == -1)
			break ;
	}
	if (id == 0)
		ft_child_start(philo, i);
	if (id == -1)
		ft_fork_fail();
	if (philo->num_to_eat > 0)
		ft_check_num_eat(philo);
	while (waitpid(-1, NULL, 0) != -1 || errno != ECHILD)
	{
	}
	return (EXIT_SUCCESS);
}

/* static void	ft_check_num_eat(t_philo *philo)
{
	int		i;

	i = philo->num_phi;
	while (i--)
		sem_wait(philo->sem_num_eat);
	i = 0;
	while (i++ < philo->num_phi)
		sem_post(philo->sem_deaths);
}

static int	ft_fork_fail(t_philo *philo)
{
	sem_post(philo->sem_deaths);
	while (waitpid(-1, NULL, 0) != -1 || errno != ECHILD)
	{
	}
	return (ft_error("Error in fork\n"));
}

int	ft_start_forks(t_philo *philo)
{
	int	i;
	int	id;

	philo->start = ft_get_time_ms();
	if (philo->start == -1)
		return (ft_error("Failed to get start time\n"));
	i = 0;
	while (i++ < philo->num_phi)
	{
		id = fork();
		if (id == 0 || id == -1)
			break ;
	}
	if (id == 0)
		ft_child_start(philo, i);
	if (id == -1)
		return (ft_fork_fail(philo));
	if (philo->num_to_eat > 0)
		ft_check_num_eat(philo);
	while (waitpid(-1, NULL, 0) != -1 || errno != ECHILD)
	{
	}
	return (EXIT_SUCCESS);
} */
/* static void	*check_eaten(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	i = philo->num_phi;
	while (i--)
		sem_wait(philo->sem_num_eat);
	// sem_post(philo->sem_deaths);
	kill(0, SIGKILL);
	return (0);
}

static void	ft_terminate(t_philo *philo)
{
	if (philo->num_to_eat > 0)
	{
		if (pthread_create(&philo->check_thr, NULL, &check_eaten, philo))
		{
			ft_error("Failed to create thread\n");
			sem_post(philo->sem_deaths);
		}
	}
	sem_wait(philo->sem_deaths);
	if (philo->num_to_eat > 0)
		pthread_join(philo->check_thr, NULL);
	// ft_close_sem(philo, 5);
	// kill(0, SIGTERM);
	kill(0, SIGKILL);
}

static int	ft_fork_fail(t_philo *philo)
{
	sem_post(philo->sem_deaths);
	while (waitpid(-1, NULL, 0) != -1)
	{
	}
	return (ft_error("Error in fork\n"));
}

int	ft_start_forks(t_philo *philo)
{
	int	i;
	int	id;

	philo->start = ft_get_time_ms();
	if (philo->start == -1)
		return (ft_error("Failed to get start time\n"));
	i = 0;
	while (i++ < philo->num_phi)
	{
		id = fork();
		if (id == 0 || id == -1)
			break ;
	}
	if (id == 0)
		ft_child_start(philo, i);
	if (id == -1)
		return (ft_fork_fail(philo));
	ft_terminate(philo);
	while (waitpid(-1, NULL, 0) != -1)
	{
	}
	return (EXIT_SUCCESS);
} */
