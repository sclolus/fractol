/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthread_draw_fractal_routine.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 10:59:08 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/03 11:13:05 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_pthread_draw_fractal_routine(void *arg)
{
	(*((t_pthread_execution_data*)arg)->f)(arg);
	pthread_exit(((t_pthread_execution_data*)arg)->mlx_data.frame);
}
