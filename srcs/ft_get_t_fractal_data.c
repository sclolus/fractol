/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_t_fractal_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 17:25:25 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/30 14:05:05 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void					ft_set_fractals_data(t_fractal_data *data)
{
	data[MANDELBROT] = (t_fractal_data){"mandelbrot", MANDELBROT_FILENAME
	, {0, 0}, {{-2, -1}, {1, 1}}, *ft_mandelbrot, *ft_cl_mandelbrot, 2, 64, 0
	, {0}};
	data[JULIA] = (t_fractal_data){"julia", JULIA_FILENAME, {0, 0}, {{-2, -1}
	, {1, 1}}, *ft_julia, *ft_cl_julia, 2, 128, 1, {0}};
	data[NEWTOWN] = (t_fractal_data){"newtown", NEWTOWN_FILENAME, {0, 0}
	, {{-10, -10}, {10, 10}}, *ft_julia, *ft_cl_newtown, 2, 32, 1, {0}};
	data[BERYL] = (t_fractal_data){"beryl", BERYL_FILENAME, {0, 0}, {{-10, -10}
	, {10, 10}}, *ft_julia, *ft_cl_beryl, 2, 32, 1, {0}};
	data[BURNING_SHIP] = (t_fractal_data){"burning_ship", BURNING_SHIP_FILENAME
	, {0, 0}, {{-2, -1}, {1, 1}}, *ft_julia, *ft_cl_burning_ship, 2, 32, 0
	, {0}};
	data[MULTIBROT] = (t_fractal_data){"multibrot", MULTIBROT_FILENAME, {0, 0}
	, {{-2, -1}, {1, 1}}, *ft_julia, *ft_cl_multibrot, 3, 32, 0, {0}};
	data[MULTILIA] = (t_fractal_data){"multilia", MULTILIA_FILENAME, {0, 0}
	, {{-2, -1}, {1, 1}}, *ft_julia, *ft_cl_multilia, 3, 32, 1, {0}};
}

inline t_fractal_data	*ft_get_reset_data(void)
{
	static t_fractal_data	fractals_data[SUPPORTED_FRACTAL_NBR];
	static int32_t			set = 0;

	if (!set)
	{
		ft_set_fractals_data(fractals_data);
		set = 1;
	}
	return (fractals_data);
}

inline t_fractal_data	*ft_get_t_fractal_data(void)
{
	static t_fractal_data	fractals_data[SUPPORTED_FRACTAL_NBR];
	static int32_t			set = 0;

	if (!set)
	{
		ft_set_fractals_data(fractals_data);
		set = 1;
	}
	return (fractals_data);
}
