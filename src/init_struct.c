/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 17:20:38 by vholovin          #+#    #+#             */
/*   Updated: 2017/06/24 20:24:51 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_fractal		*init_fractal(void)
{
	t_fractal	*fractal;
	int			i;

	if (!(fractal = (t_fractal*)malloc(sizeof(t_fractal))) ||
		!(fractal->axes = (t_axes*)malloc(sizeof(t_axes))) ||
		!(fractal->pixel = (t_pixel**)malloc(sizeof(t_pixel) * H + 1)))
		error(0);
	i = 0;
	while (i < H)
	{
		if (!(fractal->pixel[i] = (t_pixel*)malloc(sizeof(t_pixel) * W + 1)))
			error(0);
		i++;
	}
	fractal->name = "mandelbrot";
	fractal->iteration = 32;
	fractal->status_color = 6;
	fractal->status_mouse = 0;
	fractal->set_axes = 1;
	return (fractal);
}

static t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		error(0);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, W, H, "42");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, W, H);
	mlx->ptr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel,
			&mlx->size_line, &mlx->endian);
	mlx->info = 1;
	return (mlx);
}

t_struct		*init_struct(void)
{
	t_struct	*str;

	if (!(str = (t_struct*)malloc(sizeof(t_struct))))
		error(0);
	str->mlx = init_mlx();
	str->fractal = init_fractal();
	str->mouse.button = 0;
	return (str);
}
