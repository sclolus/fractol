/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 06:13:14 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/29 07:41:12 by sclolus          ###   ########.fr       */
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

# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

typedef void* t_mlx_win;
typedef void* t_mlx_img;
typedef void* t_mlx_ptr;

# define WINDOW_NAME "fractol"
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# define PI 3.14159265359
# define K 0.5
# define ANGLE 120

# define MOVE_COEFFICIENT 7
# define ROTATION_SPEED 9
# define ZOOM_RATIO 0.79
# define DEZOOM_RATIO 1.0 / ZOOM_RATIO

# define NBR_IMAGE_FRAME 1

# define STDIN_NOFILE 0

# define ABS(x) (x < 0 ? -x : x)

# define FRACTOL_USAGE "usage: ./fractol (\"mandelbrot\" | \"julia\")"

/*
** typedef struct	s_vec t_vec;
** typedef struct	s_color_set t_color_set;
** typedef struct	s_complexe t_complexe;
** typedef struct	s_pthread_execution_data t_pthread_execution_data;
** typedef struct	s_mlx_data t_mlx_data;
** typedef struct	s_fractal_data t_fractal_data;
** typedef struct	s_cl_execution_data t_cl_execution_data;
** typedef struct	s_complexe_cadran t_complexe_cadran;
** typedef struct	s_fractal_data t_fractal_data;
** typedef struct	s_win_coords t_win_coords;
** typedef struct	s_win_cadran t_win_cadran;
*/

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
	t_mlx_img		frame;
	void			*buffer;
	t_frame_state	state;
	int32_t			bits_per_pixel;
	int32_t			size_line;
	int32_t			endian;
}				t_image_frame;

typedef struct	s_mlx_data
{
	t_mlx_ptr		connector;
	t_mlx_win		win;
	t_image_frame	*frame;
}				t_mlx_data;

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
	void				(*f)(struct s_pthread_execution_data*);
	uint32_t			cadran;
	char				pad[4];
}				t_pthread_execution_data;

typedef struct	s_cl_execution_data
{
	cl_program			program;
	cl_kernel			kernel;
	cl_context			context;
	cl_command_queue	cmd_queue;
	cl_device_id		device_id;
	cl_mem				mem_obj;
}				t_cl_execution_data;

typedef void	(t_f_draw_fractal)(t_pthread_execution_data*);

typedef struct	s_fractal_data
{
	char				*name;
	char				*cl_filename;
	t_complexe			z0;
	t_complexe_cadran	c;
	t_f_draw_fractal	*f;
	void				(*cl_f)(t_mlx_data *, struct s_fractal_data *
								, t_cl_execution_data *);
	uint32_t			degree;
	uint32_t			iteration_number;
	uint8_t				tracking_mouse;
	uint8_t				pad[7];
}				t_fractal_data;

typedef void	(t_f_cl_draw_fractal)(t_mlx_data *, t_fractal_data *
										, t_cl_execution_data *);
typedef struct	s_quat
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_quat;

typedef enum	e_fractal_type
{
	MANDELBROT = 0,
	JULIA = 1,
	NEWTOWN = 2,
	BERYL = 3,
	BURNING_SHIP = 4,
	MULTIBROT = 5,
	SUPPORTED_FRACTAL_NBR,
}				t_fractal_type;

/*
** Mem_block handling
*/

# define MEM_BLOCK_LIMIT 256
# define DEFAULT_MEM_BLOCK_SIZE sizeof(t_point) * (100000)

void			*ft_mem_block_push_back_elem(t_mem_block *mem_block
									, void *elem, uint32_t size);
t_mem_block		*ft_create_mem_block(uint64_t capacity);

/*
** Frames handling
*/

t_image_frame	*ft_get_image_frames(t_mlx_ptr connector, uint32_t nbr_frames);
void			*ft_pthread_frame_clear_routine(void *arg);
t_image_frame	*ft_claim_image_frame(t_image_frame *frames);

/*
** Parsing
*/

