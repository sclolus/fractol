/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 23:22:11 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/27 00:08:19 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line(t_mlx_data *mlx_data, t_point *a, t_point *b)
{
	t_mlx_image_data	img_data;
	int					*image_rgb;
	double				e;
	double				ordonne;
	double				x;

	image_rgb = (void*)mlx_get_data_addr(mlx_data->image, &img_data.bits_per_pixel
								, &img_data.size_line, &img_data.endian);
	printf("bits_per_pixel: %d\n", img_data.size_line);
	if (a->coords.x > b->coords.x)
	{
		e = ((b->coords.z - a->coords.z) / (b->coords.x - a->coords.x));
		ordonne = b->coords.z - (e * b->coords.x);
		x = b->coords.x;
		while (x < a->coords.x)
		{
			((int*)image_rgb)[(int)(ordonne + e * x) * img_data.size_line + (int)x] = 0xFFFFFF;
//			mlx_pixel_put(connector, win, (int)x, WINDOW_HEIGHT - (int)(ordonne + e * x), (int)0xFFFFFFF);
			x += 0.05L;
		}
		return ;
	}
	e = ((b->coords.z - a->coords.z) / (b->coords.x - a->coords.x));
	ordonne = a->coords.z - (e * a->coords.x);
	x = a->coords.x;
	while (x <= b->coords.x)
	{
		((int*)image_rgb)[(int)(ordonne + e * x) * img_data.size_line + (int)x] = 0xFFFFFF;
//		mlx_pixel_put(connector, win, (int)x, WINDOW_HEIGHT - (int)(ordonne + e * x), (int)0xFFFFFFF);
		x += 0.05L;
	}
}
