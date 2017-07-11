/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_mouse_motion_julia.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 17:12:40 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/08 19:48:21 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_handler_mouse_motion_julia(int x, int y, void *param)
{
	ft_get_t_fractal_data()[JULIA].z0 = (t_complexe){(double)x / WINDOW_WIDTH - 1, (double)y / WINDOW_HEIGHT - 1};
	ft_draw_fractal((t_mlx_data*)((t_mlx_data**)param)[0], JULIA);
}
