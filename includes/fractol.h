/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 06:13:14 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/05 20:25:42 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** DEBUG
*/

# define DEBUG 0

# define CHECK(x) do {ft_putendl_fd("_______", 2);ft_putendl_fd(#x, 2);ft_putendl_fd("_______", 2);}while(0);

# include <stdint.h>
# include <unistd.h>
# include "key_codes_macos.h"
# include "events.h"
# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <pthread.h>
# include <math.h>
# include <stdio.h> //

typedef void* MLX_WIN;
typedef void* MLX_IMG;
typedef void* MLX_PTR;

# define WINDOW_NAME "fractol"
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800

# define PI 3.14159265359
# define K 0.5
# define ANGLE 120

# define MOVE_COEFFICIENT 7
# define ROTATION_SPEED 9
# define ZOOM_RATIO 0.8
# define DEZOOM_RATIO 1 / ZOOM_RATIO

# define NBR_IMAGE_FRAME 32

# define STDIN_NOFILE 0

# define ABS(x) (x < 0 ? -x : x)

typedef struct	s_vec t_vec;
typedef struct	s_color_set t_color_set;
typedef struct	s_complexe t_complexe;
typedef struct	s_pthread_execution_data t_pthread_execution_data;
typedef			void (f_draw_fractal)(t_pthread_execution_data*);
typedef struct	s_complexe_cadran t_complexe_cadran;
typedef struct	s_fractal_data t_fractal_data;
typedef struct	s_win_coords t_win_coords;
typedef struct	s_win_cadran t_win_cadran;

typedef struct	s_complexe
{
	double	real_part;
	double	imaginary_part;
}				t_complexe;

typedef struct	s_complexe_cadran
{
	t_complexe	min;
	t_complexe	max;
}				t_complexe_cadran;

typedef struct	s_mem_block
{
	uint64_t			capacity;
	uint64_t			offset;
	void				*block;
	struct s_mem_block	*next;
}				t_mem_block;

typedef struct	s_vec
{
	double	x;
	double	y;
	double	z;
}				t_vec;

typedef struct	s_point
{
	t_vec				coords;
	int					color;
	char				pad[4];
}				t_point;

typedef struct	s_keycode_f
{
	void	(*f)();
	int		keycode;
	int32_t	used;
}				t_keycode_f;

typedef enum	e_frame_state
{
	ERR = 0,
	USED = 1,
	TO_CLEAR = 2,
	AVAILABLE = 3,
	CLEARING = 4,
}				t_frame_state;

typedef struct	s_image_frame
{
	MLX_IMG			frame;
	void			*buffer;
	t_frame_state	state;
	int32_t			bits_per_pixel;
	int32_t			size_line;
	int32_t			endian;
}				t_image_frame;

typedef struct	s_mlx_data
{
	MLX_PTR			connector;
	MLX_WIN			win;
	t_image_frame	*frame;
}				t_mlx_data;

typedef struct	s_quat
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_quat;


/*
** Mem_block handling
*/

#define MEM_BLOCK_LIMIT 256
#define DEFAULT_MEM_BLOCK_SIZE sizeof(t_point) * (100000)

void			*ft_mem_block_push_back_elem(t_mem_block *mem_block
									, void *elem, uint32_t size);
t_mem_block		*ft_create_mem_block(uint64_t capacity);
t_mem_block		*ft_set_lines(t_mem_block *mem_block);

/*
** Frames handling
*/

t_image_frame	*ft_get_image_frames(MLX_PTR connector, uint32_t nbr_frames);
void			*ft_pthread_frame_clear_routine(void *arg);
t_image_frame	*ft_claim_image_frame(t_image_frame *frames);

/*
** Isometric Perspective
*/

void			ft_sus_perspective_angle(void);
void			ft_add_perspective_angle(void);
double			*ft_get_perspective_angle(void);

double			*ft_get_reduction_coefficient(void);
void			ft_sus_reduction_coefficient(void);
void			ft_add_reduction_coefficient(void);

/*
** Parsing
*/

# define HEXA_CHARSET "0123456789ABCDEF"
# define ERR_COLOR_NBR "Invalid number of color in color file"
# define ERR_COLOR_INVALID_FILE_SIZE "Invalid file size for color file"
# define ERR_INVALID_CHAR_COLOR_FILE "Invalid characters in color file"

t_mem_block		*ft_parse_file(char *filename, char *filename_color);
t_color_set		ft_parse_color(char *filename_color);

/*
** Fractals
*/

# define BASE_COLOR 0x101010
# define ITERATION_NUMBER 1024

typedef enum	e_fractal_type
{
	MANDELBROT = 0,
	SUPPORTED_FRACTAL_NBR,
}				t_fractal_type;

typedef struct	s_fractal_data
{
	t_complexe			z0;
	t_complexe_cadran	c;
	f_draw_fractal		*f;
	uint32_t			degree;
	char				pad[4];
}				t_fractal_data;

