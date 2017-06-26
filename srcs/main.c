/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 16:54:59 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/27 00:15:15 by sclolus          ###   ########.fr       */
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

	if (argc != 0 && argv)
	{
		data = ft_parse_file(argv[1]);
		# if DEBUG == 1
		ft_put_points(data);
		# endif
		if (!(connector = mlx_init()))
			ft_error_exit(1, (char*[]){MLX_INIT_ERROR}, EXIT_FAILURE);
		if (!(win = mlx_new_window(connector, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME)))
			ft_error_exit(1, (char*[]){MLX_NEW_WIN_ERROR}, EXIT_FAILURE);
		if (!(image = mlx_new_image(connector, WINDOW_WIDTH, WINDOW_HEIGHT)))
			ft_error_exit(1, (char*[]){MLX_NEW_IMG_ERROR}, EXIT_FAILURE);
		ft_set_3d(data);
		ft_set_lines(data);
		/* ft_draw_line(connector, win, &(t_point){NULL, {10, 1000, 10}}, &(t_point){NULL, {1910, 1000, 10}}); */
		/* ft_draw_line(connector, win, &(t_point){NULL, {10, 1000, 1070}}, &(t_point){NULL, {1910, 1000, 1070}}); */
		/* ft_draw_line(connector, win, &(t_point){NULL, {10, 1000, 10}}, &(t_point){NULL, {10, 1000, 1070}}); */
		/* ft_draw_line(connector, win, &(t_point){NULL, {1970, 1000, 1070}}, &(t_point){NULL, {1970, 1000, 10}}); */


		/* ft_draw_line(connector, win, &(t_point){NULL, {10, 1000, 10}}, &(t_point){NULL, {1910, 1000, 1070}}); */
		/* ft_draw_line(connector, win, &(t_point){NULL, {1910, 1000, 10}}, &(t_point){NULL, {10, 1000, 1070}}); */
		ft_draw_lines(connector, win, image, data);
		printf("data: %p\n", (void*)data);
		mlx_key_hook(win, &ft_handler_keys, (void*[]){connector, win, image, data});
		mlx_loop(connector);
	}
}
