/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthread_wait_drawing_threads.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 18:09:54 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/03 06:21:45 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pthread_wait_drawing_threads(pthread_t *thread_tab)
{
	uint32_t	i;
	void		*return_status;

	i = 0;
	while (i < DRAWING_THREAD_NBR)
	{
		pthread_join(thread_tab[i], &return_status);
		i++;
	}
}
