SRC = ./src/Logger.cpp

OBJ = $(SRC:.cpp=.o)

# Path: ./src

NAME = liblogger.a

CXX = g++

CXXFLAGS = -Wall -Wextra -Werror -std=c++17

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@mkdir -p ./include
	@cp src/Logger.hpp ./include/Logger.hpp
	@echo "\033[32m[OK] \033[0m\033[1m$(NAME)\033[0m"
	@echo "\033[32m[OK] \033[0m\033[1m./include/Logger.hpp\033[0m"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "\033[32m[OK] \033[0m\033[1m$@\033[0m"

clean:
	@rm -f $(OBJ)
	@echo "\033[31m[OK] \033[0m\033[1m$(OBJ)\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m[OK] \033[0m\033[1m$(NAME)\033[0m"

re: fclean all

install: all
	@sudo mkdir -p /usr/local/include
	@sudo cp -r ./include/Logger.hpp /usr/local/include/Logger.hpp
	@sudo cp -r ./liblogger.a /usr/local/lib/liblogger.a
	@echo "\033[32m[OK] \033[0m\033[1m/usr/local/include/Logger.hpp\033[0m"
	@echo "\033[32m[OK] \033[0m\033[1m/usr/local/lib/liblogger.a\033[0m"

.PHONY: all clean fclean re