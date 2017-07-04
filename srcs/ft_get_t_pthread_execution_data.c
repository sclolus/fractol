/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_t_pthread_execution_data.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 23:41:33 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/04 03:43:04 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pthread_execution_data	*ft_get_t_pthread_execution_data(void)
{
	static t_pthread_execution_data	pthread_data[DRAWING_THREAD_NBR + 1];

	return (pthread_data);
}
