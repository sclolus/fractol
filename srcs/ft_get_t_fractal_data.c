/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_t_fractal_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 17:25:25 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/05 17:27:10 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal_data	*ft_get_t_fractal_data(void)
{
		static t_fractal_data	fractals_data[SUPPORTED_FRACTAL_NBR] = {
		{{0, 0}, {{-2, -1}, {1, 1}}, *ft_mandelbrot, 2, {0}}};

		return (fractals_data);
}
