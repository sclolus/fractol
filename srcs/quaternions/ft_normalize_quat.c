/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_quat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 08:59:09 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/03 06:21:45 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_quat	ft_normalize_quat(t_quat *quat)
{
	double	magnitude;

	magnitude = ft_get_quat_magnitude(quat);
	return ((t_quat){quat->x / magnitude, quat->y / magnitude
				, quat->z / magnitude, quat->w / magnitude});
}
