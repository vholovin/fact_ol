/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 17:23:07 by vholovin          #+#    #+#             */
/*   Updated: 2017/06/24 17:23:09 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		main(void)
{
	t_struct	*str;

	tutorial();
	str = init_struct();
	calculate_fractal(str);
	mlx_hook(str->mlx->win_ptr, 2, 5, key_hook, str);
	mlx_hook(str->mlx->win_ptr, 4, 1L << 2, mouse_zoom, str);
	mlx_hook(str->mlx->win_ptr, 5, 1L << 3, mouse_button, str);
	mlx_hook(str->mlx->win_ptr, 6, 1L << 6, mouse_move, str);
	mlx_expose_hook(str->mlx->win_ptr, expose_hook, str);
	mlx_loop(str->mlx->mlx_ptr);
	return (0);
}
