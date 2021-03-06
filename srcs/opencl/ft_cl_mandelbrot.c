/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cl_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 04:01:37 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/30 03:28:19 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static inline void	ft_set_mandelbrot_kernel_arg(t_cl_execution_data *cl_data
									, t_fractal_data *fractal_data)
{
	static int			win_width = WINDOW_WIDTH;
	static int			win_heigth = WINDOW_HEIGHT;
	t_complexe			c_distance;
	cl_int				ret;

	c_distance = (t_complexe){ft_double_distance(fractal_data->c.min.real_part
	, fractal_data->c.max.real_part) / WINDOW_WIDTH
	, ft_double_distance(fractal_data->c.min.imaginary_part
	, fractal_data->c.max.imaginary_part) / WINDOW_HEIGHT};
	ret = clSetKernelArg(cl_data->kernel, 0, sizeof(cl_mem)
						, (void*)&cl_data->mem_obj);
	ret |= clSetKernelArg(cl_data->kernel, 1, sizeof(int)
						, (void*)&win_width);
	ret |= clSetKernelArg(cl_data->kernel, 2, sizeof(int)
						, (void*)&win_heigth);
	ret |= clSetKernelArg(cl_data->kernel, 3, sizeof(t_complexe_cadran)
						, (void*)&fractal_data->c);
	ret |= clSetKernelArg(cl_data->kernel, 4, sizeof(uint32_t)
						, (void*)&fractal_data->iteration_number);
	ret |= clSetKernelArg(cl_data->kernel, 5, sizeof(t_complexe)
						, (void*)&c_distance);
	if (ret != CL_SUCCESS)
		ft_error_exit(1, (char*[]){CL_ERR_SET_ARG}, EXIT_FAILURE);
}

void				ft_cl_mandelbrot(t_mlx_data *mlx_data
				, t_fractal_data *fractal_data, t_cl_execution_data *cl_data)
{
	cl_int				ret;

	ft_set_mandelbrot_kernel_arg(cl_data, fractal_data);
	ret = clEnqueueNDRangeKernel(cl_data->cmd_queue, cl_data->kernel, 2
	, NULL, (size_t[]){WINDOW_WIDTH, WINDOW_HEIGHT}, NULL, 0, NULL, NULL);
	if (ret != CL_SUCCESS)
		ft_error_exit(1, (char*[]){CL_ERR_KERNEL_LAUNCH}, EXIT_FAILURE);
	ret = clEnqueueReadBuffer(cl_data->cmd_queue, cl_data->mem_obj, CL_TRUE, 0
	, WINDOW_HEIGHT * WINDOW_WIDTH * 4, mlx_data->frame->buffer, 0, NULL, NULL);
	clFlush(cl_data->cmd_queue);
}
