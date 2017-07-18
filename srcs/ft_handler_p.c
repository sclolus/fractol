/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 09:27:10 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/16 09:30:54 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_handler_p(void *param)
{
	t_mlx_data	*mlx_data;

	mlx_data = (t_mlx_data*)((t_mlx_data**)param)[0];
	ft_create_screenshot(mlx_data->frame->buffer, WINDOW_WIDTH, WINDOW_HEIGHT);
}
