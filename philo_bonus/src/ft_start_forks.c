/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_forks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:22:40 by albartol          #+#    #+#             */
/*   Updated: 2024/02/20 01:44:49 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	*checker(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	// while (philo->dead == 0)
	// {
	// 	if (philo->dies <= ft_get_time_ms() && philo->eating == 0)
	// 	{
	// 		philo->dead++;
	// 		ft_print_status(philo, DEAD);
	// 	}
	// 	if (philo->num_eaten == philo->num_to_eat)
	// 	{
	// 		philo->num_eaten++;
	// 		if (philo->num_eaten >= philo->num_phi)
	// 			philo->dead++;
	// 		philo->num_eaten++;
	// 	}
	// }
	printf("Philo ID from thread: %d\n", philo->id);
	return (0);
}

static int	start(t_philo *philo)
{

	philo->dies = philo->tt_die + philo->start;
	if (pthread_create(&philo->check_thr, NULL, &checker, philo))
	{
		philo->dead++;
		return (ft_error("Failed to create thread\n"));
	}
	// if (philo->id % 2 == 0 && philo->dead == 0)
	// {
	// 	ft_print_status(philo, THINK);
	// 	ft_usleep(500);
	// }
	// while (philo->dead == 0)
	// {
	// 	if (philo->dead == 0)
	// 		ft_eat(philo);
	// 	ft_rest(philo);
	// }
	pthread_join(philo->check_thr, NULL);
	printf("Philo ID: %d\n", philo->id);
	return (0);
}

int	ft_start_forks(t_philo *philo)
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
	{
		philo->id = i;
		start(philo);
	}
	if (id == -1)
	{
		while (waitpid(-1, NULL, 0) != -1 || errno != ECHILD);
		return (ft_error("Error in fork\n"));
	}
	while (waitpid(-1, NULL, 0) != -1 || errno != ECHILD);
	return (EXIT_SUCCESS);
}
