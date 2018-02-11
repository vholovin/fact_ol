/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tutorial.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:56:54 by vholovin          #+#    #+#             */
/*   Updated: 2017/06/24 21:06:30 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	tutorial(void)
{
	ft_putstr("\
____________________________\n\
CONTROLS:\n\
Fractol:\n\
	Mandelbrot:     Key: m\n	Julia:          Key: j\n\
	Burnungship:    Key: b\n	Tricorn:        Key: t\n\
	Ship:           Key: s\n\
Move:\n\
	Up:             Key: up\n\
	Down:           Key: down\n\
	Left:           Key: left\n\
	Righ:           Key: right\n\
Zoom:\n\
	Small zoom +:   Key: +\n	Small zoom -:   Key: -\n\
	Big zoom +:     Key: [\n	Big zoom -:     Key: ]\n\
Iteration:\n\
	Up iter:        Key: >\n	Down iter:      key: <\n\
Color:\n\
	Choose mode:    Key: 1 - 7\n\
\n\
	Reset:          Key: r\n\
\n\
____________________________\n\
");
}
