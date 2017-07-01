/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 23:20:15 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/01 05:53:49 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line	*ft_get_line(double x0, double y0, double x1, double y1)
{
	static	t_line	line;

	line.start.x = x0 - WINDOW_WIDTH / 2;
	line.start.y = y0 - WINDOW_HEIGHT / 2;
	line.end.x = x1 - WINDOW_WIDTH / 2;
	line.end.y = y1 - WINDOW_HEIGHT /2 ;
	line.dx =  x1 - x0;
	line.dy =  y1 - y0;
	printf("line.dx: %lf, line.dy: %lf", line.dx, line.dy);
	line.e = line.dy / line.dx;
	printf("line.e: %lf\n", line.e);
	return (&line);
}



void	ft_draw_lines(MLX_PTR connector, MLX_WIN win, t_image_frame *frames,  t_mem_block *data)
{
	uint64_t		i;
	t_image_frame	*frame;

	i = 0;
	frame = ft_claim_image_frame(frames);
	while (i * sizeof(t_line) < data->offset)
	{
		ft_draw_line(&(t_mlx_data){connector, win, frame}, ((t_line*)data->block + i));
		i++;
		if (i * sizeof(t_line) >= data->offset
			&& data->next)
		{
			data = data->next;
			i = 0;
		}
	}
	mlx_put_image_to_window(connector, win, frame->frame, 0, 0);
	frame->state = TO_CLEAR;
}
