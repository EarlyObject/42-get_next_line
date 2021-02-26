# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 13:13:58 by asydykna          #+#    #+#              #
#    Updated: 2021/02/26 12:38:26 by asydykna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = get_next_line.c\
	get_next_line_utils.c\
	main.c


CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

BUF = -D BUFFER_SIZE=20

all: program

program:
	$(CC) $(CFLAGS) $(BUF) $(SRC) leacks_cheker_ex.c -o main

debug:
	$(CC) -g $(CFLAGS) $(BUF) $(SRC) leacks_cheker_ex.c -o main

