/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_button5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 20:08:01 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/16 08:40:08 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_handler_button5(int x, int y, void *param)
{
	t_fractal_data	*fractal_data;
	t_fractal_type	fractal_type;
	double			c_x;
	double			c_y;

	fractal_data = ft_get_t_fractal_data();
	fractal_type = *((t_fractal_type*)((t_fractal_type**)param)[1]);
	c_x = x * ((ft_double_distance(fractal_data[fractal_type].c.max.real_part
								   , fractal_data[fractal_type].c.min.real_part)) / WINDOW_WIDTH) + fractal_data[fractal_type].c.min.real_part;
	c_y = y * ((ft_double_distance(fractal_data[fractal_type].c.max.imaginary_part
								   , fractal_data[fractal_type].c.min.imaginary_part)) / WINDOW_HEIGHT) + fractal_data[fractal_type].c.min.imaginary_part;
	fractal_data[fractal_type].c.min.real_part = ((fractal_data[fractal_type].c.min.real_part - c_x) * ZOOM_RATIO) + c_x;
	fractal_data[fractal_type].c.min.imaginary_part = ((fractal_data[fractal_type].c.min.imaginary_part - c_y) * ZOOM_RATIO) + c_y;
	fractal_data[fractal_type].c.max.real_part = ((fractal_data[fractal_type].c.max.real_part - c_x) * ZOOM_RATIO) + c_x;
	fractal_data[fractal_type].c.max.imaginary_part = ((fractal_data[fractal_type].c.max.imaginary_part - c_y) * ZOOM_RATIO) + c_y;
	fractal_data[fractal_type].iteration_number += log2(fractal_data[fractal_type].iteration_number) + 1;
	ft_draw_cl_fractal((t_mlx_data*)((t_mlx_data**)param)[0]
					, *((t_fractal_type*)((t_fractal_type**)param)[1]));
}
