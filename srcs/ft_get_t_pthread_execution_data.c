/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_t_pthread_execution_data.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 23:41:33 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/03 23:43:20 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pthread_execution_data	*ft_get_t_pthread_execution_data(void)
{
	static t_pthread_execution_data	pthread_data[NBR_DRAWING_THREAD];

	return (pthread_data);
}
