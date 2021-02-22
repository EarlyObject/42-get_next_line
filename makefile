# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 13:13:58 by asydykna          #+#    #+#              #
#    Updated: 2021/02/21 18:23:34 by asydykna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = get_next_line.c\
	get_next_line_utils.c\
	main.c


CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

BUF = -D BUFFER_SIZE=3

all: program

program:
	$(CC) $(CFLAGS) $(BUF) $(SRC) leacks_cheker_ex.c -o main

debug:
	$(CC) -g $(CFLAGS) $(BUF) $(SRC) leacks_cheker_ex.c -o main

