/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:01:12 by albartol          #+#    #+#             */
/*   Updated: 2024/02/22 17:58:52 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_calloc(size_t len, size_t size)
{
	void	*array;

	array = (void *)malloc(len * size);
	if (!array)
		return (NULL);
	memset(array, 0, len * size);
	return (array);
}
