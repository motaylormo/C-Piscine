CXX = clang++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = phonebook
SRC = main.cpp \
	Contactbook.class.cpp

all: $(NAME)
$(NAME):
	$(CXX) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)
fclean: clean

re: fclean all