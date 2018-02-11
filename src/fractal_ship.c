/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 17:37:16 by vholovin          #+#    #+#             */
/*   Updated: 2017/06/24 21:09:27 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static t_pixel		ship(int iteration, t_pixel pixel)
{
	t_pixel z;
	int		i;

	z = pixel;
	i = 0;
	while (z.re * z.re + z.im * z.im < 4 && i < iteration)
	{
		pixel.re = z.re - (z.re * z.re * z.re - 3 * z.re * z.im * z.im - 1);
		pixel.im = z.im - (3 * z.re * z.re * z.im - z.im * z.im * z.im);
		if (z.re == pixel.re && z.im == pixel.im)
		{
			i = iteration;
			break ;
		}
		z = pixel;
		i++;
	}
	pixel = z;
	pixel.real_iteration = i;
	return (pixel);
}

static void			axes_ship(t_struct *str)
{
	str->fractal->status_mouse = 0;
	str->fractal->axes->re_min = -2;
	str->fractal->axes->re_max = 2;
	str->fractal->axes->re_offset = 0;
	str->fractal->axes->im_min = -1;
	str->fractal->axes->im_max = 1;
	str->fractal->axes->im_offset = 0;
	str->fractal->axes->zoom = 1;
	str->fractal->set_axes = 0;
}

void				calculate_ship(t_struct *str)
{
	int i;
	int	j;

	if (str->fractal->set_axes == 1)
		axes_ship(str);
	str->fractal->axes->d_re = (str->fractal->axes->re_max
	- str->fractal->axes->re_min) / W;
	str->fractal->axes->d_im = (str->fractal->axes->im_max
	- str->fractal->axes->im_min) / H;
	i = 0;
	while (i < H)
	{
		j = 0;
		while (j < W)
		{
			calculate_re_im(i, j, str);
			str->fractal->pixel[i][j] = ship(
					str->fractal->iteration, str->fractal->pixel[i][j]);
			j++;
		}
		i++;
	}
}
