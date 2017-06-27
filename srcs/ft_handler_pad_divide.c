/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_pad_divide.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 07:47:16 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/27 07:50:56 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_handler_pad_divide(void *param)
{
	ft_sus_reduction_coefficient();
	ft_set_3d((t_mem_block*)((t_mem_block**)param)[3]);
	ft_draw_lines(((MLX_PTR)((char**)param)[0]), (MLX_PTR)((char**)param)[1]
				  , (MLX_IMG)((char**)param)[2],(t_mem_block*)((t_mem_block**)param)[3]);
}
