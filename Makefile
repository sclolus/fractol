NAME= fractol
SRC= srcs/main.c \
	test/ft_test.c \
	srcs/parser/ft_parse.c \
	srcs/ft_print_usage.c \
	srcs/ft_create_mem_block.c \
	srcs/ft_mem_block_push_back_elem.c \
	srcs/ft_get_image_frames.c \
	srcs/ft_pthread_frame_clear_routine.c \
	srcs/ft_claim_frame.c \
	srcs/ft_pthread_wait_drawing_threads.c \
	srcs/ft_pthread_create_drawing_threads.c \
	srcs/ft_pthread_draw_fractal_routine.c \
	srcs/ft_get_t_pthread_execution_data.c \
	srcs/ft_pthread_init_thread_execution_data.c \
	srcs/ft_mandelbrot.c \
	srcs/ft_julia.c \
	srcs/ft_draw_fractal.c \
	srcs/ft_get_t_fractal_data.c \
	srcs/quaternions/ft_get_conjugate_quat.c \
	srcs/quaternions/ft_get_quat_magnitude.c \
	srcs/quaternions/ft_multiply_quat.c \
	srcs/quaternions/ft_normalize_quat.c \
	srcs/complexes/ft_multiply_complexe.c \
	srcs/complexes/ft_square_complexe.c \
	srcs/complexes/ft_add_complexe.c \
	srcs/complexes/ft_get_complexe_magnitude.c \
	srcs/complexes/ft_pow_complexe.c \
	srcs/ft_handler_keys.c \
	srcs/ft_handler_pad_up.c \
	srcs/ft_handler_pad_down.c \
	srcs/ft_handler_esc.c \
	srcs/ft_handler_right.c \
	srcs/ft_handler_left.c \
	srcs/ft_handler_buttons.c \
	srcs/ft_handler_button5.c \
	srcs/ft_handler_button4.c \
	srcs/ft_double_distance.c \
	srcs/ft_handler_mouse_motion.c \
	srcs/ft_handler_mouse_motion_julia.c \
#	srcs/ft_get_z_coord.c \
	srcs/quaternions/ft_quat_rotate_points.c \
	srcs/ft_get_color_interpolation.c \
	srcs/ft_get_lerp.c \
	srcs/ft_handler_up.c \
	srcs/ft_handler_down.c \
	srcs/ft_handler_q.c \
	srcs/ft_handler_e.c \
	srcs/ft_handler_a.c \
	srcs/ft_handler_d.c \
	srcs/ft_handler_s.c \
	srcs/ft_handler_w.c \

HDRS= includes/fractol.h
OBJ= $(SRC:.c=.o)
HDR_PATH= ./libft/includes/
CC= gcc
CC_FLAGS= -v -Weverything -Ofast -Wall -Werror -Wextra  -g3 -fsanitize=address -fsanitize-blacklist=my_ignores.txt
MLX_PATH=./minilibx_macos/
LIBFT_PATH=./libft/
FLAGS= -L$(MLX_PATH) -lmlx -L$(LIBFT_PATH) -lft -I$(HDR_PATH) -I./includes -I$(MLX_PATH)  -framework AppKit  -framework OpenCL

all: submodule $(NAME)

submodule:
#	@make -C minilibx_macos
	@make -C libft/

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $^ $(FLAGS) -o $(NAME)
%.o : %.c $(HDRS)
	$(CC) $(CC_FLAGS) $< -c -I$(HDR_PATH) -I./includes -I$(MLX_PATH) -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean
#	make -C $(MLX_PATH) clean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all
