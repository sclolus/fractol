/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 23:22:11 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/29 12:44:29 by sclolus          ###   ########.fr       */
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
	double				derror;
	double				x;
	double				y;
	double				error;

	image_rgb = (int*)mlx_data->frame->buffer;
//	e = line->e;
	e = ((line)->start.y - (line)->end.y) / ((line)->start.x - (line)->end.x);
	derror = ABS((line->start.y - line->end.y) / (line->start.x - line->end.x));
	printf("derror: %lf\n", derror);
	error = derror - 0.5;
	x = line->start.x;
	y = line->start.y;
	while (x < line->end.x)
	{
		((int*)image_rgb)[(int)(y /* + WINDOW_HEIGHT / 2 */) * WINDOW_WIDTH + (int)x /* + WINDOW_WIDTH / 2 */] = 0xFFFFFF;
		error += derror;
		if (error >= 0.5)
		{
			y++;
			error -= 1L;
		}
		x += 1L;
	}
}

static void	ft_case_2(t_mlx_data *mlx_data, t_line *line)
{
	int					*image_rgb;
	double				e;
	double				derror;
	double				x;
	double				y;
	double				error;

	image_rgb = (int*)mlx_data->frame->buffer;
	e = ((line)->start.y - (line)->end.y) / ((line)->start.x - (line)->end.x);
//	e = line->e;
	derror = line->start.x > line->end.x ? line->start.x - line->end.x : line->end.x - line->start.x;
//	derror = line->dx / 2;
	error = derror - 0.5;
	x = line->start.x;
	y = line->start.y;
	while (x < line->end.x)
	{
		((int*)image_rgb)[(int)(x /* + WINDOW_HEIGHT / 2 */) * WINDOW_WIDTH + (int)y /* + WINDOW_WIDTH / 2 */] = 0xFF0000;
		error += derror;
		if (error >= 0.5)
		{
			y++;
			error -= 1L;
		}
		x += 1L;
	}
}

static void	ft_swap_t_point_in_line(t_line *line)
{
	t_vec	tmp;

	tmp = line->start;
	line->start = line->end;
	line->end = tmp;
}

static void	ft_swap_coords_in_line(t_line *line)
{
	double	tmp;

	tmp = line->start.x;
	line->start.x = line->start.y;
	line->start.y = tmp;
	tmp = line->end.y;
	line->end.y = line->end.x;
	line->end.x = tmp;
}

void	ft_draw_line(t_mlx_data *mlx_data, t_line *line)
{
	t_line	tmp;

	tmp = *line;
	if (tmp.start.x > tmp.end.x || tmp.start.y > tmp.end.y)
		ft_swap_t_point_in_line(&tmp);
	if (ABS(line->dy) > ABS(line->dx) /* ABS(line->e) > 1 */)
	{
		ft_swap_coords_in_line(&tmp);
		/* if (tmp.start.x + (WINDOW_WIDTH / 2) >= WINDOW_WIDTH || tmp.start.y + (WINDOW_HEIGHT / 2) >=  WINDOW_HEIGHT || tmp.start.x + (WINDOW_WIDTH / 2)< 0 || tmp.start.y + (WINDOW_HEIGHT / 2) < 0 || tmp.end.x + (WINDOW_WIDTH / 2) >= WINDOW_WIDTH || tmp.end.y + (WINDOW_HEIGHT / 2) >=  WINDOW_HEIGHT || tmp.end.x + (WINDOW_WIDTH / 2) < 0 || tmp.end.y + (WINDOW_HEIGHT / 2) < 0) */
		/* 	return; */
		ft_case_2(mlx_data, &tmp);
		return ;
	}
	/* if (tmp.start.x + (WINDOW_WIDTH / 2) >= WINDOW_WIDTH || tmp.start.y + (WINDOW_HEIGHT / 2) >=  WINDOW_HEIGHT || tmp.start.x + (WINDOW_WIDTH / 2)< 0 || tmp.start.y + (WINDOW_HEIGHT / 2) < 0 || tmp.end.x + (WINDOW_WIDTH / 2) >= WINDOW_WIDTH || tmp.end.y + (WINDOW_HEIGHT / 2) >=  WINDOW_HEIGHT || tmp.end.x + (WINDOW_WIDTH / 2) < 0 || tmp.end.y + (WINDOW_HEIGHT / 2) < 0) */
	/* 	return ; */
	printf("line->start.x: %lf, line->start.y: %lf, line->end.y: %lf, line->end.x: %lf\n ", tmp.start.x, tmp.start.y, tmp.end.y, tmp.end.x);
	ft_case_1(mlx_data, &tmp);
}
