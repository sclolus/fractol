/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 16:54:59 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/27 16:24:26 by sclolus          ###   ########.fr       */
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
		((t_point*)data->block + i)->coords.x *= 10;
		((t_point*)data->block + i)->coords.y *= 10;
		((t_point*)data->block + i)->coords.z *= 10;
//		printf("Next: data->next: %p", (void*)data->next);
		printf("[%lf, %lf, %lf]\t", (((t_point*)data->block) + i)->coords.x
		, (((t_point*)data->block) + i)->coords.y, (((t_point*)data->block) + i)->coords.z);
		i++;
		if ((((t_point*)data->block) + i)->coords.y
			> (((t_point*)data->block) + i - 1)->coords.y)
			printf("\n");
		if (i * sizeof(t_point) >= data->offset && data->next)
		{
			data = data->next;
			i = 0;
		}
	}
	fflush(NULL);
}
# endif

int	main(int argc, char **argv)
{
	MLX_PTR		connector;
	MLX_WIN		win;
	MLX_IMG		image;
	t_mem_block	*data;
	t_mem_block	*lines;

	if (argc != 0 && argv)
	{
		data = ft_parse_file(argv[1]);
		if (!(connector = mlx_init()))
			ft_error_exit(1, (char*[]){MLX_INIT_ERROR}, EXIT_FAILURE);
		if (!(win = mlx_new_window(connector, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME)))
			ft_error_exit(1, (char*[]){MLX_NEW_WIN_ERROR}, EXIT_FAILURE);
		if (!(image = mlx_new_image(connector, WINDOW_WIDTH, WINDOW_HEIGHT)))
			ft_error_exit(1, (char*[]){MLX_NEW_IMG_ERROR}, EXIT_FAILURE);
		lines = ft_set_lines(data);
		ft_quat_rotate_points(&(t_vec){1, 0.5, 1},  -45 * PI / 180, data);
		ft_draw_lines(connector, win, image, data);
		mlx_hook(win, KeyPress, KeyPressMask | KeymapStateMask, &ft_handler_keys, (void*[]){connector, win, image, data});
		mlx_hook(win, KeyRelease, KeyReleaseMask | KeymapStateMask, &ft_handler_keys_release, (void*[]){connector, win, image, data});
		mlx_loop(connector);
	}
}
