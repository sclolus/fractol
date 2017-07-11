/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_complexe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 20:11:50 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/08 20:13:49 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complexe	ft_pow_complexe(t_complexe *z, uint32_t degree)
{
	uint32_t	i;
	t_complexe	tmp;

	i = 0;
	tmp = *z;
	while (i < degree - 1)
	{
		tmp = ft_square_complexe(&tmp);
		i++;
	}
	return (tmp);
}
