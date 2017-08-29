/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_mouse_motion_julia.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 17:12:40 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/29 08:47:24 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_handler_mouse_motion_julia(int x, int y, void *param)
{
	t_fractal_data	*fractal_data;
	t_fractal_type	fractal_type;

	fractal_type = *((t_fractal_type*)((t_fractal_type**)param)[1]);
	fractal_data = ft_get_t_fractal_data();
	fractal_data[fractal_type].z0 = (t_complexe){(double)(x)
			* (fractal_data[fractal_type].c.max.real_part
			- fractal_data[fractal_type].c.min.real_part)
			/ (WINDOW_WIDTH) + fractal_data[fractal_type].c.min.real_part
		, (double)(y) * (fractal_data[fractal_type].c.max.imaginary_part
		- fractal_data[fractal_type].c.min.imaginary_part)
		/ (WINDOW_WIDTH) + fractal_data[fractal_type].c.min.imaginary_part};
	ft_draw_cl_fractal((t_mlx_data*)((t_mlx_data**)param)[0]
			, *((t_fractal_type*)((t_fractal_type**)param)[1]));
}
