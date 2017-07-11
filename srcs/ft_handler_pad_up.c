/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_pad_up.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 06:49:50 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/08 17:22:34 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_handler_pad_up(void *param)
{
	t_fractal_data	*fractal_data;
	t_fractal_type	fractal_type;

	fractal_data = ft_get_t_fractal_data();
	fractal_type = MANDELBROT;

	fractal_data[fractal_type].c.min.real_part *= DEZOOM_RATIO;
	fractal_data[fractal_type].c.min.imaginary_part *= DEZOOM_RATIO;
	fractal_data[fractal_type].c.max.real_part *= DEZOOM_RATIO;
	fractal_data[fractal_type].c.max.imaginary_part *= DEZOOM_RATIO;
	ft_draw_fractal((t_mlx_data*)((t_mlx_data**)param)[0]
					, *((t_fractal_type*)((t_fractal_type**)param)[1]));
}
