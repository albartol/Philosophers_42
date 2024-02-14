/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:56:17 by albartol          #+#    #+#             */
/*   Updated: 2024/02/14 17:12:06 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	*test(void *arg)
{
	t_philo	*philo;

	philo = arg;
	ft_msleep(philo->tt_die);
	pthread_mutex_lock(&philo->lock);
	ft_print_status(philo, 1, DEAD);
	pthread_mutex_unlock(&philo->lock);
	ft_msleep(philo->tt_die);
	pthread_mutex_lock(&philo->lock);
	ft_print_status(philo, 1, EAT);
	pthread_mutex_unlock(&philo->lock);
	ft_msleep(philo->tt_die);
	pthread_mutex_lock(&philo->lock);
	ft_print_status(philo, 1, SLEEP);
	pthread_mutex_unlock(&philo->lock);
	ft_msleep(philo->tt_die);
	pthread_mutex_lock(&philo->lock);
	ft_print_status(philo, 1, THINK);
	pthread_mutex_unlock(&philo->lock);
	ft_msleep(philo->tt_die);
	pthread_mutex_lock(&philo->lock);
	ft_print_status(philo, 1, FORK);
	pthread_mutex_unlock(&philo->lock);
	return (0);
}

static void	*test_2(void *arg)
{
	t_philo	*philo;

	philo = arg;
	ft_msleep(philo->tt_die);
	pthread_mutex_lock(&philo->lock);
	ft_print_status(philo, 2, DEAD);
	pthread_mutex_unlock(&philo->lock);
	ft_msleep(philo->tt_die);
	pthread_mutex_lock(&philo->lock);
	ft_print_status(philo, 2, EAT);
	pthread_mutex_unlock(&philo->lock);
	ft_msleep(philo->tt_die);
	pthread_mutex_lock(&philo->lock);
	ft_print_status(philo, 2, SLEEP);
	pthread_mutex_unlock(&philo->lock);
	ft_msleep(philo->tt_die);
	pthread_mutex_lock(&philo->lock);
	ft_print_status(philo, 2, THINK);
	pthread_mutex_unlock(&philo->lock);
	ft_msleep(philo->tt_die);
	pthread_mutex_lock(&philo->lock);
	ft_print_status(philo, 2, FORK);
	pthread_mutex_unlock(&philo->lock);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	philo;
	t_phi	phi;
	t_phi	phi_2;

	if (argc < 5 || argc > 6)
		return (EXIT_SUCCESS);
	if (ft_philo_init(&philo, argc, argv))
		return (EXIT_FAILURE);
	pthread_mutex_init(&philo.lock, NULL);
	pthread_create(&phi.phi, NULL, test, &philo);
	pthread_create(&phi_2.phi, NULL, test_2, &philo);
	pthread_join(phi.phi, NULL);
	pthread_join(phi_2.phi, NULL);
	pthread_mutex_destroy(&philo.lock);
	return (EXIT_SUCCESS);
}
