/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_cl_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 22:35:31 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/30 03:27:50 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline void	ft_draw_cl_fractal(t_mlx_data *mlx_data
						, t_fractal_type fractal_type)
{
	static t_fractal_data		*fractal_data = NULL;
	t_cl_execution_data			*cl_data;

	if (!fractal_data)
		fractal_data = ft_get_t_fractal_data();
	cl_data = ft_get_cl_execution_data(fractal_type);
	fractal_data[fractal_type].cl_f(mlx_data, &fractal_data[fractal_type]
									, cl_data);
	mlx_put_image_to_window(mlx_data->connector, mlx_data->win
							, mlx_data->frame->frame, 0, 0);
}
