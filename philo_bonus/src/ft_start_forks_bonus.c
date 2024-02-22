/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_forks_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:22:40 by albartol          #+#    #+#             */
/*   Updated: 2024/02/22 16:43:38 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

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

static void	ft_child_start(t_philo *philo, int i)
{
	int		status;

	philo->id = i;
	status = start(philo);
	ft_close_sem(philo, 5);
	free(philo);
	if (status)
		exit (EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

/* static void	ft_child_start(t_philo *philo, int i)
{
	int		status;
	char	*name;

	philo->id = i;
	name = ft_create_name(philo->id);
	if (name == NULL)
	{
		ft_close_sem(philo, 5);
		free(philo);
		exit (EXIT_FAILURE);
	}
	philo->sem_eat = sem_open(name, O_CREAT, SEM_PER, 1);
	free(name);
	if (SEM_FAILED == philo->sem_forks)
	{
		sem_post(philo->sem_deaths);
		ft_close_sem(philo, 5);
		free(philo);
		ft_error("Error ft_child_start(sem_eat)\n");
		exit (EXIT_FAILURE);
	}
	status = start(philo);
	ft_close_sem(philo, 5);
	sem_close(philo->sem_eat);
	sem_unlink(name);
	free(philo);
	if (status)
		exit (EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
 */

/* static void	*check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (sem_wait(philo->sem_deaths) == 0)
		kill(0, SIGTERM);
	return (0);
}

static void	ft_check_num_eat(t_philo *philo)
{
	int		i;

	philo->dies = philo->tt_die + philo->start;
	if (pthread_create(&philo->check_thr, NULL, &check_death, philo))
	{
		philo->dead = 1;
		ft_error("Failed to create thread\n");
	}
	i = philo->num_phi;
	while (i--)
		sem_wait(philo->sem_num_eat);
	kill(0, SIGTERM);
	pthread_join(philo->check_thr, NULL);
} */

 static void	ft_check_num_eat(t_philo *philo)
{
	int		i;

	i = philo->num_phi;
	while (i--)
		sem_wait(philo->sem_num_eat);
	sem_post(philo->sem_deaths);
	// kill(0, SIGTERM);
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
}

/* int	ft_start_forks(t_philo *philo)
{
	int	i;
	int	id;

	philo->start = ft_get_time_ms();
	if (philo->start == -1)
		return (ft_error("Failed to get start time\n"));
	i = 0;
	id = 1;
	while (i < philo->num_phi)
	{
		if (id == 0 || id == -1)
			break ;
		if (id != 0)
			id = fork();
		i++;
	}
	if (id == 0)
		ft_child_start(philo, i);
	if (id == -1)
	{
		sem_post(philo->sem_deaths);
		while (waitpid(-1, NULL, 0) != -1 || errno != ECHILD)
		{
		}
		return (ft_error("Error in fork\n"));
	}
	if (philo->num_to_eat > 0)
		ft_check_num_eat(philo);
	while (waitpid(-1, NULL, 0) != -1 || errno != ECHILD)
	{
	}
	return (EXIT_SUCCESS);
} */
