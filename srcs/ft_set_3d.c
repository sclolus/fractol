/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:47:41 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/03 06:21:45 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_3d(t_mem_block *data)
{
	double			k;
	double			angle;
	uint64_t		i;

	i = 0;
	k = *ft_get_reduction_coefficient();
	angle = *ft_get_perspective_angle();
	while ((i) * sizeof(t_point) < data->offset)
	{

		((t_point*)data->block + i)->coords.x += k * cos(angle) * ((t_point*)data->block + i)->coords.z;
		((t_point*)data->block + i)->coords.y += k * sin(angle) * ((t_point*)data->block + i)->coords.z;
		i++;
		if ((i) * sizeof(t_point) >= data->offset
			&& data->next)
		{
			data = data->next;
			i = 0;
		}
	}
}
