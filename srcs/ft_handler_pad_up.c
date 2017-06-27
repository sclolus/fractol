/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_pad_up.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 06:49:50 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/27 07:26:11 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_handler_pad_up(void *param)
{
	t_mem_block	*data;
	t_mem_block	*tmp;
	uint32_t	i;

	data = ((t_mem_block**)param)[3];
	tmp = data;
	i = 0;
	while (i * sizeof(t_point) < tmp->offset)
	{
		((t_point*)tmp->block + i)->coords.x *= 1.03;
		((t_point*)tmp->block + i)->coords.z *= 1.03;
		((t_point*)tmp->block + i)->coords.y *= 1.03;
		i++;
		if (i * sizeof(t_point) >= tmp->offset && tmp->next && !(i = 0))
			tmp = tmp->next;
	}
	ft_draw_lines(((MLX_PTR)((char**)param)[0]), (MLX_PTR)((char**)param)[1]
		, (MLX_IMG)((char**)param)[2],(t_mem_block*)((t_mem_block**)param)[3]);
}
