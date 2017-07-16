/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cl_context.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 02:11:22 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/16 02:12:34 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
