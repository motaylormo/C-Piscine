CXX = clang++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = a.out
SRC = *.cpp

all: $(NAME)
$(NAME):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)
fclean: clean

re: fclean all