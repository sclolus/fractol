/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 07:39:39 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/19 06:11:30 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int32_t	ft_is_bounded(t_complexe c, uint32_t iteration_number)
{
	t_complexe		z;
	uint32_t		i;

	i = 0;
	z = (t_complexe){0, 0};
	while (i < iteration_number)
	{
		z = (t_complexe){z.real_part * z.real_part - (z.imaginary_part
			* z.imaginary_part), 2 * z.real_part * z.imaginary_part};
		z = (t_complexe){z.real_part + c.real_part
			, z.imaginary_part + c.imaginary_part};
		if (ft_get_complexe_magnitude(&z) > 2)
			return (((int)i * BASE_COLOR) & 0xFFFFFF);
		i++;
	}
	return (0);
}

void			ft_mandelbrot(t_pthread_execution_data *pthread_data)
{
	int						*image;
	t_complexe				c;
	uint32_t				i;
	uint32_t				u;
	uint32_t				iteration_number;

	i = pthread_data->win_cadran.min.y;
	image = pthread_data->mlx_data.frame->buffer;
	c = pthread_data->complexe_cadran.min;
	iteration_number = ft_get_t_fractal_data()[MANDELBROT].iteration_number;
	while (i < pthread_data->win_cadran.max.y)
	{
		u = pthread_data->win_cadran.min.x;
		while (u < pthread_data->win_cadran.max.x)
		{
			image[(int)((int)i * (WINDOW_WIDTH)) + (int)u] = ft_is_bounded(c
															, iteration_number);
			c.real_part += pthread_data->c_augmentation_rate.real_part;
			u++;
		}
		c.real_part = pthread_data->complexe_cadran.min.real_part;
		c.imaginary_part += pthread_data->c_augmentation_rate.imaginary_part;
		i++;
	}
}
