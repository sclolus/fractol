/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 04:45:36 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/30 01:42:33 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_handler_1(void *param)
{
	*((t_fractal_type*)((t_fractal_type**)param)[1]) = MANDELBROT;
	ft_draw_cl_fractal((t_mlx_data*)((t_mlx_data**)param)[0]
					, *((t_fractal_type*)((t_fractal_type**)param)[1]));
}
