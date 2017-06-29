/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 23:20:15 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/28 21:35:04 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
