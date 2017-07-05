/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_complexe_magnitude.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 07:54:39 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/03 07:56:39 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_get_complexe_magnitude(t_complexe *z)
{
	return (sqrt(pow(z->real_part, 2) + pow(z->imaginary_part, 2)));
}
