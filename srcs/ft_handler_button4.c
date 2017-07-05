/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_button4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 20:19:09 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/05 20:28:25 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_handler_button4(int x, int y, void *param)
{
	t_fractal_data	*fractal_data;
	t_fractal_type	fractal_type;
	double			c_x;
	double			c_y;

	fractal_data = ft_get_t_fractal_data();
	fractal_type = MANDELBROT;
	c_x = x * ((ft_double_distance(fractal_data[fractal_type].c.max.real_part
	, fractal_data[fractal_type].c.min.real_part)) / WINDOW_WIDTH) + fractal_data[fractal_type].c.min.real_part;
	c_y = y * ((ft_double_distance(fractal_data[fractal_type].c.max.imaginary_part
	, fractal_data[fractal_type].c.min.imaginary_part)) / WINDOW_HEIGHT) + fractal_data[fractal_type].c.min.imaginary_part;
	fractal_data[fractal_type].c.min.real_part = ((fractal_data[fractal_type].c.min.real_part - c_x) / DEZOOM_RATIO) + c_x;
	fractal_data[fractal_type].c.min.imaginary_part = (fractal_data[fractal_type].c.min.imaginary_part - c_y) / DEZOOM_RATIO + c_y;
	fractal_data[fractal_type].c.max.real_part = (fractal_data[fractal_type].c.max.real_part - c_x) / DEZOOM_RATIO + c_x;
	fractal_data[fractal_type].c.max.imaginary_part = (fractal_data[fractal_type].c.max.imaginary_part - c_y) / DEZOOM_RATIO + c_y;
	ft_draw_fractal((t_mlx_data*)((t_mlx_data**)param)[0], MANDELBROT);
}
