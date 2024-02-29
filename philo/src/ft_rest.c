/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:41:15 by albartol          #+#    #+#             */
/*   Updated: 2024/02/29 13:02:52 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_rest(t_phi *phi)
{
	ft_num_dead(phi);
	if (phi->dead != 0)
		return ;
	ft_print_status(phi, SLEEP);
	ft_num_dead(phi);
	if (phi->dead == 0)
		ft_msleep(phi->philo->tt_sleep);
	ft_num_dead(phi);
	if (phi->dead == 0)
		ft_print_status(phi, THINK);
}
