/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:41:45 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/26 18:53:56 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_lines(t_mem_block *mem_block)
{
	t_mem_block	*tmp;
	uint64_t	offset;
	uint64_t	i;

	i = 0;
	offset = 0;
	tmp = mem_block;
	while ((i + 1) * sizeof(t_point) < mem_block->offset)
	{
		if (((t_point*)mem_block->block + i)->coords.y
			< (((t_point*)mem_block->block + i + 1))->coords.y)
		{
			i++;
			break ;
		}
		i++;
		if ((i) * sizeof(t_point) >= mem_block->offset
			&& mem_block->next)
		{
			mem_block = mem_block->next;
			i = 0;
		}
	}
	while ((i) * sizeof(t_point) < mem_block->offset)
	{
		((t_point*)tmp->block + offset)->line = ((t_point*)mem_block->block + i);
		offset++;
		i++;
		if (i * sizeof(t_point) >= mem_block->offset
			&& mem_block->next && !(i = 0))
			mem_block = mem_block->next;
		if (offset * sizeof(t_point) >= tmp->offset
			&& tmp->next && !(offset = 0))
			tmp = tmp->next;
	}
}
