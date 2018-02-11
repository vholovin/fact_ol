/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods_of_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 17:23:39 by vholovin          #+#    #+#             */
/*   Updated: 2017/06/24 17:24:33 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_colors	mods_of_colors(int mod)
{
	t_colors	colors[5];

	colors[0] =
	(t_colors){16, 2, {0x000000, 0x111111, 0x222222, 0x333333, 0x444444,
		0x555555, 0x666666, 0x777777, 0x888888, 0x999999, 0xAAAAAA, 0xBBBBBB,
		0xCCCCCC, 0xDDDDDD, 0xEEEEEE, 0xFFFFFF}};
	colors[1] =
	(t_colors){16, 10, {0x000000, 0x110000, 0x220000, 0x330000, 0x440000,
		0x5500000, 0x660000, 0x770000, 0x880000, 0x990000, 0xAA0000, 0xBB0000,
		0xCC0000, 0xDD0000, 0xEE0000, 0xFF0000}};
	colors[2] =
	(t_colors){5, 0, {0x7F1637, 0x047878, 0xFFB733, 0xF57336, 0xC22121}};
	colors[3] =
	(t_colors){6, 0, {0xFFFFFF, 0xE7D8F7, 0xA748FC, 0x6A00D0, 0x4A0095,
		0x330065}};
	colors[4] =
	(t_colors){7, 2, {0xFF0000, 0xFFFF00, 0x00FF00, 0x00FFFF, 0x0000FF,
		0xFF00FF, 0xFF0000}};
	return (colors[mod]);
}
