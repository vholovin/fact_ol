/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 17:25:55 by vholovin          #+#    #+#             */
/*   Updated: 2017/06/24 21:30:54 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int		ft_lerpi(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

static int		rgb_set(t_color c1, t_color c2, double p)
{
	t_color c;

	if (c1.value == c2.value)
		return (c1.value);
	c.rgb.r = (char)ft_lerpi((int)c1.rgb.r, (int)c2.rgb.r, p);
	c.rgb.g = (char)ft_lerpi((int)c1.rgb.g, (int)c2.rgb.g, p);
	c.rgb.b = (char)ft_lerpi((int)c1.rgb.b, (int)c2.rgb.b, p);
	return (c.value);
}

static int		gradienting(double grad_iter, int iteration, t_colors colors)
{
	double		index;
	double		control;
	int			k_color;

	if (colors.cycle)
		index = fmod(grad_iter, colors.cycle - 1) / (colors.cycle - 1);
	else
		index = grad_iter / iteration;
	k_color = colors.k_color - 1;
	control = fmod(index, 1.0 / k_color) * k_color;
	return (rgb_set(
			(t_color)(colors.colors[(int)(index * k_color) + 1]),
			(t_color)(colors.colors[(int)(index * k_color)]),
			(int)(control + 1) - control));
}

static int		smoothing(t_pixel pixel, int iteration, int status_color)
{
	double		grad_iter;
	t_colors	colors;

	if (pixel.real_iteration >= iteration)
		return (0x000000);
	else
	{
		colors = mods_of_colors(status_color);
		grad_iter = pixel.real_iteration + 1 -
		log((log(pixel.re * pixel.re + pixel.im * pixel.im) / 2) / log(2))
		/ log(2);
		if (grad_iter < 0)
			grad_iter = 0;
		return (gradienting(grad_iter, iteration, colors));
	}
}

int				set_color(t_pixel pixel, t_struct *str)
{
	double z_n;

	if (str->fractal->status_color == 1 && (pixel.re + pixel.im) / 2 > 1)
		return (0xFFFFFF);
	else if (str->fractal->status_color == 2)
	{
		z_n = sqrt(pow(pixel.re, 2) + pow(pixel.im, 2));
		if (z_n > 1 && z_n < 3 && ft_strcmp(str->fractal->name, "ship") == 0)
			return (0xFFFFFF);
		if (z_n > 2 && z_n < 32 && ft_strcmp(str->fractal->name, "ship") != 0)
			return (0xFFFFFF);
	}
	else if (str->fractal->status_color >= 3)
	{
		return (smoothing(pixel,
					str->fractal->iteration, str->fractal->status_color - 3));
	}
	return (0x000000);
}
