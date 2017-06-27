/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 23:22:11 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/27 07:05:20 by sclolus          ###   ########.fr       */
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
//	printf("bits_per_pixel: %d\n", img_data.size_line);
	if (a->coords.x > WINDOW_WIDTH || a->coords.x < 0 || b->coords.x > WINDOW_WIDTH || b->coords.x < 0
		|| a->coords.z > WINDOW_HEIGHT || a->coords.z < 0 || b->coords.z > WINDOW_HEIGHT || b->coords.z < 0)
		return ;
	if (a->coords.x > b->coords.x)
	{
		e = ((b->coords.z - a->coords.z) / (b->coords.x - a->coords.x));
		ordonne = b->coords.z - (e * b->coords.x);
		x = b->coords.x;
		while (x < a->coords.x)
		{
			((int*)image_rgb)[(int)((ordonne + e * x)) * WINDOW_WIDTH + (int)x] = 0xFFFFFF;
			x += 0.5L;
		}
		return ;
	}
	e = ((b->coords.z - a->coords.z) / (b->coords.x - a->coords.x));
	ordonne = a->coords.z - (e * a->coords.x);
	x = a->coords.x;
	while (x < b->coords.x)
	{
		((int*)image_rgb)[(int)((ordonne + e * x)) * WINDOW_WIDTH + (int)x] = 0xFFFFFF;
		x += 0.5L;
	}
}
