/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 17:01:02 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/29 01:46:54 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int32_t	ft_is_bounded(t_complexe c, uint32_t iteration_number
								, t_complexe z0)
{
	t_complexe		z;
	t_complexe		tmp;
	uint32_t		i;

	i = 0;
	z = z0;
	while (i < iteration_number)
	{
		tmp = ft_square_complexe(&z);
		z = ft_add_complexe(&tmp, &c);
		if (ft_get_complexe_magnitude(&z) > 2)
			return (((int)i * BASE_COLOR) & 0xFFFFFF);
		i++;
	}
	return (0);
}

void			ft_julia(t_pthread_execution_data *pthread_data)
{
	t_complexe		z0;
	t_complexe		c;
	uint32_t		i;
	uint32_t		u;
	uint32_t		iteration_number;

	i = pthread_data->win_cadran.min.y;
	z0 = pthread_data->complexe_cadran.min;
	iteration_number = ft_get_t_fractal_data()[JULIA].iteration_number;
	c = ft_get_t_fractal_data()[JULIA].z0;
	while (i < pthread_data->win_cadran.max.y)
	{
		u = pthread_data->win_cadran.min.x;
		while (u < pthread_data->win_cadran.max.x)
		{
			((int*)pthread_data->mlx_data.frame->buffer)[(int)((int)i
		* (WINDOW_WIDTH)) + (int)u] = ft_is_bounded(c, iteration_number, z0);
			z0.real_part += pthread_data->c_augmentation_rate.real_part;
			u++;
		}
		z0.real_part = pthread_data->complexe_cadran.min.real_part;
		z0.imaginary_part += pthread_data->c_augmentation_rate.imaginary_part;
		i++;
	}
}
