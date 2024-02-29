# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 14:52:30 by albartol          #+#    #+#              #
#    Updated: 2024/02/29 14:25:08 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:=gcc

CFLAGS:=-Wall -Wextra -Werror -pthread

SRC=src/philo.c \
	src/ft_atoi.c \
	src/ft_calloc.c \
	src/ft_usleep.c \
	src/ft_get_time.c \
	src/ft_philo_init.c \
	src/ft_print_status.c \
	src/ft_start_pthreads.c \
	src/ft_clean.c \
	src/ft_eat.c \
	src/ft_rest.c \
	src/ft_error.c \
	src/ft_pthreads_cheker.c

OBJ=$(SRC:%.c=%.o)

NAME=philo

all: $(NAME)

$(NAME): include/philo.h $(OBJ)
	$(CC) $(CFLAGS) -O3 $(OBJ) -o $@

%.o: %.c include/philo.h 
	$(CC) $(CFLAGS) -O3 -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re