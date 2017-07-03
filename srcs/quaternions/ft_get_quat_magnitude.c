/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_quat_magnitude.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 08:56:46 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/03 06:21:45 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_get_quat_magnitude(t_quat *quat)
{
	return (sqrt(pow(quat->x, 2) + pow(quat->y, 2)
				+ pow(quat->z, 2) + pow(quat->w, 2)));
}
