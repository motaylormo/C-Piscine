# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phtruong <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/26 09:50:26 by phtruong          #+#    #+#              #
#    Updated: 2019/10/27 20:55:54 by phtruong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= ft_retro
CC		:= clang++
FLAGS	:= -std=c++98 -Wall -Wextra -Werror

FILES	:= main.cpp \
			Game.class.cpp \
			Entity.class.cpp \
			Enemy.class.cpp \
			Bullet.class.cpp \
			staticScenery.cpp
OBJ		:= $(FILES:.cpp=.o)

all		: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -lncurses -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean	:
	rm -rf $(OBJ)

fclean	: clean
	rm -rf $(NAME)

re		: fclean all

.PHONY: all, clean, fclean, re
