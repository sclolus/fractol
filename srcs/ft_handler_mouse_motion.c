/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_mouse_motion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 17:14:19 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/08 17:19:35 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_handler_mouse_motion(int x, int y, void *param)
{
	if (*((t_fractal_type*)((t_fractal_type**)param)[1]) == JULIA)
		ft_handler_mouse_motion_julia(x, y, param);
	return (0);
}
