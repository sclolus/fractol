/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_m.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 07:25:48 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/30 07:26:36 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_handler_m(void *param)
{
	*ft_get_render_mode() ^= 1;
	ft_draw_cl_fractal((t_mlx_data*)((t_mlx_data**)param)[0]
		, *((t_fractal_type*)((t_fractal_type**)param)[1]));
}
