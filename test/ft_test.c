/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 01:58:23 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/21 01:09:57 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_call_cl(t_mlx_data *mlx_data, t_fractal_type fractal_type)
{
	t_cl_execution_data	*cl_data;
	cl_int				ret;
	int					win_width = WINDOW_WIDTH;
	int					win_heigth = WINDOW_HEIGHT;
	t_complexe_cadran	c;

	cl_data = ft_get_cl_execution_data(fractal_type);
 	ret = clSetKernelArg(cl_data->kernel, 0, sizeof(cl_mem), (void*)&cl_data->mem_obj);
	ret = clSetKernelArg(cl_data->kernel, 1, sizeof(int), (void*)&win_width);
	ret = clSetKernelArg(cl_data->kernel, 2, sizeof(int), (void*)&win_heigth);
	c = (ft_get_t_fractal_data()[fractal_type].c);
	ret = clSetKernelArg(cl_data->kernel, 3, sizeof(t_complexe_cadran), (void*)&c);
	t_complexe	c_distance = (t_complexe){ft_double_distance(ft_get_t_fractal_data()[fractal_type].c.min.real_part / WINDOW_WIDTH, ft_get_t_fractal_data()[fractal_type].c.max.real_part), ft_double_distance(ft_get_t_fractal_data()[fractal_type].c.min.imaginary_part, ft_get_t_fractal_data()[fractal_type].c.max.imaginary_part) / WINDOW_HEIGHT};
	ret = clSetKernelArg(cl_data->kernel, 4, sizeof(uint32_t), (void*)&ft_get_t_fractal_data()[fractal_type].iteration_number);
	ret = clSetKernelArg(cl_data->kernel, 5, sizeof(t_complexe), (void*)&c_distance);
	if (ret != CL_SUCCESS)
		ft_error_exit(1, (char*[]){CL_ERR_SET_ARG}, EXIT_FAILURE);
//	ret = clEnqueueTask(cl_data->cmd_queue, cl_data->kernel, 0, NULL, NULL);

	const size_t global_work_size[1] = {WINDOW_WIDTH * WINDOW_HEIGHT};
//	printf("cadran.min.real_part: %.128lf, cadran.max.real_part: %.128lf\n", ft_get_t_fractal_data()[fractal_type].c.min.real_part, ft_get_t_fractal_data()[fractal_type].c.max.real_part);

	ret = clEnqueueNDRangeKernel(cl_data->cmd_queue, cl_data->kernel, 1, NULL, global_work_size, NULL, 0, NULL, NULL);
	if (ret != CL_SUCCESS)
		ft_error_exit(1, (char*[]){CL_ERR_KERNEL_LAUNCH}, EXIT_FAILURE);
	ret = clEnqueueReadBuffer(cl_data->cmd_queue, cl_data->mem_obj, CL_TRUE, 0
	, WINDOW_HEIGHT * WINDOW_WIDTH * 4, mlx_data->frame->buffer, 0, NULL, NULL);
	clFlush(cl_data->cmd_queue);
	mlx_put_image_to_window(mlx_data->connector, mlx_data->win, mlx_data->frame->frame, 0, 0);
//	printf("put image\n");
}

void	ft_test(int argc, char **argv)
{
	MLX_PTR				connector;
	MLX_WIN				win;
	t_image_frame		*frames;
	t_mem_block			*data;
	t_fractal_type		fractal_type;

	data = NULL;
	if (argc == 2 && argv)
	{
		fractal_type = ft_parse(argv[1]);
		if (!(connector = mlx_init()))
			ft_error_exit(1, (char*[]){MLX_INIT_ERROR}, EXIT_FAILURE);
		if (!(win = mlx_new_window(connector, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME)))
			ft_error_exit(1, (char*[]){MLX_NEW_WIN_ERROR}, EXIT_FAILURE);
		frames = ft_get_image_frames(connector, NBR_IMAGE_FRAME);
		ft_draw_cl_fractal(&(t_mlx_data){connector, win, frames}, fractal_type);
		mlx_hook(win, KeyPress, KeyPressMask
				 , &ft_handler_keys, (void*[]){&(t_mlx_data){connector, win, frames}, &fractal_type});
		mlx_hook(win, KeyRelease, KeyReleaseMask
				, &ft_handler_keys_release, (void*[]){&(t_mlx_data){connector, win, frames}, &fractal_type});
		mlx_hook(win, ButtonPress, ButtonPressMask
				, &ft_handler_buttons, (void*[]){&(t_mlx_data){connector, win, frames}, &fractal_type});
		mlx_hook(win, MotionNotify, 0, &ft_handler_mouse_motion, (void*[]){&(t_mlx_data){connector, win, frames}, &fractal_type});
		mlx_loop(connector);
	}
	else
		ft_print_usage();
}
