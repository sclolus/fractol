/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fractal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 10:34:48 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/04 03:46:45 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw_fractal(MLX_PTR connector, MLX_WIN win, t_image_frame *frame
						, t_fractal_type fractal_type)
{
	static pthread_t					*thread_tab;
	static t_pthread_execution_data		*pthread_data = NULL;
	static t_fractal_data				fractals_data[SUPPORTED_FRACTAL_NBR] = {
		{{0, 0}, {{-2, -1}, {1, 1}}, *ft_mandelbrot, 2, {0}}};

	if (!pthread_data)
		pthread_data = ft_pthread_init_thread_execution_data(DRAWING_THREAD_NBR
		+ 1, fractals_data[fractal_type].c);
	thread_tab = ft_pthread_create_drawing_threads(&(t_mlx_data){connector
				, win, frame}, pthread_data, fractals_data[fractal_type].f);
	fractals_data[fractal_type].f(pthread_data);
/* 	ft_mandelbrot(&(t_pthread_execution_data){{connector, win, frame}, NULL, 0 */
/* 				, {0}}); */
	ft_pthread_wait_drawing_threads(thread_tab);
	mlx_put_image_to_window(connector, win, frame->frame, 0, 0);
}
