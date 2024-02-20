# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 14:52:30 by albartol          #+#    #+#              #
#    Updated: 2024/02/20 00:15:27 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:=gcc

CFLAGS:=-Wall -Wextra -Werror

SRC=src/philo_bonus.c \
	src/ft_atoi_bonus.c \
	src/ft_calloc_bonus.c \
	src/ft_usleep_bonus.c \
	src/ft_get_time_bonus.c \
	src/ft_philo_init_bonus.c \
	src/ft_print_status_bonus.c \
	src/ft_start_forks_bonus.c \
	src/ft_eat_bonus.c \
	src/ft_rest_bonus.c \
	src/ft_error_bonus.c \
	src/ft_create_sem_bonus.c \
	src/ft_unlink_sem_bonus.c \
	src/ft_open_sem_bonus.c \
	src/ft_close_sem_bonus.c

OBJ=$(SRC:%.c=%.o)

NAME=philo_bonus

all: $(NAME)

$(NAME): include/philo_bonus.h $(OBJ)
	$(CC) $(CFLAGS) -O3 $(OBJ) -o $@

%.o: %.c include/philo_bonus.h 
	$(CC) $(CFLAGS) -O3 -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re