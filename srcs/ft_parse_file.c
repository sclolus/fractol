/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 20:57:51 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/28 22:17:20 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
static t_vec		ft_get_data_from_line(char *line, t_mem_block *data)
{
	static int64_t	y = 0;
	static t_vec	max = {0, 0, 0};
	int64_t			x;
	int64_t			z;
	uint64_t		i;


	i = 0;
	x = 0;
	while (line[i])
	{
		while (line[i] && !ft_isdigit(line[i]))
			i++;
		z = ft_atoi(line + i);
		max.z = (z > max.z ? z : max.z);
		max.y = (y > max.z ? y : max.y);
		max.x = (x > max.x ? x : max.x);
		ft_mem_block_push_back_elem(data
									, &(t_point){{(double)(x), (double)(y), (double)(-z)}}, sizeof(t_point));
		while (ft_isdigit(line[i]))
			i++;
		x++;
	}
	y++;
	return (max);
}

static void		ft_adjust_points(t_mem_block *data, t_vec max_coords)
{
	uint64_t		i;
	t_vec			half_max;

	i = 0;
	half_max.x = max_coords.x / 2;
	half_max.y = max_coords.y / 2;
	half_max.z = max_coords.z / 2;
	while ((i) * sizeof(t_point) < data->offset)
	{
		((t_point*)data->block + i)->coords.z -= half_max.z;
		((t_point*)data->block + i)->coords.x -= half_max.x;
		((t_point*)data->block + i)->coords.y -= half_max.y;
		i++;
		if ((i) * sizeof(t_point) >= data->offset
			&& data->next)
		{
			data = data->next;
			i = 0;
		}
	}
}

t_mem_block			*ft_parse_file(char *filename)
{
	t_mem_block	*data;
	char		*line;
	t_vec		max_coords;
	int			fd;

	max_coords = (t_vec){0, 0, 0};
	data = ft_create_mem_block(DEFAULT_MEM_BLOCK_SIZE);
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_error_exit(2, (char*[]){filename, OPEN_FILE_FAILED}, EXIT_FAILURE);
	while (get_next_line(fd, &line) > 0)
		max_coords = ft_get_data_from_line(line, data);
	ft_adjust_points(data, max_coords);
	if (close(fd) == -1)
		ft_error_exit(3, (char*[]){"Failed to close(): "
					, filename, " file"}, EXIT_FAILURE);
	return (data);
}
