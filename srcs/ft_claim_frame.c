/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_claim_frame.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 21:16:04 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/03 06:21:41 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image_frame	*ft_claim_image_frame(t_image_frame *frames)
{
	uint32_t	i;

	i = 0;
	while (i < NBR_IMAGE_FRAME)
	{
		if (frames[i].state == AVAILABLE)
		{
			frames[i].state = USED;
			return (frames + i);
		}
		i++;
		i %= 8;
	}
	return (frames);
}
