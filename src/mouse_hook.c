/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 17:24:53 by vholovin          #+#    #+#             */
/*   Updated: 2017/06/24 17:25:38 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	re_im_mouse(int x, int y, t_struct *str)
{
	str->fractal->axes_mouse.re = str->fractal->axes->re_min
	+ str->fractal->axes->re_offset + str->fractal->axes->d_re
	* x * str->fractal->axes->zoom;
	str->fractal->axes_mouse.im = str->fractal->axes->im_min
	+ str->fractal->axes->im_offset + str->fractal->axes->d_im
	* y * str->fractal->axes->zoom;
}

int			mouse_zoom(int button, int x, int y, t_struct *str)
{
	if ((x >= 0 && x <= W) && (y >= 0 && y <= H))
	{
		if (button == 4)
		{
			zoom(x, y, str->fractal->axes, 0.9);
			calculate_fractal(str);
			draw(str);
		}
		else if (button == 5)
		{
			zoom(x, y, str->fractal->axes, 1.1);
			calculate_fractal(str);
			draw(str);
		}
		str->mouse.button |= 1 << button;
	}
	return (0);
}

int			mouse_button(int button, int x, int y, t_struct *str)
{
	(void)x;
	(void)y;
	str->mouse.button &= ~(1 << button);
	return (0);
}

int			mouse_move(int x, int y, t_struct *str)
{
	str->mouse.last_x = str->mouse.x;
	str->mouse.last_y = str->mouse.y;
	str->mouse.x = x;
	str->mouse.y = y;
	if ((x >= 0 && x <= W) && (y >= 0 && y <= H) && str->fractal->status_mouse)
		re_im_mouse(x, y, str);
	if (str->mouse.button & (1 << 1))
	{
		str->fractal->axes->re_offset += ((str->mouse.last_x - str->mouse.x)
		* str->fractal->axes->d_re * str->fractal->axes->zoom);
		str->fractal->axes->im_offset += ((str->mouse.last_y - str->mouse.y)
		* str->fractal->axes->d_im * str->fractal->axes->zoom);
	}
	calculate_fractal(str);
	draw(str);
	return (0);
}
