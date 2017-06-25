NAME= fdf
SRC= main.c
OBJ= $(SRC:.c=.o)
HDR_PATH= ./libft/includes/
CC= gcc
CC_FLAGS= -Weverything -Wall -Werror -Wextra -g3 -fsanitize=address -fsanitize_blacklist=my_ignores.txt
MLX_PATH=./minilibx_macos/
LIBFT_PATH=./libft/
FLAGS= -L$(MLX_PATH) -lmlx -L$(LIBFT_PATH) -lft -I$(HDR_PATH) -I./includes -I$(MLX_PATH)

all: submodule $(NAME)

submodule:
	@make -C minilibx_macos
	@make -C libft/

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $^ $(FLAGS) -o $(NAME)
%.o : %.c
	$(CC) $(CC_FLAGS) $< -c -I$(FLAGS) -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean
	make -C $(MLX_PATH) fclean

re: fclean all
