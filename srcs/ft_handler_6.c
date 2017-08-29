/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 07:33:52 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/29 07:37:12 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_handler_6(void *param)
{
	*((t_fractal_type*)((t_fractal_type**)param)[1]) = MULTIBROT;
	ft_draw_cl_fractal((t_mlx_data*)((t_mlx_data**)param)[0]
					, *((t_fractal_type*)((t_fractal_type**)param)[1]));
}
