# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/29 17:48:48 by mtaylor           #+#    #+#              #
#    Updated: 2019/10/29 17:48:55 by mtaylor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = clang++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = megaphone
SRC = main.cpp

all: $(NAME)
$(NAME):
	$(CXX) $(SRC)
#	$(CXX) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)
fclean: clean

re: fclean all
