# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 14:52:30 by albartol          #+#    #+#              #
#    Updated: 2024/02/14 17:16:43 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:=gcc

CFLAGS:=-Wall -Wextra -Werror

SRC=src/philo.c \
	src/ft_atoi.c \
	src/ft_usleep.c \
	src/ft_philo_init.c \
	src/ft_print_status.c \
	src/ft_get_time.c

OBJ=$(SRC:%.c=%.o)

NAME=philo

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -O3 $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -O3 -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re