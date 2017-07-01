/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color_interpolation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:54:27 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/01 16:59:31 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int32_t	ft_get_color_interpolation(t_line *line, t_vec *point)
{
	double	z1;
	double	z2;

	if (line->start.z < line->end.z)
	{
		z1 = line->start.z;
		z2 = line->end.z;
	}
	else
	{
		z1 = line->end.z;
		z2 = line->start.z;
	}
	return (ft_get_lerp(z1, z2, ft_get_z_coord(line, point)));
}
