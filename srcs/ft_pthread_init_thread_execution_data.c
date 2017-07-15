/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthread_init_thread_execution_data.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 23:38:42 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/15 00:50:12 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void					ft_pthread_init_c_augmentation_rate(t_pthread_execution_data *pthread_data
																, uint32_t index)
{
	pthread_data[index].c_augmentation_rate =
		(t_complexe){(pthread_data[index].complexe_cadran.max.real_part
		- pthread_data[index].complexe_cadran.min.real_part)
		/ (pthread_data[index].win_cadran.max.x
		- pthread_data[index].win_cadran.min.x),
		(pthread_data[index].complexe_cadran.max.imaginary_part
		- pthread_data[index].complexe_cadran.min.imaginary_part)
		/ (pthread_data[index].win_cadran.max.y
		- pthread_data[index].win_cadran.min.y)};
}

t_pthread_execution_data	*ft_pthread_init_thread_execution_data(uint32_t thread_nbr
								, t_complexe_cadran complexe_cadran)
{
	t_pthread_execution_data	*pthread_data;
	t_complexe					complexe_delta;
	uint32_t					i;

	pthread_data = ft_get_t_pthread_execution_data();
	complexe_delta = (t_complexe){(ft_float_distance(complexe_cadran.min.real_part
								, complexe_cadran.max.real_part) / thread_nbr)
								, (ft_float_distance(complexe_cadran.min.imaginary_part
								, complexe_cadran.max.imaginary_part) / thread_nbr)};
	i = 0;
	while (i < thread_nbr)
	{
		pthread_data[i] = (t_pthread_execution_data){{NULL, NULL, NULL}
		, {{(WINDOW_WIDTH / thread_nbr) * i, /* (WINDOW_HEIGHT / thread_nbr) * i */0}
		, {(WINDOW_WIDTH / thread_nbr) * (i + 1)
		, /* (WINDOW_HEIGHT / thread_nbr) * (i + 1) */ WINDOW_HEIGHT}}
		, {{complexe_delta.real_part * i  + complexe_cadran.min.real_part
			, /* complexe_delta.imaginary_part * i + complexe_cadran.min.imaginary_part */complexe_cadran.min.imaginary_part}
		, {complexe_delta.real_part * (i + 1) + complexe_cadran.min.real_part
		, /* complexe_delta.imaginary_part */
		   /* 		   * (i + 1) + complexe_cadran.min.imaginary_part} */complexe_cadran.max.imaginary_part}}
		   , {0, 0}, NULL, i, {0}};
		ft_pthread_init_c_augmentation_rate(pthread_data, i);
		i++;
	}
	return (pthread_data);
}