void			ft_draw_fractal(t_mlx_data *mlx_data
						, t_fractal_type fractal_type);

t_fractal_data	*ft_get_t_fractal_data(void);
void			ft_mandelbrot(t_pthread_execution_data *pthread_data);

/*
** Pthread drawing
*/

# define DRAWING_THREAD_NBR 7
# define ERR_PTHREAD_FAIL "pthread_create() failed"

typedef struct	s_win_coords
{
	uint32_t	x;
	uint32_t	y;
}				t_win_coords;

typedef struct	s_win_cadran
{
	t_win_coords	min;
	t_win_coords	max;
}				t_win_cadran;

typedef struct	s_pthread_execution_data
{
	t_mlx_data			mlx_data;
	t_win_cadran		win_cadran;
	t_complexe_cadran	complexe_cadran;
	t_complexe			c_augmentation_rate;
	f_draw_fractal		*f;
	uint32_t			cadran;
	char				pad[4];
}				t_pthread_execution_data;

pthread_t					*ft_pthread_create_drawing_threads(t_mlx_data *mlx_data
							, t_pthread_execution_data *pthread_data, f_draw_fractal *f);
void						ft_pthread_wait_drawing_threads(pthread_t *thread_tab);
void						*ft_pthread_draw_fractal_routine(void *arg);
t_pthread_execution_data	*ft_pthread_init_thread_execution_data(uint32_t thread_nbr
								, t_complexe_cadran complexe_cadran);
t_pthread_execution_data	*ft_get_t_pthread_execution_data(void);

/*
** Key handling
*/

# define NBR_KEY_HOOKS 5
# define INVALID_KEYS_HOOKS_NBR "Invalid keys_hooks number provided in macro expansion"

int				ft_handler_keys(int keycode, void *param);
int				ft_handler_keys_release(int keycode, void *param __attribute__((unused)));
void			ft_handler_esc(void *param __attribute__((unused)))
				__attribute__((noreturn));
void			ft_handler_right(void *param);
void			ft_handler_left(void *param);
void			ft_handler_down(void *param);
void			ft_handler_up(void *param);
void			ft_handler_pad_down(void *param);
void			ft_handler_pad_up(void *param);
void			ft_handler_q(void *param);
void			ft_handler_e(void *param);
void			ft_handler_w(void *param);
void			ft_handler_s(void *param);
void			ft_handler_d(void *param);
void			ft_handler_a(void *param);

/*
** Button handling
*/

# define NBR_BUTTON_HOOKS 2
# define INVALID_BUTTONS_HOOKS_NBR "Invalid buttons_hooks number provided in macro expansion"

int				ft_handler_buttons_release(int keycode, void *param __attribute__((unused)));
int				ft_handler_buttons(int keycode, int x, int y, void *param);
void			ft_handler_button5(int x, int y, void *param);
void			ft_handler_button4(int x, int y, void *param);

/*
** Quaternions
*/

double			ft_get_quat_magnitude(t_quat *quat);
t_quat			ft_normalize_quat(t_quat *quat);
t_quat			ft_get_conjugate_quat(t_quat *quat);
t_quat			ft_multiply_quat(t_quat a, t_quat b);
void			ft_quat_rotate_points(t_vec *axis, double angle, t_mem_block *data);

/*
** Complexe numbers
*/

t_complexe	ft_square_complexe(t_complexe *z1);
t_complexe	ft_multiply_complexe(t_complexe *z1, t_complexe *z2);
t_complexe	ft_add_complexe(t_complexe *z1, t_complexe *z2);
double		ft_get_complexe_magnitude(t_complexe *z);

/*
** Miscellaneous functions
*/

double		ft_double_distance(double a, double b);

/*
** Interpolation
*/
/*
# define COLOR_MIN_Z 0xF00000
# define COLOR_MAX_Z 0xFFFFFF

typedef struct	s_color_set
{
	int	color_min;
	int	color_max;
}				t_color_set;

int32_t			ft_get_color_interpolation(t_line *line, t_vec *point);
double			ft_get_z_coord(t_line *line, t_vec *point);
int32_t			ft_get_lerp(double z1, double z2
				, double z, t_color_set color_set);
*/
/*
** Error handling
*/

# define INVALID_MEM_CAPACITY "Invalid capacity provided to ft_create_mem_block()"
# define MALLOC_FAILURE "malloc() failed due to insufficient ressources left"
# define MLX_INIT_ERROR "mlx_init() failed"
# define MLX_NEW_WIN_ERROR "mlx_new_window() failed"
# define MLX_NEW_IMG_ERROR "mlx_new_image() failed"
# define MLX_IMG_FRAMES_ERROR "malloc() failed to alloc image frames"
# define OPEN_FILE_FAILED ": open() failed"
# define ERR_PARSE_COLOR_READ "read() failed"

#endif
