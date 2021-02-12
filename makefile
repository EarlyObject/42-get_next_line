# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 13:13:58 by asydykna          #+#    #+#              #
#    Updated: 2021/02/12 21:34:13 by asydykna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = get_next_line.c	\
	get_next_line_utils.c\
	main.c

OBJ = $(SRC:.c=.o)


CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all: $(OBJ)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) 

fclean: clean
	$(RM) all

re: fclean all

phony: all clean fclean re ¡