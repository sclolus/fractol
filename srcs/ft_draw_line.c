/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 23:22:11 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/01 18:34:30 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_case_1(t_mlx_data *mlx_data, t_line *line)
{
	int					*image_rgb;
	double				e;
	double				derror;
	double				x;
	double				y;
	double				error;

	image_rgb = (int*)mlx_data->frame->buffer;
	e = (line->dy / line->dx);
	derror = ABS(e);
	error = derror - 0.5;
	x = line->start.x;
	y = line->start.y;
	while (x < line->end.x)
	{
		((int*)image_rgb)[(int)(y + WINDOW_HEIGHT / 2) * WINDOW_WIDTH + (int)(x) + WINDOW_WIDTH / 2] = ft_get_color_interpolation(line, &(t_vec){x, y, 0});
		error += derror;
		if (error >= 0.5)
		{
			y += 1L;
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
	e = (line->dy / line->dx);
	derror = ABS(e);
	error = derror - 0.5;
	x = line->start.x;
	y = line->start.y;
	while (x < line->end.x)
	{
		((int*)image_rgb)[(int)(y + WINDOW_HEIGHT / 2) * WINDOW_WIDTH + (int)x + WINDOW_WIDTH / 2] = ft_get_color_interpolation(line, &(t_vec){x, y, 0});
		error += derror;
		if (error >= 0.5)
		{
			y--;
			error -= 1L;
		}
		x += 1;
	}
}

static void	ft_case_3(t_mlx_data *mlx_data, t_line *line)
{
	int					*image_rgb;
	double				e;
	double				derror;
	double				x;
	double				y;
	double				error;

	image_rgb = (int*)mlx_data->frame->buffer;
	e = (line->dx / line->dy);
	derror = ABS(e);
	error = derror - 0.5;
	x = line->start.x;
	y = line->start.y;
	while (y < line->end.y)
	{
		((int*)image_rgb)[(int)(y + WINDOW_HEIGHT / 2) * WINDOW_WIDTH + (int)x + WINDOW_WIDTH / 2] = ft_get_color_interpolation(line, &(t_vec){x, y, 0});
		error += derror;
		if (error >= 0.5)
		{
			x++;
			error -= 1L;
		}
		y += 1;
	}
}

static void	ft_case_4(t_mlx_data *mlx_data, t_line *line)
{
	int					*image_rgb;
	double				e;
	double				derror;
	double				x;
	double				y;
	double				error;

	image_rgb = (int*)mlx_data->frame->buffer;
	e = (line->dx / line->dy);
	derror = ABS(e);
	error = derror - 0.5;
	x = line->start.x;
	y = line->start.y;
	while (y > line->end.y)
	{
		((int*)image_rgb)[(int)(y + WINDOW_HEIGHT / 2) * WINDOW_WIDTH + (int)x + WINDOW_WIDTH / 2] = ft_get_color_interpolation(line, &(t_vec){x, y, 0});
		error += derror;
		if (error >= 0.5)
		{
			x++;
			error -= 1L;
		}
		y -= 1;
	}
}

static void	ft_swap_t_point_in_line(t_line *line)
{
	t_vec	tmp;

	tmp = line->start;
	line->start = line->end;
	line->end = tmp;
	line->dx *= 1;
	line->dy *= 1;
}
void	ft_draw_line(t_mlx_data *mlx_data, t_line *line)
{
	t_line	tmp;

	tmp = *line;
	if (tmp.start.x + (WINDOW_WIDTH / 2) + 1 >= WINDOW_WIDTH || tmp.start.y + (WINDOW_HEIGHT / 2) + 1 >=  WINDOW_HEIGHT
		|| tmp.start.x + (WINDOW_WIDTH / 2) < 0 || tmp.start.y + (WINDOW_HEIGHT / 2) < 0 || tmp.end.x + (WINDOW_WIDTH / 2) + 1>= WINDOW_WIDTH || tmp.end.y + (WINDOW_HEIGHT / 2) + 1 >=  WINDOW_HEIGHT
		|| tmp.end.x + (WINDOW_WIDTH / 2) < 0 || tmp.end.y + (WINDOW_HEIGHT / 2) < 0)
		return ;
	if (tmp.start.x > tmp.end.x)
		ft_swap_t_point_in_line(&tmp);
	if (tmp.start.y > tmp.end.y)
	{
		if (ABS(tmp.e) < 1)
			ft_case_2(mlx_data, &tmp);
		else
			ft_case_4(mlx_data, &tmp);
	}
	else
	{
		if (ABS(tmp.e) < 1)
			ft_case_1(mlx_data, &tmp);
		else
			ft_case_3(mlx_data, &tmp);
	}
}
