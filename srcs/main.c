/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 16:54:59 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/04 03:36:41 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	pthread_t			thread;
	MLX_PTR				connector;
	MLX_WIN				win;
	t_image_frame		*frames;
	t_mem_block			*data;

	data = NULL;
	if (argc != 0 && argv)
	{
		if (!(connector = mlx_init()))
			ft_error_exit(1, (char*[]){MLX_INIT_ERROR}, EXIT_FAILURE);
		if (!(win = mlx_new_window(connector, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME)))
			ft_error_exit(1, (char*[]){MLX_NEW_WIN_ERROR}, EXIT_FAILURE);
		frames = ft_get_image_frames(connector, NBR_IMAGE_FRAME);
		if (pthread_create(&thread, NULL, &ft_pthread_frame_clear_routine, frames) ||
			pthread_create(&thread, NULL, &ft_pthread_frame_clear_routine, frames))
			ft_error_exit(1, (char*[]){ERR_PTHREAD_FAIL}, EXIT_FAILURE);
		ft_draw_fractal(connector, win, frames, MANDELBROT);
/* 		mlx_hook(win, KeyPress, KeyPressMask | KeymapStateMask */
/* 				, &ft_handler_keys, (void*[]){connector */
/* 				, win, frames, data}); */
/* 		mlx_hook(win, KeyRelease, KeyReleaseMask | KeymapStateMask */
/* 				, &ft_handler_keys_release, (void*[]){connector */
/* 				, win, frames, data}); */
		mlx_loop(connector);
	}

}
