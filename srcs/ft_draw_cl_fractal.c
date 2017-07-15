/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_cl_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 22:35:31 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/15 22:36:02 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw_cl_fractal(t_mlx_data *mlx_data
						, t_fractal_type fractal_type)
{
	ft_call_cl(mlx_data, fractal_type);
}
