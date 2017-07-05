/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_complexe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 06:52:58 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/03 06:54:47 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complexe	ft_add_complexe(t_complexe *z1, t_complexe *z2)
{
	return ((t_complexe){z1->real_part + z2->real_part
				, z1->imaginary_part + z2->imaginary_part});
}
