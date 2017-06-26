/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 20:57:51 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/26 18:02:59 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
static void		ft_get_data_from_line(char *line, t_mem_block *data)
{
	static int64_t	y = 0;
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
		ft_mem_block_push_back_elem(data
									, &(t_point){NULL, {(double)(x), (double)(y), (double)(z)}}, sizeof(t_point));
		while (ft_isdigit(line[i]))
			i++;
		x++;
	}
	y++;
}


t_mem_block		*ft_parse_file(char *filename)
{
	t_mem_block	*data;
	char		*line;
	int			fd;

	data = ft_create_mem_block(DEFAULT_MEM_BLOCK_SIZE);
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_error_exit(2, (char*[]){filename, OPEN_FILE_FAILED}, EXIT_FAILURE);
	while (get_next_line(fd, &line) > 0)
		ft_get_data_from_line(line, data);
	return (data);
}
