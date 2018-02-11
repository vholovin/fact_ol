/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 17:31:54 by vholovin          #+#    #+#             */
/*   Updated: 2017/06/24 17:32:01 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_axes		*zoom(int x, int y, t_axes *axes, double new_zoom)
{
	double w;
	double h;
	double new_w;
	double new_h;

	w = (axes->re_max - axes->re_min) * (axes->zoom);
	h = (axes->im_max - axes->im_min) * (axes->zoom);
	new_w = (axes->re_max - axes->re_min) * (axes->zoom * new_zoom);
	new_h = (axes->im_max - axes->im_min) * (axes->zoom * new_zoom);
	axes->zoom *= new_zoom;
	axes->re_offset -= ((double)x / W) * (new_w - w);
	axes->im_offset -= ((double)y / H) * (new_h - h);
	return (axes);
}
