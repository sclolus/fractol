/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthread_init_thread_execution_data.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 23:38:42 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/04 00:16:12 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pthread_execution_data	*ft_pthread_init_thread_execution_data(uint32_t thread_nbr
								, t_complexe_cadran complexe_cadran)
{
	t_pthread_execution_data	*pthread_data;
	t_complexe					complexe_delta;
	uint32_t					i;

	pthread_data = ft_get_t_pthread_execution_data();
	complexe_delta = (t_complexe){((uint32_t)ft_distance(complexe_cadran.min.x
								, complexe_cadran.max.x) / thread_nbr)
								, ((uint32_t)ft_distance(complexe_cadran.min.y
								, complexe_cadran.max.y) / thread_nbr)};
	i = 0;
	while (i < thread_nbr)
	{
		pthread_data[i] = {{NULL, NULL, NULL}
		, {{(WINDOW_WIDTH / thread_nbr) * i, (WINDOW_HEIGHT / thread_nbr) * i}
		, {(WINDOW_WIDTH / thread_nbr) * (i + 1)
		, (WINDOW_HEIGHT / thread_nbr) * (i + 1)}}
		, {{complexe_delta.x * i - complexe_cadran.min.x, complexe_delta.y * i - complexe_cadran.min.y}
		, {complexe_delta.x * (i + 1) - complexe_cadran.min.x, complexe_delta.y * (i + 1) - complexe_cadran.min.y}}
		, {0, 0}, NULL, i, {0}};
		pthread_data[i].c_augmentation_rate = {pthread_data[i].
		i++;
	}

}
