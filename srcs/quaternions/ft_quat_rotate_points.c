/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quat_rotate_points.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 09:21:26 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/03 06:21:45 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	rotation_quat_prime = ft_get_conjugate_quat(&rotation_quat);
	while ((i) * sizeof(t_line) < data->offset)
	{
		ft_memcpy(&view_quat, &((t_line*)data->block + i)->start, sizeof(t_vec));
		view_quat.w = 0;
		tmp_quat = ft_multiply_quat(ft_multiply_quat(
					rotation_quat, view_quat), rotation_quat_prime);
		ft_memcpy(&((t_line*)data->block + i)->start, &tmp_quat, sizeof(t_vec));
		ft_memcpy(&view_quat, &((t_line*)data->block + i)->end, sizeof(t_vec));
		view_quat.w = 0;
		tmp_quat = ft_multiply_quat(ft_multiply_quat(
					rotation_quat, view_quat), rotation_quat_prime);
		ft_memcpy(&((t_line*)data->block + i)->end, &tmp_quat, sizeof(t_vec));
		((t_line*)data->block + i)->dx = ((t_line*)data->block + i)->start.x - ((t_line*)data->block + i)->end.x;
		((t_line*)data->block + i)->dy = ((t_line*)data->block + i)->start.y - ((t_line*)data->block + i)->end.y;
		((t_line*)data->block + i)->e = ((t_line*)data->block + i)->dy / ((t_line*)data->block + i)->dx;
		i++;
		if ((i) * sizeof(t_line) >= data->offset
			&& data->next)
		{
			data = data->next;
			i = 0;
		}
	}
}
