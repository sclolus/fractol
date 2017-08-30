/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_page_down.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 06:00:05 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/30 06:03:42 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_handler_page_down(void *param)
{
	t_fractal_data	*fractal_data;
	t_fractal_type	fractal_type;

	fractal_data = ft_get_t_fractal_data();
	fractal_type = *((t_fractal_type*)((t_fractal_type**)param)[1]);
	if (fractal_data[fractal_type].iteration_number > 32)
		fractal_data[fractal_type].iteration_number -=
		log2(fractal_data[fractal_type].iteration_number);
	ft_putstr("\nIteration_number: ");
	ft_putnbr((int)fractal_data[fractal_type].iteration_number);
	ft_draw_cl_fractal((t_mlx_data*)((t_mlx_data**)param)[0]
		, *((t_fractal_type*)((t_fractal_type**)param)[1]));
}
