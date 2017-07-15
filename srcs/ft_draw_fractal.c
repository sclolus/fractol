/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fractal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 10:34:48 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/15 00:30:06 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw_fractal(t_mlx_data *mlx_data
						, t_fractal_type fractal_type)
{
/* 	static pthread_t					*thread_tab; */
/* 	static t_pthread_execution_data		*pthread_data = NULL; */
/* 	t_fractal_data						*fractals_data; */

/* 	fractals_data = ft_get_t_fractal_data(); */
/* 	pthread_data = ft_pthread_init_thread_execution_data(DRAWING_THREAD_NBR */
/* 					+ 1, fractals_data[fractal_type].c); */
/* 	thread_tab = ft_pthread_create_drawing_threads(mlx_data, pthread_data */
/* 												, fractals_data[fractal_type].f); */
/* 	fractals_data[fractal_type].f(pthread_data); */
/* 	ft_pthread_wait_drawing_threads(thread_tab); */
	ft_call_cl(mlx_data, fractal_type);
//	mlx_put_image_to_window(mlx_data->connector, mlx_data->win, mlx_data->frame->frame, 0, 0);
}
