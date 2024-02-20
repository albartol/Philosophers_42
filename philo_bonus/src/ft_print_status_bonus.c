/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:35:40 by albartol          #+#    #+#             */
/*   Updated: 2024/02/19 23:39:14 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	ft_print_status(t_philo *philo, char *str)
{
	long long	ms;

	ms = ft_get_time_ms() - philo->start;
	printf(ORANGE "[%lld]" WHITE " %d" RESET " %s\n", ms, philo->id, str);
}

/* int	ft_print_status(t_philo *philo, int phi, char *str)
{
	long long	ms;

	ms = ft_get_time_ms();
	if (ms == -1)
		return (EXIT_FAILURE);
	pthread_mutex_lock(&philo->print_lock);
	ms -= philo->start;
	printf(ORANGE "[%lld]" WHITE " %d" RESET " %s\n", ms, phi, str);
	pthread_mutex_unlock(&philo->print_lock);
	return (EXIT_SUCCESS);
} */
