/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 21:05:42 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/26 23:09:47 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_handler_keys(int keycode, void *param)
{
	static t_keycode_f	keycodes_f[] = {
		{ft_handler_esc, KEY_ESCAPE, {0}},
		{ft_handler_right, KEY_RIGHT, {0}},
		{ft_handler_left, KEY_LEFT, {0}},
		{ft_handler_up, KEY_UP, {0}},
		{ft_handler_down, KEY_DOWN, {0}},
		{ft_handler_esc, KEY_ESCAPE, {0}}};
	uint32_t			i;

	i = 0;
	while (i < sizeof(keycodes_f) / sizeof(t_keycode_f))
	{
		if (keycodes_f[i].keycode == keycode)
			keycodes_f[i].f(param);
		i++;
	}
	return (0);
}
