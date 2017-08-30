/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 04:46:56 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/30 01:42:36 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_handler_2(void *param)
{
	*((t_fractal_type*)((t_fractal_type**)param)[1]) = JULIA;
	ft_draw_cl_fractal((t_mlx_data*)((t_mlx_data**)param)[0]
					, *((t_fractal_type*)((t_fractal_type**)param)[1]));
}
