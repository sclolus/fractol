/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_random_filename.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 05:29:21 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/29 05:30:21 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline void	ft_normalize_random_filename(char *filename)
{
	uint32_t	i;

	i = 0;
	while (filename[i])
	{
		if (!ft_isprint(filename[i]))
			filename[i] = (char)(ABS(filename[i]) % (128 - ' ')) + ' ';
		i++;
	}
}
