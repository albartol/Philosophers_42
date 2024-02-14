/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:35:40 by albartol          #+#    #+#             */
/*   Updated: 2024/02/14 17:14:47 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_print_status(t_philo *philo, int phi, char *str)
{
	unsigned int	ms;

	philo->now = ft_get_time_ms();
	if (philo->now == -1)
		return (EXIT_FAILURE);
	ms = philo->now - philo->start;
	printf(YELLOW "[%u]" WHITE " %d" RESET " %s\n", ms, phi, str);
	return (EXIT_SUCCESS);
}
