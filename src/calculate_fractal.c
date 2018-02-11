/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 17:17:06 by vholovin          #+#    #+#             */
/*   Updated: 2017/06/24 21:17:50 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	calculate_re_im(int i, int j, t_struct *str)
{
	str->fractal->pixel[i][j].im = str->fractal->axes->im_min
		+ str->fractal->axes->im_offset + str->fractal->axes->d_im
		* i * str->fractal->axes->zoom;
	str->fractal->pixel[i][j].re = str->fractal->axes->re_min
		+ str->fractal->axes->re_offset + str->fractal->axes->d_re
		* j * str->fractal->axes->zoom;
}

void	calculate_fractal(t_struct *str)
{
	if (ft_strcmp(str->fractal->name, "mandelbrot") == 0)
		calculate_mandelbrot(str);
	else if (ft_strcmp(str->fractal->name, "julia") == 0)
		calculate_julia(str);
	else if (ft_strcmp(str->fractal->name, "burningship") == 0)
		calculate_burningship(str);
	else if (ft_strcmp(str->fractal->name, "tricorn") == 0)
		calculate_tricorn(str);
	else if (ft_strcmp(str->fractal->name, "ship") == 0)
		calculate_ship(str);
}
