/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:47:41 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/26 18:07:19 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_3d(t_mem_block *data)
{
	uint64_t	i;

	i = 0;
	while ((i) * sizeof(t_point) < data->offset)
	{

		((t_point*)data->block + i)->coords.x += K * cos(ANGLE) * ((t_point*)data->block + i)->coords.y;
		((t_point*)data->block + i)->coords.z += K * sin(ANGLE) * ((t_point*)data->block + i)->coords.y;
		i++;
		if ((i) * sizeof(t_point) >= data->offset
			&& data->next)
		{
			data = data->next;
			i = 0;
		}
	}
}
