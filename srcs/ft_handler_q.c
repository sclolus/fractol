/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_q.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 07:47:52 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/27 07:51:31 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_handler_q(void *param)
{
	ft_add_perspective_angle();
	ft_set_3d((t_mem_block*)((t_mem_block**)param)[3]);
	ft_draw_lines(((MLX_PTR)((char**)param)[0]), (MLX_PTR)((char**)param)[1]
				  , (MLX_IMG)((char**)param)[2],(t_mem_block*)((t_mem_block**)param)[3]);
}
