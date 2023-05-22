## /$$$$$$             /$$     /$$      /$$                       ##
##|_  $$_/            | $$    | $$$    /$$$                       ##
##  | $$   /$$$$$$$  /$$$$$$  | $$$$  /$$$$  /$$$$$$  /$$   /$$   ##
##  | $$  | $$__  $$|_  $$_/  | $$ $$/$$ $$ |____  $$|  $$ /$$/   ##
##  | $$  | $$  \ $$  | $$    | $$  $$$| $$  /$$$$$$$ \  $$$$/    ##
##  | $$  | $$  | $$  | $$ /$$| $$\  $ | $$ /$$__  $$  >$$  $$    ##
## /$$$$$$| $$  | $$  |  $$$$/| $$ \/  | $$|  $$$$$$$ /$$/\  $$   ##
##|______/|__/  |__/   \___/  |__/     |__/ \_______/|__/  \__/   ##
##
## @file: Makefile                  @author: IntMaxOddity       

NAME = IMChecker

CC = c++

SRC = checker.cpp \
		print.cpp \
		utils.cpp \
		execPhilo.cpp \
		parsing.cpp

OBJ = $(SRC:%.cpp=%.o)

%.o: %.c
	@$(CC) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(OBJ)  -o $(NAME)
	@echo "\033[4;32m--- executable created ---\n\033[0m"
	@rm -rf $(OBJ)

all: $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[4;35m--- all creations have been deleted ---\n\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus