/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:56:12 by albartol          #+#    #+#             */
/*   Updated: 2024/02/17 17:30:10 by albartol         ###   ########.fr       */
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
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[1;97m"
# define RESET "\033[0m"
# define ORANGE "\033[38;5;208m"

# define DEAD "\033[1;31mdied 💀\033[0m"
# define EAT "is\033[1;32m eating 🍝\033[0m"
# define SLEEP "is\033[1;34m sleeping 😴\033[0m"
# define THINK "is\033[1;36m thinking 🧠\033[0m"
# define FORK "has\033[1;35m taken a fork 🍴\033[0m"

typedef struct s_philo	t_philo;
typedef struct s_phi	t_phi;

struct s_phi
{
	pthread_t		thr;
	pthread_t		check_thr;
	int				id;
	int				eating;
	int				num_eaten;
	long long		dies;
	pthread_mutex_t	access_lock;
	pthread_mutex_t	fork;
	pthread_mutex_t	*left_fork;
	t_philo			*philo;
};

struct s_philo
{
	long long		start;
	int				num_phi;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				num_to_eat;
	int				num_eaten;
	int				num_dead;
	pthread_mutex_t	access_lock;
	pthread_mutex_t	write_lock;
	t_phi			*philos;
};

/*struct s_phi
{
	pthread_t		thread;
	int				id;
	int				dead;
	int				eating;
	int				num_eaten;
	long long		dies;
	pthread_mutex_t	access_lock;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*left_fork;
	t_philo			*philo;
};

struct s_philo
{
	long long		start;
	int				num_phi;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				num_to_eat;
	int				num_eaten;
	int				num_dead;
	pthread_mutex_t	access_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*forks;
	t_phi			*philos;
};*/

//	converts a string to an int
int					ft_atoi(const char *str);

// calloc copy
void				*ft_calloc(size_t len, size_t size);

// sleep time in microseconds
int					ft_usleep(unsigned int time_in_us);

//	sleep time in milliseconds
int					ft_msleep(unsigned int time_in_ms);

// gets time in milliseconds
long long			ft_get_time_ms(void);

// gets time in microseconds
long long			ft_get_time_us(void);

// prints the status depending on the constant sent
//int					ft_print_status(t_philo *philo, int phi, char *str);
void				ft_print_status(t_philo *philo, int phi, char *str);

// ft_philo_init: checks the arguments and initializes the values in s_philo
int					ft_philo_init(t_philo *philo, int argc, char **argv);

int					ft_start_philos(t_philo *philo);

int					ft_start_pthreads(t_philo *philo);

void				ft_clean(t_philo *philo);

void				ft_eat(t_phi *phi);

#endif