/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 07:39:39 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/03 11:20:32 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int32_t	ft_is_bounded(t_complexe c)
{
	t_complexe		z;
	t_complexe		tmp;
	uint32_t		i;

	i = 0;
	z = (t_complexe){0, 0};
	while (i < ITERATION_NUMBER)
	{
		tmp = ft_square_complexe(&z);
		z = ft_add_complexe(&tmp, &c);
		if (ft_get_complexe_magnitude(&z) > 2)
			return (((int)i * (int)((z.imaginary_part)) * BASE_COLOR) & 0xFFFFFF);
		i++;
	}
	return (0);
}

void			ft_mandelbrot(t_pthread_execution_data *pthread_data)
{
	int				*image;
	t_complexe		c;
	uint32_t		i;
	uint32_t		u;
	int32_t			color;

	i = (WINDOW_HEIGHT / (DRAWING_THREAD_NBR + 1)) * pthread_data->cadran;
	image = pthread_data->mlx_data.frame->buffer;
	c = (t_complexe){-2, -1};
	while (i < (WINDOW_HEIGHT / (DRAWING_THREAD_NBR + 1)) * (pthread_data->cadran + 1))
	{
		u = (WINDOW_WIDTH / (DRAWING_THREAD_NBR + 1)) * pthread_data->cadran;
		while (u < WINDOW_WIDTH / (DRAWING_THREAD_NBR + 1) * (pthread_data->cadran + 1))
		{
			if (!(color = ft_is_bounded(c)))
				image[(int)((int)i * (WINDOW_WIDTH)) + (int)u] = 0;
			else
				image[(int)((int)i * (WINDOW_WIDTH)) + (int)u] = color;
			c.real_part += (3 / (double)WINDOW_WIDTH);
			u++;
		}
		c.real_part = -2;
		c.imaginary_part += 2 / (double)WINDOW_HEIGHT;
		i++;
	}
}
