/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_mouse_motion_julia.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 17:12:40 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/20 07:34:03 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_handler_mouse_motion_julia(int x, int y, void *param)
{
	t_fractal_data	*fractal_data;
	t_complexe			coefficient;

	fractal_data = ft_get_t_fractal_data();
	coefficient = (t_complexe){ft_double_distance(fractal_data[JULIA].c.min.real_part
		, fractal_data[JULIA].c.max.real_part), ft_double_distance(fractal_data[JULIA].c.min.imaginary_part
		, fractal_data[JULIA].c.max.imaginary_part)};
	ft_get_t_fractal_data()[JULIA].z0 = (t_complexe){(double)(x) / WINDOW_WIDTH - 1, (double)(y)  / WINDOW_HEIGHT - 1};
	ft_draw_cl_fractal((t_mlx_data*)((t_mlx_data**)param)[0]
					, *((t_fractal_type*)((t_fractal_type**)param)[1]));
}
