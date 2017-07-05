/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 07:39:39 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/05 17:20:54 by sclolus          ###   ########.fr       */
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

	i = pthread_data->win_cadran.min.y;
	image = pthread_data->mlx_data.frame->buffer;
	c = pthread_data->complexe_cadran.min;
	while (i < pthread_data->win_cadran.max.y)
	{
		u = pthread_data->win_cadran.min.x;
		while (u < pthread_data->win_cadran.max.x)
		{
			if (!(color = ft_is_bounded(c)))
				image[(int)((int)i * (WINDOW_WIDTH)) + (int)u] = 0;
			else
				image[(int)((int)i * (WINDOW_WIDTH)) + (int)u] = color;
			c.real_part += pthread_data->c_augmentation_rate.real_part;
			u++;
		}
		c.real_part = pthread_data->complexe_cadran.min.real_part;
		c.imaginary_part += pthread_data->c_augmentation_rate.imaginary_part;
		i++;
	}
}
