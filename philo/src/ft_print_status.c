/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:35:40 by albartol          #+#    #+#             */
/*   Updated: 2024/02/13 18:48:33 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_print_status(t_philo *philo, int phi, char *str)
{
	unsigned long	ms;

	if (gettimeofday(&philo->time, NULL) == -1)
		return (EXIT_FAILURE);
	philo->now = philo->time.tv_sec * 1000 + philo->time.tv_usec / 1000;
	ms = philo->now - philo->start;
	printf(YELLOW "[%lu]" RESET WHITE " %d" RESET " %s\n", ms, phi, str);
	return (EXIT_SUCCESS);
}
