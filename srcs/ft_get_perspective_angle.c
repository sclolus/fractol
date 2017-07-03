/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_perspective_angle.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 07:37:56 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/03 06:21:45 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_sus_perspective_angle(void)
{
	*ft_get_perspective_angle() -= 0.2;
}

void	ft_add_perspective_angle(void)
{
	*ft_get_perspective_angle() += 0.2;
}

double	*ft_get_perspective_angle(void)
{
	static double	angle = ANGLE;

	return (&angle);
}
