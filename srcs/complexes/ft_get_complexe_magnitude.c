/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_complexe_magnitude.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 07:54:39 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/15 00:51:24 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_get_complexe_magnitude(t_complexe *z)
{
	return ((double)sqrt(pow((double)z->real_part, 2) + (double)pow((double)z->imaginary_part, 2)));
}
