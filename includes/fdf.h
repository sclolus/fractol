/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 16:55:51 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/27 16:03:20 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** DEBUG
*/

# define DEBUG 0

# define CHECK(x) do {ft_putendl_fd("_______", 2);ft_putendl_fd(#x, 2);ft_putendl_fd("_______", 2);}while(0);

# include <stdint.h>
# include "key_codes_macos.h"
# include "events.h"
# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h> //

typedef void* MLX_WIN;
typedef void* MLX_IMG;
typedef void* MLX_PTR;

# define WINDOW_NAME "fdf"
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# define PI 3.14159265359
# define K 0.5
# define ANGLE 120

# define MOVE_COEFFICIENT 10
# define ROTATION_SPEED 0.5

# define STDIN_NOFILE 0
typedef struct	s_mem_block
{
	uint64_t			capacity;
	uint64_t			offset;
	void				*block;
	struct s_mem_block	*next;
}				t_mem_block;

typedef struct	s_matrice
{
	double		x;
	double		y;
	double		z;
}				t_matrice;

typedef struct	s_point
{
	struct s_point		*line;
	t_matrice			coords;
}				t_point;

typedef struct	s_keycode_f
{
	void	(*f)();
	int		keycode;
	int32_t	used;
}				t_keycode_f;

typedef struct	s_mlx_data
{
	MLX_PTR	connector;
	MLX_WIN	win;
	MLX_IMG	image;
}				t_mlx_data;

typedef struct	s_mlx_image_data
{
	int32_t	bits_per_pixel;
	int32_t	size_line;
	int32_t	endian;
}				t_mlx_image_data;

typedef struct	s_vec
{
	double	x;
	double	y;
	double	z;
}				t_vec;

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
#define DEFAULT_MEM_BLOCK_SIZE sizeof(t_point) * (1000000)

void		*ft_mem_block_push_back_elem(t_mem_block *mem_block
									, void *elem, uint32_t size);
t_mem_block	*ft_create_mem_block(uint64_t capacity);
void		ft_set_lines(t_mem_block *mem_block);

/*
** Isometric Perspective
*/

void		ft_sus_perspective_angle(void);
void		ft_add_perspective_angle(void);
double		*ft_get_perspective_angle(void);

double		*ft_get_reduction_coefficient(void);
void		ft_sus_reduction_coefficient(void);
void		ft_add_reduction_coefficient(void);
/*
** Parsing
*/

t_mem_block	*ft_parse_file(char *filename);

/*
** Line drawing
*/

void		ft_set_3d(t_mem_block *data);
void		ft_draw_line(t_mlx_data *mlx_data, t_point *a, t_point *b);
void		ft_draw_lines(MLX_PTR connector, MLX_WIN win, MLX_IMG image
						, t_mem_block *data);
int			ft_draw_lines_hook(void *param);

/*
** Key handling
*/

# define NBR_KEY_HOOKS 13
# define INVALID_KEYS_HOOKS_NBR "Invalid keys_hooks number provided in macro expansion"

int			ft_handler_keys(int keycode, void *param);
int			ft_handler_keys_release(int keycode, void *param __attribute__((unused)));
void		ft_handler_esc(void *param __attribute__((unused)))
			__attribute__((noreturn));
void		ft_handler_right(void *param);
void		ft_handler_left(void *param);
void		ft_handler_down(void *param);
void		ft_handler_up(void *param);
void		ft_handler_pad_down(void *param);
void		ft_handler_pad_up(void *param);
void		ft_handler_q(void *param);
void		ft_handler_e(void *param);
void		ft_handler_w(void *param);
void		ft_handler_s(void *param);
void		ft_handler_d(void *param);
void		ft_handler_a(void *param);

/*
** Quaternions
*/

double		ft_get_quat_magnitude(t_quat *quat);
t_quat		ft_normalize_quat(t_quat *quat);
t_quat		ft_get_conjugate_quat(t_quat *quat);
t_quat		ft_multiply_quat(t_quat a, t_quat b);
void		ft_quat_rotate_points(t_vec *axis, double angle, t_mem_block *data);

/*
** Error handling
*/

# define INVALID_MEM_CAPACITY "Invalid capacity provided to ft_create_mem_block()"
# define MALLOC_FAILURE "malloc() failed due to insufficient ressources left"
# define MLX_INIT_ERROR "mlx_init() failed"
# define MLX_NEW_WIN_ERROR "mlx_new_window() failed"
# define MLX_NEW_IMG_ERROR "mlx_new_image() failed"
# define OPEN_FILE_FAILED "open() failed"
#endif
