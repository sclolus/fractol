/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cl_kernel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 02:04:23 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/16 02:04:42 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
