/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:41:15 by albartol          #+#    #+#             */
/*   Updated: 2024/02/26 15:48:35 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_rest(t_phi *phi)
{
	if (phi->philo->num_dead == 0)
		ft_print_status(phi->philo, phi->id, SLEEP);
	if (phi->philo->num_dead == 0)
		ft_msleep(phi->philo->tt_sleep);
	if (phi->philo->num_dead == 0)
		ft_print_status(phi->philo, phi->id, THINK);
}
