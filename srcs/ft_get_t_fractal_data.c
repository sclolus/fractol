/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_t_fractal_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 17:25:25 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/16 04:01:28 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal_data	*ft_get_t_fractal_data(void)
{
		static t_fractal_data	fractals_data[SUPPORTED_FRACTAL_NBR] = {
			{"mandelbrot", MANDELBROT_FILENAME, {0, 0}, {{-2, -1}, {1, 1}}
			, *ft_mandelbrot, *ft_cl_mandelbrot, 2, 64},
			{"julia", JULIA_FILENAME, {0, 0}, {{-2, -1}, {1, 1}}
			, *ft_julia, *ft_cl_julia, 2, 32}};
		return (fractals_data);
}
