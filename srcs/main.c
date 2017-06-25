/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 16:54:59 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/25 23:20:00 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h> //

# if DEBUG == 1
static void	ft_put_points(t_mem_block *data)
{
	uint64_t	i;

	i = 0;
	while (i * sizeof(t_point) < data->offset)
	{
		printf("[%lld, %lld, %lld]\t", (((t_point*)data->block) + i)->coords.x
		, (((t_point*)data->block) + i)->coords.y, (((t_point*)data->block) + i)->coords.z);
		i++;
		if (i * sizeof(t_point) < data->offset && (((t_point*)data->block) + i)->coords.y
			!= (((t_point*)data->block) + i - 1)->coords.y)
			printf("\n");
		if (i * sizeof(t_point) >= data->offset)
		{
			if (data->next)
			{
				data = data->next;
				i = 0;
			}
		}
	}
}
# endif

int	main(int argc, char **argv)
{
	MLX_PTR		connector;
	MLX_WIN		win;
	MLX_IMG		image;
	t_mem_block	*data;

	if (argc != 0 && argv)
	{
		data = ft_parse_file(argv[1]);
		# if DEBUG == 1
		ft_put_points(data);
		# endif
		if (!(connector = mlx_init()))
			ft_error_exit(1, (char*[]){MLX_INIT_ERROR}, EXIT_FAILURE);
		if (!(win = mlx_new_window(connector, 1920, 1080, WINDOW_NAME)))
			ft_error_exit(1, (char*[]){MLX_NEW_WIN_ERROR}, EXIT_FAILURE);
		if (!(image = mlx_new_image(connector, 1920, 1080)))
			ft_error_exit(1, (char*[]){MLX_NEW_IMG_ERROR}, EXIT_FAILURE);
		ft_draw_lines(data, connector, win);
	}
//	return (0);
}
