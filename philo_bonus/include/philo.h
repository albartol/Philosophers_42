/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:56:12 by albartol          #+#    #+#             */
/*   Updated: 2024/02/20 01:30:10 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//	for ptread_create, ptread_detach & ptread_join
# include <pthread.h>
// for printf
# include <stdio.h>
// for malloc, free, exit & macros
# include <stdlib.h>
// for memset
# include <string.h>
// for write, usleep && fork
# include <unistd.h>
// for gettimeofday
# include <sys/time.h>
// for fork & kill
# include <sys/types.h>
// for waitpid
# include <sys/wait.h>
// for sem_open
# include <sys/stat.h> /* For mode constants */
// for sem_open
# include <fcntl.h> /* For O_* constants */
// for sem_open, sem_close, sem_post, sem_wait & sem_unlink
# include <semaphore.h>
// for macro ECHILD
# include <errno.h>
// for kill
# include <signal.h>

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

typedef struct s_philo
{
	long long		start;
	int				num_phi;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				num_to_eat;
	int				num_eaten;
	pthread_t		check_thr;
	int				id;
	int				eating;
	int				dead;
	long long		dies;
}					t_philo;

//	converts a string to an int
int					ft_atoi(const char *str);

//	prints a string to STDERR and returns the number of bytes printed or -1
int					ft_error(char *str);

//	allocs memory and sets the bytes to 0
void				*ft_calloc(size_t len, size_t size);

//	sleep time in microseconds
int					ft_usleep(unsigned int time_in_us);

//	sleep time in milliseconds
int					ft_msleep(unsigned int time_in_ms);

//	gets time in milliseconds
long long			ft_get_time_ms(void);

//	gets time in microseconds
long long			ft_get_time_us(void);

//	prints the status depending on the string sent
void				ft_print_status(t_philo *philo, char *str);
//int					ft_print_status(t_philo *philo, int phi, char *str);

//	checks the arguments and initializes the values in t_philo
int					ft_philo_init(t_philo *philo, int argc, char **argv);

//	creates the child proceses and starts the execution of the philosophers
int					ft_start_forks(t_philo *philo);

//	the eating action for a philosopher from taking the fork to droping it
void				ft_eat(t_philo *philo);

//	the resting action for a philosopher to do after eating: sleaping & tinking
void				ft_rest(t_philo *philo);

#endif