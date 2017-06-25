/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 16:54:59 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/25 22:39:11 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h> //

static void	ft_put_points(t_mem_block *data)
{
	uint64_t	i;

	i = 0;
	while (i * sizeof(t_point) < data->offset)
	{
		printf("[%lld, %lld, %lld]\t", (((t_point*)data->block) + i)->coords.x
		, (((t_point*)data->block) + i)->coords.y, (((t_point*)data->block) + i)->coords.z);
		i++;
		if ((((t_point*)data->block) + i)->coords.y
			!= (((t_point*)data->block) + i - 1)->coords.y)
			printf("\n");
	}
}

int	main(int argc, char **argv)
{
	MLX_PTR		connector;
	MLX_WIN		win;
	MLX_IMG		image;
	t_mem_block	*data;

	if (argc != 0 && argv)
	{
		data = ft_parse_file(argv[1]);
		ft_put_points(data);
		if (!(connector = mlx_init()))
			ft_error_exit(1, (char*[]){MLX_INIT_ERROR}, EXIT_FAILURE);
		if (!(win = mlx_new_window(connector, 1920, 1080, WINDOW_NAME)))
			ft_error_exit(1, (char*[]){MLX_NEW_WIN_ERROR}, EXIT_FAILURE);
		if (!(image = mlx_new_image(connector, 1920, 1080)))
			ft_error_exit(1, (char*[]){MLX_NEW_IMG_ERROR}, EXIT_FAILURE);
	}
//	return (0);
}
