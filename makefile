# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 13:13:58 by asydykna          #+#    #+#              #
#    Updated: 2021/02/17 18:54:26 by asydykna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = get_next_line.c\
	get_next_line_utils.c\
	main.c


CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

BUF = -D BUFFER_SIZE=32

all: program

program:
	$(CC) $(CFLAGS) $(BUF) $(SRC)
