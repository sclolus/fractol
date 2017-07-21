/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 09:38:25 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/21 09:39:21 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_handler_4(void *param)
{
	*((t_fractal_type*)((t_fractal_type**)param)[1]) = BERYL;
	ft_draw_cl_fractal((t_mlx_data*)((t_mlx_data**)param)[0]
					, *((t_fractal_type*)((t_fractal_type**)param)[1]));
}
