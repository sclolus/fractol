/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 01:58:23 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/12 20:12:54 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

# define MANDELBROT_FILENAME "./test/mandelbrot.cl"

# define CL_ERR_COMMAND_QUEUE "Creation of command queue failed"
# define CL_ERR_GET_DEVICE_IDS "clGetDeviceIDs() failed"
# define CL_ERR_GET_PLATFORMS_IDS "clGetPlatformsIDs() failed"
# define CL_ERR_CREATE_CONTEXT "clCreateContext() failed"
# define CL_ERR_CREATE_BUFFER "clCreateBuffer() failed"
# define CL_ERR_CREATE_PROGRAM_WITH_SOURCE "clCreateProgramWithSource() failed"
# define CL_ERR_BUILD_PROGRAM "clBuildProgram() failed"
# define CL_ERR_CREATE_KERNEL "clCreateKernel() failed"
# define CL_ERR_SET_ARG "clSetKernelArg() failed"
# define CL_ERR_KERNEL_LAUNCH "Kernel launch failed"

cl_kernel		ft_get_cl_kernel(cl_program program, char *name
								 , cl_device_id device_id);
cl_device_id	ft_get_device_id(void);
cl_context	ft_get_cl_context(cl_device_id device_id);
cl_command_queue ft_get_cl_command_queue(cl_context context, cl_device_id device_id);
cl_mem			ft_get_cl_buffer(cl_context context, cl_mem_flags mem_flags, uint64_t size);
cl_program		ft_get_cl_program_from_source(cl_context context, char *filename);
cl_kernel		ft_get_cl_kernel(cl_program program, char *name
								 , cl_device_id device_id);
void	ft_call_cl(t_mlx_data *mlx_data, t_fractal_type fractal_type);


cl_device_id	ft_get_device_id(void)
{
	cl_platform_id	platform_id;
	cl_device_id	device_id;
	cl_uint			ret_num_platforms;
	cl_uint			ret_num_devices;
	cl_int			ret;

	platform_id = NULL;
	ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
	if (ret != CL_SUCCESS)
		ft_error_exit(1, (char*[]){CL_ERR_GET_DEVICE_IDS}, EXIT_FAILURE);
	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &ret_num_devices);
	if (ret != CL_SUCCESS)
		ft_error_exit(1, (char*[]){CL_ERR_GET_PLATFORMS_IDS}, EXIT_FAILURE);
	return (device_id);
}

cl_context	ft_get_cl_context(cl_device_id device_id)
{
	cl_context		context;
	cl_int			ret;

	context = NULL;
	context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);
	if (ret != CL_SUCCESS)
		ft_error_exit(1, (char*[]){CL_ERR_CREATE_CONTEXT}, EXIT_FAILURE);
	return (context);
}

cl_command_queue ft_get_cl_command_queue(cl_context context, cl_device_id device_id)
{
	cl_command_queue	cmd_queue;
	cl_int				ret;

	cmd_queue = clCreateCommandQueue(context, device_id, 0, &ret);
	if (ret != CL_SUCCESS)
		ft_error_exit(1, (char*[]){CL_ERR_COMMAND_QUEUE}, EXIT_FAILURE);
	return (cmd_queue);
}

cl_mem			ft_get_cl_buffer(cl_context context, cl_mem_flags mem_flags, uint64_t size)
{
	cl_mem	mem_obj;
	cl_int	ret;

	mem_obj = clCreateBuffer(context, mem_flags, size, NULL, &ret);
	if (ret != CL_SUCCESS)
		ft_error_exit(1, (char*[]){CL_ERR_CREATE_BUFFER}, EXIT_FAILURE);
	return (mem_obj);
}

uint32_t	ft_strlen_lol(char *str);
uint32_t	ft_strlen_lol(char *str)
{
	uint32_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);

}

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

