/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 23:10:15 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/05 17:52:37 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_handler_left(void *param)
{
	t_fractal_data	*fractal_data;
	t_fractal_type	fractal_type;

	fractal_data = ft_get_t_fractal_data();
	fractal_type = MANDELBROT;

	fractal_data[fractal_type].c.min.real_part -= 0.01;
	fractal_data[fractal_type].c.max.real_part -= 0.01;
	ft_draw_fractal((t_mlx_data*)((t_mlx_data**)param)[0], MANDELBROT);
}
