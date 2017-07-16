/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cl_program_from_source.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 02:07:07 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/16 02:11:01 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

cl_program		ft_get_cl_program_from_source(cl_context context, char *filename)
{
	char			*source_str;
	cl_program		program;
	uint64_t		len;
	cl_int			ret;

	if (!(source_str = ft_get_file_content(filename)))
		exit(EXIT_FAILURE);
	len = ft_strlen(source_str);
	program = clCreateProgramWithSource(context, 1, (const char*[]){(const char*)source_str},
										(const size_t*)&len, &ret);
	if (ret != CL_SUCCESS)
		ft_error_exit(1, (char*[]){CL_ERR_CREATE_PROGRAM_WITH_SOURCE}
								, EXIT_FAILURE);
	free(source_str);
	return (program);
}
