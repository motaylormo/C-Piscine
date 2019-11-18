CXX = clang++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = iter
SRC = iter.cpp

all: $(NAME)
$(NAME):
	$(CXX) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)
fclean: clean

re: fclean all