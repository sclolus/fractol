/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_t_fractal_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 17:25:25 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/29 04:08:24 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline t_fractal_data	*ft_get_t_fractal_data(void)
{
	static t_fractal_data	fractals_data[SUPPORTED_FRACTAL_NBR] = {
	{"mandelbrot", MANDELBROT_FILENAME, {0, 0}, {{-2, -1}, {1, 1}}
	, *ft_mandelbrot, *ft_cl_mandelbrot, 2, 64, 0, {0}}
	, {"julia", JULIA_FILENAME, {0, 0}, {{-2, -1}, {1, 1}}
	, *ft_julia, *ft_cl_julia, 2, 128, 1, {0}}
	, {"newtown", NEWTOWN_FILENAME, {0, 0}, {{-10, -10}, {10, 10}}
	, *ft_julia, *ft_cl_newtown, 2, 32, 1, {0}}
	, {"beryl", BERYL_FILENAME, {0, 0}, {{-10, -10}, {10, 10}}
	, *ft_julia, *ft_cl_beryl, 2, 32, 1, {0}}
	, {"burning_ship", BURNING_SHIP_FILENAME, {0, 0}, {{-2, -1}, {1, 1}}
	, *ft_julia, *ft_cl_burning_ship, 2, 32, 1, {0}}};

	return (fractals_data);
}
