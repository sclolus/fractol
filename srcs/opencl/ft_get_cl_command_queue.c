/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cl_command_queue.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 02:10:16 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/16 02:10:59 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

cl_command_queue ft_get_cl_command_queue(cl_context context, cl_device_id device_id)
{
	cl_command_queue	cmd_queue;
	cl_int				ret;

	cmd_queue = clCreateCommandQueue(context, device_id, 0, &ret);
	if (ret != CL_SUCCESS)
		ft_error_exit(1, (char*[]){CL_ERR_COMMAND_QUEUE}, EXIT_FAILURE);
	return (cmd_queue);
}
