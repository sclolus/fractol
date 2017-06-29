/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 23:22:11 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/29 09:06:36 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* static void	ft_case_2(t_mlx_data *mlx_data, t_line *line) */
/* { */
/* 	int					*image_rgb; */
/* 	double				e; */
/* 	double				ordonne; */
/* 	double				x; */
/* 	double				y; */

/* 	image_rgb = (int*)mlx_data->frame->buffer; */
/* 	e = line->e; */
/* 	ordonne = line->end.y - (e * line->end.x); */
/* 	x = line->end.x; */
/* 	y = line->end.y; */
/* 	while (x < line->start.x) */
/* 	{ */
/* 		y = ordonne + e * x; */
/* 		((int*)image_rgb)[(int)(y + WINDOW_HEIGHT / 2) * WINDOW_WIDTH + (int)x + WINDOW_WIDTH / 2] = 0xFFFFFF; */
/* 		x += 1L; */
/* 	} */
/* } */

static void	ft_case_1(t_mlx_data *mlx_data, t_line *line)
{
	int					*image_rgb;
	double				e;
	double				ordonne;
	double				derror;
	double				x;
	double				y;
	double				error;

	image_rgb = (int*)mlx_data->frame->buffer;
	e = line->e;
	derror = (e >= 0 ? e : -e);
	error = derror - 0.5;
	ordonne = line->start.y - (e * line->start.x);
	x = line->start.x;
	y = line->start.y;
	while (x < line->end.x)
	{
		((int*)image_rgb)[(int)(y + WINDOW_HEIGHT / 2 ) * WINDOW_WIDTH + (int)x + WINDOW_WIDTH / 2] = 0xFFFFFF;
		error += derror;
		if (error >= 0)
		{
			y++;
			error -= 1L;
		}
		x += 1L;
	}
}

/* static void	ft_swap_t_point_in_line(t_line *line) */
/* { */
/* 	t_vec	tmp; */

/* 	tmp = line->start; */
/* 	line->start = line->end; */
/* 	line->end = tmp; */
/* } */

static void	ft_swap_coords_x_in_line(t_line *line)
{
	double	tmp;

	tmp = line->start.x;
	line->start.x = line->end.x;
	line->end.x = tmp;
	tmp = line->start.y;
	line->start.y = line->end.y;
	line->end.y = tmp;
}

void	ft_draw_line(t_mlx_data *mlx_data, t_line *line)
{

	/* printf("line->start.x: %lf, line->start.y: %lf, line->end.x: %lf, line->end.y: %lf\n", line->start.x + (WINDOW_WIDTH / 2), line->start.y + (WINDOW_HEIGHT / 2), line->end.x  + (WINDOW_WIDTH / 2), line->end.y + (WINDOW_HEIGHT / 2)); */
	/* if (!(new_line = ft_line_clipping(&(t_line){{line->start.x + WINDOW_WIDTH / 2, line->start.y + WINDOW_HEIGHT / 2 , 0}, {line->end.x + WINDOW_WIDTH / 2, line->end.y + WINDOW_HEIGHT / 2 , 0}, line->dx, line->dy, line->e, NULL, NULL}))) */
	/* 	return ; */
	/* printf("new_line->start.x: %lf, new_line->start.y: %lf, new_line->end.x: %lf, new_line->end.y: %lf\n", new_line->start.x, new_line->start.y, new_line->end.x, new_line->end.y); */
	if (line->start.x + (WINDOW_WIDTH / 2) >= WINDOW_WIDTH || line->start.y + (WINDOW_HEIGHT / 2) >=  WINDOW_HEIGHT || line->start.x + (WINDOW_WIDTH / 2)< 0 || line->start.y + (WINDOW_HEIGHT / 2) < 0 || line->end.x + (WINDOW_WIDTH / 2) >= WINDOW_WIDTH || line->end.y + (WINDOW_HEIGHT / 2) >=  WINDOW_HEIGHT || line->end.x + (WINDOW_WIDTH / 2) < 0 || line->end.y + (WINDOW_HEIGHT / 2) < 0)
		return ;
	if (line->start.x > line->end.x)
		ft_swap_coords_x_in_line(line);
	ft_case_1(mlx_data, line);
}
