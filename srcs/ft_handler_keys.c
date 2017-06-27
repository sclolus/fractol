/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 21:05:42 by sclolus           #+#    #+#             */
/*   Updated: 2017/06/27 12:18:54 by sclolus          ###   ########.fr       */
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
		{ft_handler_pad_multiply, KEY_PAD_MULTIPLY, {0}},
		{ft_handler_pad_divide, KEY_PAD_DIVIDE, {0}},
		{ft_handler_q, KEY_Q, {0}},
		{ft_handler_a, KEY_A, {0}},
		{ft_handler_d, KEY_D, {0}},
		{ft_handler_w, KEY_W, {0}},
		{ft_handler_s, KEY_S, {0}},
		{ft_handler_e, KEY_E, {0}},
		{ft_handler_pad_up, KEY_PAD_ADD, {0}},
		{ft_handler_pad_down, KEY_PAD_SUB, {0}}};
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
