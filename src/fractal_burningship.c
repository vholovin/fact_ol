/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_burningship.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 17:47:52 by vholovin          #+#    #+#             */
/*   Updated: 2017/06/24 19:55:43 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static t_pixel		burningship(int iteration, t_pixel pixel)
{
	t_pixel z;
	t_pixel c;
	int		i;

	z = pixel;
	c = z;
	i = 0;
	while (z.re * z.re + z.im * z.im < 256 && i < iteration)
	{
		z.re = fabs(z.re);
		z.im = fabs(z.im);
		pixel.re = z.re * z.re - z.im * z.im + c.re;
		pixel.im = 2 * z.re * z.im + c.im;
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

static void			axes_burningship(t_struct *str)
{
	str->fractal->status_mouse = 0;
	str->fractal->axes->re_min = -2.5;
	str->fractal->axes->re_max = 2.5;
	str->fractal->axes->re_offset = -0.25;
	str->fractal->axes->im_min = -1.25;
	str->fractal->axes->im_max = 1.25;
	str->fractal->axes->im_offset = -0.5;
	str->fractal->axes->zoom = 1;
	str->fractal->set_axes = 0;
}

void				calculate_burningship(t_struct *str)
{
	int i;
	int j;

	if (str->fractal->set_axes == 1)
		axes_burningship(str);
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
			str->fractal->pixel[i][j] = burningship(
					str->fractal->iteration, str->fractal->pixel[i][j]);
			j++;
		}
		i++;
	}
}
