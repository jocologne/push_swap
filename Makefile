NAME = push_swap
CC = cc
FLAGS = -Werror -Wall -Wextra
HDR = -I./

SRC = $(wildcard *.c)

OBJ_DIR = obj
OBJ = $(SRC:.c=.o)
OBJ_PATH = $(OBJ:%.o=$(OBJ_DIR)/%.o) 

all: $(NAME)

$(NAME): $(OBJ_PATH)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ_PATH) $(HDR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@ $(HDR)

clean:
	@rm -rf $(OBJ_PATH)
	@rm -rf $(OBJ_DIR)


fclean: clean
	@rm -rf $(NAME)

re: fclean all

e: all clean