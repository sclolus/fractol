/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 16:54:59 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/25 18:18:40 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	MLX_PTR	connector;
	MLX_WIN	win;
	MLX_IMG	image;

	if (argc != 0 && argv)
	{
		if (!(connector = mlx_init()))
			ft_error_exit(1, (char*[]){MLX_INIT_ERROR}, EXIT_FAILURE);
		if (!(win = mlx_new_window(connector, 1920, 1080, WINDOW_NAME)))
			ft_error_exit(1, (char*[]){MLX_NEW_WIN_ERROR}, EXIT_FAILURE);
		if (!(image = mlx_new_image(connector, 1920, 1080)))
			ft_error_exit(1, (char*[]){MLX_NEW_IMG_ERROR}, EXIT_FAILURE);
	}
	while (42)
		;
//	return (0);
}
