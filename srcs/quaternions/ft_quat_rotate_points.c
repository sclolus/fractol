/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quat_rotate_points.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 09:21:26 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/27 12:14:54 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_quat_rotate_points(t_vec *axis, double angle, t_mem_block *data)
{
	t_quat		rotation_quat;
	t_quat		rotation_quat_prime;
	t_quat		view_quat;
	t_quat		tmp_quat;
	uint64_t	i;

	i = 0;
	rotation_quat.x = axis->x * sin(angle / 2);
	rotation_quat.y = axis->y * sin(angle / 2);
	rotation_quat.z = axis->z * sin(angle / 2);
	rotation_quat.w = cos(angle / 2);
	rotation_quat = ft_normalize_quat(&rotation_quat);
	rotation_quat_prime = ft_get_conjugate_quat(&rotation_quat);
	while ((i) * sizeof(t_point) < data->offset)
	{
		ft_memcpy(&view_quat, &((t_point*)data->block + i)->coords, sizeof(t_matrice));
		view_quat.w = 0;
		tmp_quat = ft_multiply_quat(ft_multiply_quat(
					rotation_quat, view_quat), rotation_quat_prime);
		ft_memcpy(&((t_point*)data->block + i)->coords, &tmp_quat, sizeof(t_matrice));
//		((t_point*)data->block + i)->coords = (t_matrice)tmp_quat;
		i++;
		if ((i) * sizeof(t_point) >= data->offset
			&& data->next)
		{
			data = data->next;
			i = 0;
		}
	}
}
