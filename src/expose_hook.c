/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 17:19:10 by vholovin          #+#    #+#             */
/*   Updated: 2017/06/24 21:21:58 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	print_info(t_mlx *mlx, int color)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
			10, 50, color, "Mandelbrot:m     Julia:j");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
			10, 65, color, "Burningship:b    Tricorn:t");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 80, color, "Ship:s");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 95, color, "Move:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
			10, 110, color, "Up:up       Down:down");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
			10, 125, color, "Left:left   Righ:right");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 140, color, "Zoom:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 155, color, "Small:-/+");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 170, color, "Big:  [/]");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 185, color, "Iteration:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
			10, 200, color, "Up:>   Down:<");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 215, color, "Color:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
			10, 230, color, "Choose mode: 1 - 7");
}

static void	draw_information(t_mlx *mlx, char *name, int iteration, int color)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
			10, 5, color, name);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
			10, 20, color, "Iteration:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
			110, 20, color, ft_itoa(iteration));
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
			10, 35, color, "Close/Open info:~   Reset:r");
	if (mlx->info == 1)
		print_info(mlx, color);
}

void		mlx_put_pixel_to_image(int y, int x, int color, t_mlx *mlx)
{
	unsigned int	new_color;
	int				i;

	new_color = mlx_get_color_value(mlx->mlx_ptr, color);
	i = x * 4 + y * mlx->size_line;
	mlx->ptr[i] = (new_color & 0xFF);
	mlx->ptr[i + 1] = (new_color & 0xFF00) >> 8;
	mlx->ptr[i + 2] = (new_color & 0xFF0000) >> 16;
}

void		draw(t_struct *str)
{
	int	i;
	int	j;

	i = 0;
	while (i < H)
	{
		j = 0;
		while (j < W)
		{
			mlx_put_pixel_to_image(i, j,
			set_color(str->fractal->pixel[i][j], str), str->mlx);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(str->mlx->mlx_ptr, str->mlx->win_ptr,
			str->mlx->img_ptr, 0, 0);
	draw_information(str->mlx, str->fractal->name, str->fractal->iteration,
			0xAAAAAA);
}

int			expose_hook(t_struct *str)
{
	draw(str);
	return (0);
}
