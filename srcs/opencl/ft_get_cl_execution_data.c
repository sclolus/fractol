/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cl_execution_data.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 02:03:57 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/30 05:44:01 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static inline void	ft_inline_get_prog(t_cl_execution_data *cl_data
									, char *filename)
{
	cl_data->program = ft_get_cl_program_from_source(cl_data->context
						, filename);
}

t_cl_execution_data	*ft_get_cl_execution_data(t_fractal_type fractal_type)
{
	static t_fractal_type		current_fractal_type = SUPPORTED_FRACTAL_NBR;
	static t_cl_execution_data	cl_data;
	static t_fractal_data		*fractal_data = NULL;

	if (!fractal_data)
	{
		fractal_data = ft_get_t_fractal_data();
		cl_data.device_id = ft_get_device_id();
		cl_data.context = ft_get_cl_context(cl_data.device_id);
		cl_data.cmd_queue = ft_get_cl_command_queue(cl_data.context
								, cl_data.device_id);
		cl_data.mem_obj = ft_get_cl_buffer(cl_data.context, CL_MEM_WRITE_ONLY
								, WINDOW_HEIGHT * WINDOW_WIDTH * 4);
	}
	if (current_fractal_type != fractal_type)
	{
		clReleaseProgram(cl_data.program);
		if (current_fractal_type != SUPPORTED_FRACTAL_NBR)
			clReleaseKernel(cl_data.kernel);
		ft_inline_get_prog(&cl_data, fractal_data[fractal_type].cl_filename);
		cl_data.kernel = ft_get_cl_kernel(cl_data.program
						, fractal_data[fractal_type].name, cl_data.device_id);
		current_fractal_type = fractal_type;
	}
	return (&cl_data);
}
