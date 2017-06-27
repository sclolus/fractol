/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 23:20:15 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/27 06:47:58 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* int		ft_draw_lines_hook(void *param) */
/* { */
/* 	printf("1: %p\n 2: %p\n 3: %p\n", ((MLX_PTR)((char**)param)[0]), (MLX_PTR)((char**)param)[1], (void*)(t_mem_block*)((t_mem_block**)param)[2]); */
/* 	ft_draw_lines(((MLX_PTR)((char**)param)[0]), (MLX_PTR)((char**)param)[1], (t_mem_block*)((t_mem_block**)param)[2]); */
/* 	(void)param; */
/* 	printf("salut"); */
/* 	return (0); */
/* } */

void	ft_draw_lines(MLX_PTR connector, MLX_WIN win, MLX_IMG image,  t_mem_block *data)
{
	uint64_t	i;

	i = 0;
	while ((i + 1) * sizeof(t_point) < data->offset)
	{
		if (((t_point*)data->block + i)->coords.y >= ((t_point*)data->block + i + 1)->coords.y)
			ft_draw_line(&(t_mlx_data){connector, win, image}, ((t_point*)data->block + i), ((t_point*)data->block + i + 1));
		if (((t_point*)data->block + i)->line)
			ft_draw_line(&(t_mlx_data){connector, win, image}, ((t_point*)data->block + i), ((t_point*)data->block + i)->line);
		i++;
		if ((i + 1) * sizeof(t_point) >= data->offset
			&& data->next)
		{
			data = data->next;
			i = 0;
		}
	}
	mlx_put_image_to_window(connector, win, image, 0, 0);
	ft_bzero(mlx_get_data_addr(image, &(int){1}, &(int){1}, &(int){1}), WINDOW_HEIGHT * WINDOW_WIDTH * 4);

}
