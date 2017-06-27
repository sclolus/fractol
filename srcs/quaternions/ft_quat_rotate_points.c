/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quat_rotate_points.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 09:21:26 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/27 09:29:10 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_quat_rotate_points(t_vec *axis, double angle, t_mem_block *data)
{
	t_quat	rotation_quat;
	t_quat	rotation_quat_prime;
	t_quat	view_quat;

	i = 0;
	rotation_quat.x = axis.x * sin(angle / 2);
	rotation_quat.y = axis.y * sin(angle / 2);
	rotation_quat.z = axis.z * sin(angle / 2);
	rotation_quat.w = cos(angle / 2);
	rotation_quat_prim = ft_get_conjugate_quat(&rotation_quat);
	while ((i) * sizeof(t_point) < data->offset)
	{
		view_quat = (t_quat)((t_point*)data->block + i);
		((t_point*)data->block + i) = (t_vec)ft_multiply_quat(ft_multiply_quat(
									&rotation_quat, &view_quat), rotation_quat_prim);
		i++;
		if ((i) * sizeof(t_point) >= data->offset
			&& data->next)
		{
			data = data->next;
			i = 0;
		}
	}
}
