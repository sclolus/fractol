/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_mouse_motion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 17:14:19 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/29 08:46:15 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_handler_mouse_motion(int x, int y, void *param)
{
	t_fractal_type	fractal_type;

	fractal_type = *((t_fractal_type*)((t_fractal_type**)param)[1]);
	if (ft_get_tracking_mouse_data()[fractal_type])
	{
		if (fractal_type == JULIA || fractal_type == MULTILIA)
			ft_handler_mouse_motion_julia(x, y, param);
		else if (fractal_type == NEWTOWN)
			ft_handler_mouse_motion_newtown(x, y, param);
		else if (fractal_type == BERYL)
			ft_handler_mouse_motion_beryl(x, y, param);
	}
	return (0);
}
