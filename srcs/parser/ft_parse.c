/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:46:58 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/21 09:26:45 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal_type	ft_parse(char *fractal_name)
{
	t_fractal_data	*fractal_data;
	uint32_t		i;

	i = 0;
	fractal_data = ft_get_t_fractal_data();
	while (i < SUPPORTED_FRACTAL_NBR)
	{
		if (ft_strequ(fractal_name, fractal_data[i].name))
			return ((t_fractal_type)i);
		i++;
	}
	ft_error(2, (char*[]){"illegal fractal name: ", fractal_name}, 0);
	ft_print_usage();
}
