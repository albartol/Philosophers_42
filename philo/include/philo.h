/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:56:12 by albartol          #+#    #+#             */
/*   Updated: 2024/02/14 17:12:02 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define YELLOW "\033[0;33m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;97m"
# define RESET "\033[0m"

# define DEAD "\033[0;31m died 💀\033[0m"
# define EAT "is\033[0;32m eating 🍝\033[0;32m"
# define SLEEP "is\033[0;34m sleeping 😴\033[0;32m"
# define THINK "is\033[0;36m thinking 🧠\033[0;32m"
# define FORK "has\033[0;97m taken a fork 🍴\033[0;32m"

typedef struct s_phi
{
	pthread_t		phi;
	int				id;
	int				dead;
	int				eating;
	int				sleeping;
	int				num_eaten;
	long long		dies;
	pthread_mutex_t	lock;
	pthread_mutex_t	fork;
}					t_phi;

typedef struct s_philo
{
	long long		start;
	long long		now;
	int				num_phi;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				num_to_eat;
	t_phi			*philos;
	pthread_mutex_t	lock;
}					t_philo;

//	converts a string to an int
int					ft_atoi(const char *str);

// sleep time in microseconds
int					ft_usleep(unsigned int time_in_us);

//	sleep time in milliseconds
int					ft_msleep(unsigned int time_in_ms);

// gets time in milliseconds
long long			ft_get_time_ms(void);

// gets time in microseconds
long long			ft_get_time_us(void);

// prints the status depending on the constant sent
int					ft_print_status(t_philo *philo, int phi, char *str);

// ft_philo_init: checks the arguments and initializes the values in s_philo
int					ft_philo_init(t_philo *philo, int argc, char **argv);

#endif