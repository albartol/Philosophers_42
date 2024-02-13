/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:56:12 by albartol          #+#    #+#             */
/*   Updated: 2024/02/13 19:32:43 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define YELLOW "\033[0;33m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;97m"
# define RESET "\033[0m"

# define DEAD "is \033[0;31mdead 💀\033[0m"
# define EAT "is \033[0;32meating 🍝\033[0;32m"
# define SLEEP "is \033[0;34msleeping 😴\033[0;32m"
# define THINK "is \033[0;36mthinking 🧠\033[0;32m"
# define FORK "has \033[0;97mtaken a fork 🍴\033[0;32m"

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	struct timeval	time;
	unsigned long	start;
	unsigned long	now;
	int				num_phi;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				num_to_eat;
}					t_philo;

//  aux functions
int					ft_atoi(const char *str);
int					ft_usleep(unsigned int time);
int					ft_print_status(t_philo *philo, int phi, char *str);

// ft_philo_init
int					ft_philo_init(t_philo *philo, int argc, char **argv);

#endif