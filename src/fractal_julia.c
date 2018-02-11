/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 17:47:48 by vholovin          #+#    #+#             */
/*   Updated: 2017/06/24 19:53:28 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static t_pixel		julia(int iteration, t_pixel pixel, t_pixel axes_mouse)
{
	t_pixel	z;
	t_pixel	c;
	int		i;

	z = pixel;
	c = axes_mouse;
	i = 0;
	while (z.re * z.re + z.im * z.im < 256 && i < iteration)
	{
		pixel.re = z.re * z.re - z.im * z.im + c.re;
		pixel.im = z.re * z.im * 2 + c.im;
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

static void			axes_julia(t_struct *str)
{
	str->fractal->status_mouse = 1;
	str->fractal->axes->re_min = -3;
	str->fractal->axes->re_max = 3;
	str->fractal->axes->re_offset = 0;
	str->fractal->axes->im_min = -1.5;
	str->fractal->axes->im_max = 1.5;
	str->fractal->axes->im_offset = 0;
	str->fractal->axes->zoom = 1;
	str->fractal->set_axes = 0;
}

void				calculate_julia(t_struct *str)
{
	int	i;
	int	j;

	if (str->fractal->set_axes == 1)
		axes_julia(str);
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
			str->fractal->pixel[i][j] = julia(str->fractal->iteration,
					str->fractal->pixel[i][j], str->fractal->axes_mouse);
			j++;
		}
		i++;
	}
}
