/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 16:54:59 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/11 06:39:33 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
//	pthread_t			thread;
/* 	MLX_PTR				connector; */
/* 	MLX_WIN				win; */
/* 	t_image_frame		*frames; */
/* 	t_mem_block			*data; */
/* 	t_fractal_type		fractal_type; */

/* 	data = NULL; */
/* 	if (argc == 2 && argv) */
/* 	{ */
/* 		fractal_type = ft_parse(argv[1]); */
/* 		if (!(connector = mlx_init())) */
/* 			ft_error_exit(1, (char*[]){MLX_INIT_ERROR}, EXIT_FAILURE); */
/* 		if (!(win = mlx_new_window(connector, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME))) */
/* 			ft_error_exit(1, (char*[]){MLX_NEW_WIN_ERROR}, EXIT_FAILURE); */
/* 		frames = ft_get_image_frames(connector, NBR_IMAGE_FRAME); */
/* 		ft_draw_fractal(&(t_mlx_data){connector, win, frames}, fractal_type); */
/* 		mlx_hook(win, KeyPress, KeyPressMask | KeymapStateMask */
/* 				 , &ft_handler_keys, (void*[]){&(t_mlx_data){connector, win, frames}, &fractal_type}); */
/* 		mlx_hook(win, ButtonPress, KeyPressMask | KeymapStateMask */
/* 				, &ft_handler_buttons, (void*[]){&(t_mlx_data){connector, win, frames}, &fractal_type}); */
/* 		mlx_hook(win, KeyRelease, KeyReleaseMask | KeymapStateMask */
/* 				, &ft_handler_keys_release, (void*[]){&(t_mlx_data){connector, win, frames}, &fractal_type}); */
/* 		mlx_hook(win, ButtonRelease, KeyReleaseMask | KeymapStateMask */
/* 				, &ft_handler_buttons_release, (void*[]){&(t_mlx_data){connector, win, frames}, &fractal_type}); */
/* 		mlx_hook(win, MotionNotify, 0, &ft_handler_mouse_motion, (void*[]){&(t_mlx_data){connector, win, frames}, &fractal_type}); */
/* 		mlx_loop(connector); */
/* 	} */
/* 	else */
/* 		ft_print_usage(); */
	ft_test(argc, argv);
	return (0);
}
