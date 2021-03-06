/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 21:05:42 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/30 07:27:29 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_keycode_f	*ft_get_keycodes_f(void)
{
	static t_keycode_f	keycodes_f[] = {
		{ft_handler_esc, KEY_ESCAPE, 0},
		{ft_handler_right, KEY_RIGHT, 0},
		{ft_handler_left, KEY_LEFT, 0},
		{ft_handler_up, KEY_UP, 0},
		{ft_handler_down, KEY_DOWN, 0},
		{ft_handler_page_up, KEY_PAGE_UP, 0},
		{ft_handler_page_down, KEY_PAGE_DOWN, 0},
		{ft_handler_p, KEY_P, 0}, {ft_handler_r, KEY_R, 0}
		, {ft_handler_m, KEY_M, 0}, {ft_handler_t, KEY_T, 0}
		, {ft_handler_1, KEY_1, 0}, {ft_handler_2, KEY_2, 0},
		{ft_handler_4, KEY_4, 0},
		{ft_handler_5, KEY_5, 0},
		{ft_handler_3, KEY_3, 0},
		{ft_handler_6, KEY_6, 0},
		{ft_handler_7, KEY_7, 0},
		{ft_handler_pad_up, KEY_PAD_ADD, 0},
		{ft_handler_pad_down, KEY_PAD_SUB, 0}};

	if (sizeof(keycodes_f) / sizeof(t_keycode_f) != NBR_KEY_HOOKS)
		ft_error_exit(1, (char*[]){INVALID_KEYS_HOOKS_NBR}, EXIT_FAILURE);
	return (keycodes_f);
}

int					ft_handler_keys_release(int keycode
									, void __attribute__((unused)) *param)
{
	static t_keycode_f	*keycodes_f = NULL;
	uint32_t			i;

	i = 0;
	if (!keycodes_f)
		keycodes_f = ft_get_keycodes_f();
	while (i < NBR_KEY_HOOKS)
	{
		if (keycodes_f[i].keycode == keycode)
		{
			keycodes_f[i].used = 0;
			break ;
		}
		i++;
	}
	return (0);
}

int					ft_handler_keys(int keycode, void *param)
{
	static t_keycode_f	*keycodes_f = NULL;
	uint32_t			i;

	i = 0;
	if (!keycodes_f)
		keycodes_f = ft_get_keycodes_f();
	while (i < NBR_KEY_HOOKS)
	{
		if (keycodes_f[i].keycode == keycode)
		{
			keycodes_f[i].used = 1;
			break ;
		}
		i++;
	}
	i = 0;
	while (i < NBR_KEY_HOOKS)
	{
		if (keycodes_f[i].used)
			keycodes_f[i].f(param);
		i++;
	}
	return (0);
}
