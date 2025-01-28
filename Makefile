NAME = push_swap
CC = cc
FLAGS = -Werror -Wall -Wextra
HDR = -I./

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(HDR)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@ $(HDR)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

noflag:
	@$(CC) -c $(SRC) $(HDR)
	@$(CC) -o $(NAME) $(OBJ) $(HDR)