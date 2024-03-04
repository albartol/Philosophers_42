/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rest_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:41:15 by albartol          #+#    #+#             */
/*   Updated: 2024/03/04 13:23:24 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	ft_rest(t_philo *philo)
{
	ft_print_status(philo, SLEEP);
	ft_msleep(philo->tt_sleep);
	ft_print_status(philo, THINK);
}

/* void	ft_rest(t_philo *philo)
{
	if (philo->dies <= ft_get_time_ms() + philo->tt_sleep)
	{
		ft_print_status(philo, SLEEP);
		ft_msleep(philo->dies - ft_get_time_ms());
		ft_print_status(philo, DEAD);
		kill(0, SIGKILL);
	}
	ft_print_status(philo, SLEEP);
	ft_msleep(philo->tt_sleep);
	if (philo->dies <= ft_get_time_ms())
	{
		ft_print_status(philo, DEAD);
		kill(0, SIGKILL);
	}
	ft_print_status(philo, THINK);
} */

/* void	ft_rest(t_philo *philo)
{
	if (philo->dead == 0)
		ft_print_status(philo, SLEEP);
	if (philo->dead == 0)
		ft_msleep(philo->tt_sleep);
	if (philo->dead == 0)
		ft_print_status(philo, THINK);
} */