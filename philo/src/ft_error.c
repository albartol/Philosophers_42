/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:17:16 by albartol          #+#    #+#             */
/*   Updated: 2024/02/22 17:58:43 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_error(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (write(STDERR_FILENO, str, i));
}
