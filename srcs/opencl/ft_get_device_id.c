/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_device_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 02:12:06 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/16 02:12:33 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
