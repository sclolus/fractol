/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cl_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 04:29:27 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/21 07:23:11 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_cl_julia(t_mlx_data *mlx_data, t_fractal_data *fractal_data
						, t_cl_execution_data *cl_data)
{
	cl_int				ret;
	static int			win_width = WINDOW_WIDTH;
	static int			win_heigth = WINDOW_HEIGHT;
	t_complexe			c_distance;
	t_complexe_cadran	c;

	c_distance = (t_complexe){ft_double_distance(
			fractal_data->c.min.real_part
			, fractal_data->c.max.real_part) / WINDOW_WIDTH
			, ft_double_distance(fractal_data->c.min.imaginary_part
			, fractal_data->c.max.imaginary_part) / WINDOW_HEIGHT};
	ret = clSetKernelArg(cl_data->kernel, 0, sizeof(cl_mem), (void*)&cl_data->mem_obj);
	ret = clSetKernelArg(cl_data->kernel, 1, sizeof(int), (void*)&win_width);
	ret = clSetKernelArg(cl_data->kernel, 2, sizeof(int), (void*)&win_heigth);
	c = (fractal_data->c);
	ret = clSetKernelArg(cl_data->kernel, 3, sizeof(t_complexe_cadran), (void*)&c);
	ret = clSetKernelArg(cl_data->kernel, 4, sizeof(uint32_t), (void*)&fractal_data->iteration_number);
	ret = clSetKernelArg(cl_data->kernel, 5, sizeof(t_complexe), (void*)&c_distance);
	ret = clSetKernelArg(cl_data->kernel, 6, sizeof(t_complexe), (void*)&fractal_data->z0);
	if (ret != CL_SUCCESS)
		ft_error_exit(1, (char*[]){CL_ERR_SET_ARG}, EXIT_FAILURE);
	ret = clEnqueueNDRangeKernel(cl_data->cmd_queue, cl_data->kernel, 2, NULL,  (size_t[]){WINDOW_WIDTH, WINDOW_HEIGHT}, NULL/* (size_t[]){8, 24} */, 0, NULL, NULL);
	if (ret != CL_SUCCESS)
		ft_error_exit(1, (char*[]){CL_ERR_KERNEL_LAUNCH}, EXIT_FAILURE);
	ret = clEnqueueReadBuffer(cl_data->cmd_queue, cl_data->mem_obj, CL_TRUE, 0
	, WINDOW_HEIGHT * WINDOW_WIDTH * 4, mlx_data->frame->buffer, 0, NULL, NULL);
	clFlush(cl_data->cmd_queue);
}
