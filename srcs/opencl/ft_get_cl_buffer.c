/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cl_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 02:09:38 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/16 02:11:00 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

cl_mem			ft_get_cl_buffer(cl_context context, cl_mem_flags mem_flags, uint64_t size)
{
	cl_mem	mem_obj;
	cl_int	ret;

	mem_obj = clCreateBuffer(context, mem_flags, size, NULL, &ret);
	if (ret != CL_SUCCESS)
		ft_error_exit(1, (char*[]){CL_ERR_CREATE_BUFFER}, EXIT_FAILURE);
	return (mem_obj);
}