cl_kernel		ft_get_cl_kernel(cl_program program, char *name
								, cl_device_id device_id)
{
	cl_int		ret;
	cl_kernel	kernel;

	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
	if (ret != CL_SUCCESS)
		ft_error_exit(1, (char*[]){CL_ERR_BUILD_PROGRAM}
								, EXIT_FAILURE);
	kernel = clCreateKernel(program, (const char*)name, &ret);
	if (ret != CL_SUCCESS)
		ft_error_exit(1, (char*[]){CL_ERR_CREATE_KERNEL}
								, EXIT_FAILURE);
	return (kernel);
}

void	ft_call_cl(t_mlx_data *mlx_data, t_fractal_type fractal_type)
{
	t_cl_execution_data	cl_data;
	cl_int				ret;
	int					win_width = WINDOW_WIDTH;
	int					win_heigth = WINDOW_HEIGHT;

	(void)fractal_type;
	cl_data.device_id = ft_get_device_id();
	cl_data.context = ft_get_cl_context(cl_data.device_id);
	cl_data.cmd_queue = ft_get_cl_command_queue(cl_data.context, cl_data.device_id);
	cl_data.mem_obj = ft_get_cl_buffer(cl_data.context, CL_MEM_READ_WRITE, WINDOW_HEIGHT * WINDOW_WIDTH * 4);
	cl_data.program = ft_get_cl_program_from_source(cl_data.context, MANDELBROT_FILENAME);
	cl_data.kernel = ft_get_cl_kernel(cl_data.program, "mandelbrot", cl_data.device_id);
	ret = clSetKernelArg(cl_data.kernel, 0, sizeof(cl_mem), (void*)&cl_data.mem_obj);
	ret = clSetKernelArg(cl_data.kernel, 1, sizeof(int), (void*)&win_width);
	ret = clSetKernelArg(cl_data.kernel, 2, sizeof(int), (void*)&win_heigth);
	if (ret != CL_SUCCESS)
		ft_error_exit(1, (char*[]){CL_ERR_SET_ARG}, EXIT_FAILURE);
	ret = clEnqueueTask(cl_data.cmd_queue, cl_data.kernel, 0, NULL, NULL);
	if (ret != CL_SUCCESS)
		ft_error_exit(1, (char*[]){CL_ERR_KERNEL_LAUNCH}, EXIT_FAILURE);
	ret = clEnqueueReadBuffer(cl_data.cmd_queue, cl_data.mem_obj, CL_TRUE, 0
	, WINDOW_HEIGHT * WINDOW_WIDTH * 4, mlx_data->frame->buffer, 0, NULL, NULL);
	clFlush(cl_data.cmd_queue);
	clFinish(cl_data.cmd_queue);
	mlx_put_image_to_window(mlx_data->connector, mlx_data->win, mlx_data->frame->frame, 0, 0);
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
		ft_call_cl(&(t_mlx_data){connector, win, frames}, fractal_type);
//		ft_draw_fractal(&(t_mlx_data){connector, win, frames}, fractal_type);
	/* 	mlx_hook(win, KeyPress, KeyPressMask | KeymapStateMask */
/* 				 , &ft_handler_keys, (void*[]){&(t_mlx_data){connector, win, frames}, &fractal_type}); */
/* 		mlx_hook(win, ButtonPress, KeyPressMask | KeymapStateMask */
/* 				, &ft_handler_buttons, (void*[]){&(t_mlx_data){connector, win, frames}, &fractal_type}); */
/* 		mlx_hook(win, KeyRelease, KeyReleaseMask | KeymapStateMask */
/* 				, &ft_handler_keys_release, (void*[]){&(t_mlx_data){connector, win, frames}, &fractal_type}); */
/* 		mlx_hook(win, ButtonRelease, KeyReleaseMask | KeymapStateMask */
/* 				, &ft_handler_buttons_release, (void*[]){&(t_mlx_data){connector, win, frames}, &fractal_type}); */
/* 		mlx_hook(win, MotionNotify, 0, &ft_handler_mouse_motion, (void*[]){&(t_mlx_data){connector, win, frames}, &fractal_type}); */
		mlx_loop(connector);
	}
	else
		ft_print_usage();
}
