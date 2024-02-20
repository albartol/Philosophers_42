/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:41:15 by albartol          #+#    #+#             */
/*   Updated: 2024/02/20 01:30:18 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	ft_take_forks(t_philo *philo)
{
	if (philo->dead == 0)
		ft_print_status(philo, FORK);
	if (philo->dead == 0)
		ft_print_status(philo, FORK);
}

static void	ft_leave_forks(t_philo *philo)
{
	philo->eating = 0;
	philo->num_eaten++;
}

void	ft_eat(t_philo *philo)
{
	if (philo->dead == 0)
		ft_take_forks(philo);
	philo->eating = 1;
	philo->dies = philo->tt_die + ft_get_time_ms();
	if (philo->dead == 0)
	{
		ft_print_status(philo, EAT);
		ft_msleep(philo->tt_eat);
	}
	ft_leave_forks(philo);
}