# define HEXA_CHARSET "0123456789ABCDEF"
# define ERR_COLOR_NBR "Invalid number of color in color file"
# define ERR_COLOR_INVALID_FILE_SIZE "Invalid file size for color file"
# define ERR_INVALID_CHAR_COLOR_FILE "Invalid characters in color file"

t_fractal_type	ft_parse(char *fractal_name);

/*
** Fractals
*/

# define BASE_COLOR 0x110000
# define ITERATION_NUMBER 7

void			ft_draw_fractal(t_mlx_data *mlx_data
						, t_fractal_type fractal_type);

t_fractal_data	*ft_get_t_fractal_data(void);
void			ft_mandelbrot(t_pthread_execution_data *pthread_data);
void			ft_julia(t_pthread_execution_data *pthread_data);

/*
** Mouse tracking
*/

uint8_t			*ft_get_tracking_mouse_data(void);

/*
** Pthread drawing
*/

# define DRAWING_THREAD_NBR 7
# define ERR_PTHREAD_FAIL "pthread_create() failed"

pthread_t					*ft_pthread_create_drawing_threads(
				t_mlx_data *mlx_data
				, t_pthread_execution_data *pthread_data, t_f_draw_fractal *f);
void						ft_pthread_wait_drawing_threads(
							pthread_t *thread_tab);
void						*ft_pthread_draw_fractal_routine(void *arg);
t_pthread_execution_data	*ft_pthread_init_thread_execution_data(
								uint32_t thread_nbr
								, t_complexe_cadran complexe_cadran);
t_pthread_execution_data	*ft_get_t_pthread_execution_data(void);

/*
** Key handling
*/

# define NBR_KEY_HOOKS 15
# define FUCK_NORME " number provided in macro expansion"
# define INVALID_KEYS_HOOKS_NBR "Invalid keys_hooks" FUCK_NORME

int				ft_handler_keys(int keycode, void *param);
int				ft_handler_keys_release(int keycode
										, void * __attribute__((unused))param);
void			ft_handler_esc(void * __attribute__((unused))param);
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
void			ft_handler_t(void *param);
void			ft_handler_p(void *param);
void			ft_handler_2(void *param);
void			ft_handler_1(void *param);
void			ft_handler_5(void *param);
void			ft_handler_6(void *param);
void			ft_handler_4(void *param);
void			ft_handler_3(void *param);

/*
** Button handling
*/

# define NBR_BUTTON_HOOKS 2
# define INVALID_BUTTONS_HOOKS_NBR "Invalid buttons_hooks" FUCK_NORME

int				ft_handler_buttons(int keycode, int x, int y, void *param);
void			ft_handler_button5(int x, int y, void *param);
void			ft_handler_button4(int x, int y, void *param);

/*
** Mouse motion handling
*/

int				ft_handler_mouse_motion(int x, int y, void *param);
void			ft_handler_mouse_motion_julia(int x, int y, void *param);
void			ft_handler_mouse_motion_newtown(int x, int y, void *param);
void			ft_handler_mouse_motion_beryl(int x, int y, void *param);

/*
** Complexe numbers
*/

t_complexe		ft_square_complexe(t_complexe *z1);
t_complexe		ft_multiply_complexe(t_complexe *z1, t_complexe *z2);
t_complexe		ft_add_complexe(t_complexe *z1, t_complexe *z2);
double			ft_get_complexe_magnitude(t_complexe *z);
t_complexe		ft_pow_complexe(t_complexe *z, uint32_t degree);

/*
** Miscellaneous functions
*/

double			ft_double_distance(double a, double b);

/*
** Error handling
*/

# define INVALID_MEM_CAPACITY "Invalid capacity given to ft_create_mem_block()"
# define MALLOC_FAILURE "malloc() failed due to insufficient ressources left"
# define MLX_INIT_ERROR "mlx_init() failed"
# define MLX_NEW_WIN_ERROR "mlx_new_window() failed"
# define MLX_NEW_IMG_ERROR "mlx_new_image() failed"
# define MLX_IMG_FRAMES_ERROR "malloc() failed to alloc image frames"
# define OPEN_FILE_FAILED ": open() failed"
# define ERR_PARSE_COLOR_READ "read() failed"

