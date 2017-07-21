/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tracking_mouse_data.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 03:37:28 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/21 09:24:10 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint8_t	*ft_get_tracking_mouse_data(void)
{
	static uint8_t	tracking_data[SUPPORTED_FRACTAL_NBR] = {
		0, 1, 1, 1, 0};

	return (tracking_data);
}
