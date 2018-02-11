/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 17:21:55 by vholovin          #+#    #+#             */
/*   Updated: 2017/06/24 21:04:14 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void		key_hook_reset(int keycode, t_struct *str)
{
	if (keycode == 15)
		str->fractal = init_fractal();
}

static void		key_hook_status_color(int keycode, t_struct *str)
{
	if (keycode == 18)
		str->fractal->status_color = 1;
	else if (keycode == 19)
		str->fractal->status_color = 2;
	else if (keycode == 20)
		str->fractal->status_color = 3;
	else if (keycode == 21)
		str->fractal->status_color = 4;
	else if (keycode == 23)
		str->fractal->status_color = 5;
	else if (keycode == 22)
		str->fractal->status_color = 6;
	else if (keycode == 26)
		str->fractal->status_color = 7;
}

static void		key_hook_fractal_iteration(int keycode, t_struct *str)
{
	if (keycode == 43 && str->fractal->iteration > 1)
		str->fractal->iteration -= 1;
	else if (keycode == 47)
		str->fractal->iteration += 1;
	else if (keycode == 46)
		str->fractal->name = "mandelbrot";
	else if (keycode == 38)
		str->fractal->name = "julia";
	else if (keycode == 11)
		str->fractal->name = "burningship";
	else if (keycode == 17)
		str->fractal->name = "tricorn";
	else if (keycode == 1)
		str->fractal->name = "ship";
	if (keycode == 46 || keycode == 38 || keycode == 11 || keycode == 17
			|| keycode == 1)
		str->fractal->set_axes = 1;
}

static void		key_hook_move_zoom(int keycode, t_struct *str)
{
	if (keycode == 123)
		str->fractal->axes->re_offset -= (0.1 * str->fractal->axes->zoom);
	else if (keycode == 124)
		str->fractal->axes->re_offset += (0.1 * str->fractal->axes->zoom);
	else if (keycode == 125)
		str->fractal->axes->im_offset += (0.1 * str->fractal->axes->zoom);
	else if (keycode == 126)
		str->fractal->axes->im_offset -= (0.1 * str->fractal->axes->zoom);
	else if (keycode == 24)
		str->fractal->axes = zoom(W / 2, H / 2, str->fractal->axes, 0.9);
	else if (keycode == 27)
		str->fractal->axes = zoom(W / 2, H / 2, str->fractal->axes, 1.1);
	else if (keycode == 30)
		str->fractal->axes = zoom(W / 2, H / 2, str->fractal->axes, 0.5);
	else if (keycode == 33)
		str->fractal->axes = zoom(W / 2, H / 2, str->fractal->axes, 2);
}

int				key_hook(int keycode, t_struct *str)
{
	if (keycode == 50)
	{
		if (str->mlx->info == 1)
			str->mlx->info = 0;
		else
			str->mlx->info = 1;
	}
	if (keycode == 53)
	{
		mlx_destroy_window(str->mlx->mlx_ptr, str->mlx->win_ptr);
		exit(0);
	}
	key_hook_move_zoom(keycode, str);
	key_hook_fractal_iteration(keycode, str);
	key_hook_status_color(keycode, str);
	key_hook_reset(keycode, str);
	calculate_fractal(str);
	draw(str);
	return (0);
}