void	ft_print_usage(void) __attribute__((noreturn));

/*
** OpenCL
*/

# define KERNEL_FLAGS "-cl-fast-relaxed-math -cl-no-signed-zeros -cl-mad-enable"

# define MANDELBROT_FILENAME "./test/mandelbrot.cl"
# define JULIA_FILENAME "./test/julia.cl"
# define NEWTOWN_FILENAME "./test/newtown.cl"
# define BERYL_FILENAME "./test/beryl.cl"
# define BURNING_SHIP_FILENAME "./test/burning_ship.cl"
# define MULTIBROT_FILENAME "./test/multibrot.cl"


# define CL_ERR_COMMAND_QUEUE "Creation of command queue failed"
# define CL_ERR_GET_DEVICE_IDS "clGetDeviceIDs() failed"
# define CL_ERR_GET_PLATFORMS_IDS "clGetPlatformsIDs() failed"
# define CL_ERR_CREATE_CONTEXT "clCreateContext() failed"
# define CL_ERR_CREATE_BUFFER "clCreateBuffer() failed"
# define CL_ERR_CREATE_PROGRAM_WITH_SOURCE "clCreateProgramWithSource() failed"
# define CL_ERR_BUILD_PROGRAM "clBuildProgram() failed"
# define CL_ERR_CREATE_KERNEL "clCreateKernel() failed"
# define CL_ERR_SET_ARG "clSetKernelArg() failed"
# define CL_ERR_KERNEL_LAUNCH "Kernel launch failed"

void				ft_draw_cl_fractal(t_mlx_data *mlx_data
						, t_fractal_type fractal_type);
void				ft_call_cl(t_mlx_data *mlx_data
						, t_fractal_type fractal_type);
t_cl_execution_data	*ft_get_cl_execution_data(t_fractal_type fractal_type);
cl_kernel			ft_get_cl_kernel(cl_program program, char *name
								, cl_device_id device_id);
cl_program			ft_get_cl_program_from_source(cl_context context
						, char *filename);
cl_mem				ft_get_cl_buffer(cl_context context
						, cl_mem_flags mem_flags, uint64_t size);
cl_command_queue	ft_get_cl_command_queue(cl_context context
						, cl_device_id device_id);
cl_context			ft_get_cl_context(cl_device_id device_id);
cl_device_id		ft_get_device_id(void);

/*
** Opencl Fractals
*/

void				ft_cl_mandelbrot(t_mlx_data *mlx_data
						, t_fractal_data *fractal_data
						, t_cl_execution_data *cl_data);
void				ft_cl_julia(t_mlx_data *mlx_data
						, t_fractal_data *fractal_data
						, t_cl_execution_data *cl_data);
void				ft_cl_newtown(t_mlx_data *mlx_data
						, t_fractal_data *fractal_data
						, t_cl_execution_data *cl_data);
void				ft_cl_beryl(t_mlx_data *mlx_data
						, t_fractal_data *fractal_data
						, t_cl_execution_data *cl_data);
void				ft_cl_burning_ship(t_mlx_data *mlx_data
						, t_fractal_data *fractal_data
						, t_cl_execution_data *cl_data);
void				ft_cl_multibrot(t_mlx_data *mlx_data
				, t_fractal_data *fractal_data
				, t_cl_execution_data *cl_data);


/*
** Screenshots
*/

# define RANDOM_FILE "/dev/urandom"
# define ERR_OPEN_SCREENSHOT "failed to open() screenshot file"
# define ERR_CLOSE_SCREENSHOT "failed to close() screenshot file"

# define SCREENSHOT_FILENAME_HEADER "fractol_screenshot_"

void			ft_create_screenshot(void *buffer, uint32_t width
									, uint32_t height);
void			ft_normalize_random_filename(char *filename);

#endif
