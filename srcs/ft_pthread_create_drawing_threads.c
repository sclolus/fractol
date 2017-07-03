/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthread_create_drawing_threads.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 10:40:16 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/03 11:12:46 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

pthread_t	*ft_pthread_create_drawing_threads(t_mlx_data *mlx_data
											, f_draw_fractal *f)
{
	static pthread_t					threat_tab[DRAWING_THREAD_NBR];
	static t_pthread_execution_data		pthread_data[DRAWING_THREAD_NBR];
	uint32_t							i;

	i = 0;
	while (i < DRAWING_THREAD_NBR)
	{
		pthread_data[i] = (t_pthread_execution_data){*mlx_data
					, f, i + 1, {0}};
		if (pthread_create(threat_tab + i, NULL, &ft_pthread_draw_fractal_routine
					, pthread_data + i))
			ft_error_exit(1, (char*[]){ERR_PTHREAD_FAIL}, EXIT_FAILURE);
		i++;
	}
	return (threat_tab);
}
