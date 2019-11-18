CXX = clang++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = a.out
SRC = *.cpp

all: $(NAME)
$(NAME):
	$(CXX) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)
fclean: clean

re: fclean all