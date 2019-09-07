# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twitting <twitting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 14:23:06 by twitting          #+#    #+#              #
#    Updated: 2019/09/07 16:12:45 by twitting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
SRC = ./src/main.c

LIBFT = ./libft/libft.a
OBJECTS = $(SRC:.c=.o)
WWW = -Wall -Wextra -Werror -Ofast
INCLUDES = -I libft -I includes/

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C libft/
	gcc -o $(NAME) $(OBJECTS) $(INCLUDES) $(LIBFT) 

%.o: %.c
	gcc $(WWW) $(INCLUDES) -c $< -o $@

clean:
	make clean -C libft/
	/bin/rm -f $(OBJECTS)

fclean: clean
	make fclean -C libft/
	/bin/rm -f $(NAME)

re: fclean all

