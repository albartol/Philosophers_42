/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rest_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:41:15 by albartol          #+#    #+#             */
/*   Updated: 2024/02/22 17:59:37 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	ft_rest(t_philo *philo)
{
	if (philo->dead == 0)
		ft_print_status(philo, SLEEP);
	if (philo->dead == 0)
		ft_msleep(philo->tt_sleep);
	if (philo->dead == 0)
		ft_print_status(philo, THINK);
}
