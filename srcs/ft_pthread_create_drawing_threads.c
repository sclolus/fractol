/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthread_create_drawing_threads.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 10:40:16 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/23 06:01:13 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

pthread_t	*ft_pthread_create_drawing_threads(t_mlx_data *mlx_data
							, t_pthread_execution_data *pthread_data, f_draw_fractal *f)
{
	static pthread_t					threat_tab[DRAWING_THREAD_NBR + 1];
	uint32_t							i;

	i = 0;
	while (i < DRAWING_THREAD_NBR + 1)
	{
		pthread_data[i].mlx_data = *mlx_data;
		pthread_data[i].f = f;
		if (i && pthread_create(threat_tab + i, NULL
			, &ft_pthread_draw_fractal_routine, pthread_data + i) == -1)
			ft_error_exit(1, (char*[]){ERR_PTHREAD_FAIL}, EXIT_FAILURE);
		i++;
	}
	return (threat_tab);
}
