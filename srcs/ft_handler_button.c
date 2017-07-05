/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_button.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 18:52:47 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/05 18:52:57 by sclolus          ###   ########.fr       */
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
	ft_draw_fractal((t_mlx_data*)((t_mlx_data**)param)[0], MANDELBROT);
}
