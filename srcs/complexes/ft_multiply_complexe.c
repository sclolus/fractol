/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiply_complexe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 06:34:03 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/03 06:51:55 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complexe	ft_multiply_complexe(t_complexe *z1, t_complexe *z2)
{
	t_complexe	z3;

	z3.real_part = z1->real_part * z2->real_part + (-(z1->imaginary_part * z2->imaginary_part));
	z3.imaginary_part = z1->imaginary_part * z2->real_part + z2->imaginary_part * z1->real_part;
	return (z3);
}
