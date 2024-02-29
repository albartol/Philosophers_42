/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:35:40 by albartol          #+#    #+#             */
/*   Updated: 2024/02/29 13:13:22 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_print_status(t_phi *phi, char *str)
{
	long long	ms;

	ft_num_dead(phi);
	if (phi->dead != 0)
		return ;
	pthread_mutex_lock(&phi->philo->print_lock);
	ms = ft_get_time_ms() - phi->philo->start;
	ft_num_dead(phi);
	if (phi->dead != 0)
	{
		pthread_mutex_unlock(&phi->philo->print_lock);
		return ;
	}
	printf(ORANGE "[%lld]" WHITE " %d" RESET " %s\n", ms, phi->id, str);
	pthread_mutex_unlock(&phi->philo->print_lock);
}

void	ft_print_death(t_phi *phi, char *str)
{
	long long	ms;

	// pthread_mutex_lock(&phi->philo->print_lock);
	ms = ft_get_time_ms() - phi->philo->start;
	printf(ORANGE "[%lld]" WHITE " %d" RESET " %s\n", ms, phi->id, str);
	// pthread_mutex_unlock(&phi->philo->print_lock);
}

/* void	ft_print_status(t_philo *philo, int phi_id, char *str)
{
	long long	ms;

	pthread_mutex_lock(&philo->print_lock);
	ms = ft_get_time_ms() - philo->start;
	printf(ORANGE "[%lld]" WHITE " %d" RESET " %s\n", ms, phi_id, str);
	pthread_mutex_unlock(&philo->print_lock);
} */

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
