/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fractal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 10:34:48 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/03 23:38:18 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw_fractal(MLX_PTR connector, MLX_WIN win, t_image_frame *frame)
{
	static pthread_t	*thread_tab;

	thread_tab = ft_pthread_create_drawing_threads(&(t_mlx_data){connector
				, win, frame}, *ft_mandelbrot);
	ft_mandelbrot(&(t_pthread_execution_data){{connector, win, frame}, NULL, 0, {0}});
	ft_pthread_wait_drawing_threads(thread_tab);
	mlx_put_image_to_window(connector, win, frame->frame, 0, 0);
}
