/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_complexe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 06:48:06 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/03 06:54:14 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complexe	ft_square_complexe(t_complexe *z1)
{
	return ((t_complexe){z1->real_part * z1->real_part - (z1->imaginary_part
		* z1->imaginary_part), 2 * z1->real_part * z1->imaginary_part});
}
