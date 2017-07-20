/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:46:58 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/20 09:17:29 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal_type	ft_parse(char *fractal_name)
{
	char		*fractal_types[] =
		{"mandelbrot", "julia", "newtown"};
	uint32_t	i;

	i = 0;
	while (i < sizeof(fractal_types) / sizeof(char*))
	{
		if (ft_strequ(fractal_name, fractal_types[i]))
			return ((t_fractal_type)i);
		i++;
	}
	ft_error(2, (char*[]){"illegal fractal name: ", fractal_name}, 0);
	ft_print_usage();
}
