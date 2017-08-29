/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 16:54:59 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/29 02:12:05 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static inline void	ft_set_mlx_hooks(t_mlx_data *mlx_data, void **params)
{
	mlx_hook(mlx_data->win, KEYPRESS, KEYPRESSMASK, &ft_handler_keys
		, params);
	mlx_hook(mlx_data->win, KEYRELEASE, KEYRELEASEMASK, &ft_handler_keys_release
		, params);
	mlx_hook(mlx_data->win, BUTTONPRESS, BUTTONPRESSMASK, &ft_handler_buttons
		, params);
	mlx_hook(mlx_data->win, MOTIONNOTIFY, 0, &ft_handler_mouse_motion
		, params);
}

int					main(int argc, char **argv)
{
	t_mlx_data			mlx_data;
	t_image_frame		*frames;
	t_mem_block			*data;
	t_fractal_type		fractal_type;

	data = NULL;
	if (argc == 2)
	{
		fractal_type = ft_parse(argv[1]);
		if (!(mlx_data.connector = mlx_init()))
			ft_error_exit(1, (char*[]){MLX_INIT_ERROR}, EXIT_FAILURE);
		if (!(mlx_data.win = mlx_new_window(mlx_data.connector, WINDOW_WIDTH
					, WINDOW_HEIGHT, WINDOW_NAME)))
			ft_error_exit(1, (char*[]){MLX_NEW_WIN_ERROR}, EXIT_FAILURE);
		frames = ft_get_image_frames(mlx_data.connector, NBR_IMAGE_FRAME);
		ft_draw_cl_fractal(&(t_mlx_data){mlx_data.connector
					, mlx_data.win, frames}, fractal_type);
		ft_set_mlx_hooks(&mlx_data, (void*[]){&(t_mlx_data){mlx_data.connector
						, mlx_data.win, frames}, &fractal_type});
		mlx_loop(mlx_data.connector);
	}
	else
		ft_print_usage();
	return (0);
}
