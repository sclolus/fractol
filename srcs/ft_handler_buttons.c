/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_buttons.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 18:45:57 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/11 06:54:59 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_keycode_f	*ft_get_buttoncodes_f(void)
{
	static t_keycode_f	keycodes_f[] = {
		{ft_handler_button5, Button5, 0},
		{ft_handler_button4, Button4, 0}};

	if (sizeof(keycodes_f) / sizeof(t_keycode_f) != NBR_BUTTON_HOOKS)
		ft_error_exit(1, (char*[]){INVALID_BUTTONS_HOOKS_NBR}, EXIT_FAILURE);
	return (keycodes_f);
}

int			ft_handler_buttons_release(int keycode, void *param __attribute__((unused)))
{
	static t_keycode_f	*keycodes_f = NULL;
	uint32_t			i;

	i = 0;
	if (!keycodes_f)
		keycodes_f = ft_get_buttoncodes_f();
	while (i < NBR_BUTTON_HOOKS)
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

int			ft_handler_buttons(int keycode, int x, int y, void *param)
{
	static t_keycode_f	*keycodes_f = NULL;
	uint32_t			i;
	uint32_t			boolean;

	i = 0;
	if (!keycodes_f)
		keycodes_f = ft_get_buttoncodes_f();
	printf("%d: \n", keycode);
	while (i < NBR_BUTTON_HOOKS)
	{
		if (keycodes_f[i].keycode == keycode)
		{
			keycodes_f[i].used = 1;
			break ;
		}
		i++;
	}
	i = 0;
	boolean = 0;
	while (i < NBR_BUTTON_HOOKS)
	{
		if (keycodes_f[i].used)
		{
			keycodes_f[i].f(x, y, param);
			boolean = 1;
		}
		i++;
		if (i == NBR_BUTTON_HOOKS && !boolean)
			break ;
	}
	return (0);
}
