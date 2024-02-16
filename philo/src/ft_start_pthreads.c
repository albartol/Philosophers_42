/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_pthreads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:22:40 by albartol          #+#    #+#             */
/*   Updated: 2024/02/16 18:41:23 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	*test(void *arg)
{
	t_phi	*phi;

	phi = arg;
	ft_msleep(phi->philo->tt_die);
	ft_print_status(phi->philo, phi->id, DEAD);
	ft_msleep(phi->philo->tt_die);
	ft_print_status(phi->philo, phi->id, EAT);
	ft_msleep(phi->philo->tt_die);
	ft_print_status(phi->philo, phi->id, SLEEP);
	ft_msleep(phi->philo->tt_die);
	ft_print_status(phi->philo, phi->id, THINK);
	ft_msleep(phi->philo->tt_die);
	ft_print_status(phi->philo, phi->id, FORK);
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
		pthread_create(&philo->philos[i].thread, NULL, test, &philo->philos[i]);
		i++;
		ft_usleep(1);
	}
	i = 0;
	while (i < philo->num_phi)
	{
		pthread_join(philo->philos[i].thread, NULL);
		i++;
	}
	return (EXIT_SUCCESS);
}
