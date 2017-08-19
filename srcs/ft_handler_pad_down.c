/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_pad_down.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 06:51:08 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/19 06:35:49 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_handler_pad_down(void *param)
{
	t_fractal_data	*fractal_data;
	t_fractal_type	fractal_type;

	fractal_data = ft_get_t_fractal_data();
	fractal_type = *((t_fractal_type*)((t_fractal_type**)param)[1]);
	fractal_data[fractal_type].c.min.real_part *= ZOOM_RATIO;
	fractal_data[fractal_type].c.min.imaginary_part *= ZOOM_RATIO;
	fractal_data[fractal_type].c.max.real_part *= ZOOM_RATIO;
	fractal_data[fractal_type].c.max.imaginary_part *= ZOOM_RATIO;
	ft_draw_fractal((t_mlx_data*)((t_mlx_data**)param)[0]
					, *((t_fractal_type*)((t_fractal_type**)param)[1]));
}
