/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 19:56:08 by vholovin          #+#    #+#             */
/*   Updated: 2017/06/24 21:22:38 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/src/libft.h"
# include "../minilibX/mlx.h"
# include <math.h>
# define W 1800
# define H 900

typedef struct		s_mouse
{
	char		button;
	int			x;
	int			y;
	int			last_x;
	int			last_y;
}					t_mouse;

typedef struct		s_rgb
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
}					t_rgb;

typedef union		u_color
{
	int			value;
	t_rgb		rgb;
}					t_color;

typedef struct		s_colors
{
	int			k_color;
	int			cycle;
	int			colors[16];
}					t_colors;

typedef struct		s_pixel
{
	double		re;
	double		im;
	int			real_iteration;
}					t_pixel;

typedef struct		s_axes
{
	double		re_min;
	double		re_max;
	double		re_offset;
	double		d_re;
	double		im_min;
	double		im_max;
	double		im_offset;
	double		d_im;
	double		zoom;
}					t_axes;

typedef struct		s_fractal
{
	char		*name;
	t_pixel		**pixel;
	t_axes		*axes;
	int			set_axes;
	int			iteration;
	int			status_color;
	int			status_mouse;
	t_pixel		axes_mouse;
}					t_fractal;

typedef struct		s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*ptr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			info;
}					t_mlx;

typedef struct		s_struct
{
	t_mlx		*mlx;
	t_fractal	*fractal;
	t_mouse		mouse;
}					t_struct;

t_struct			*init_struct(void);
t_fractal			*init_fractal(void);
void				error(int status);
void				calculate_fractal(t_struct *str);
void				calculate_re_im(int i, int j, t_struct *str);
void				calculate_mandelbrot(t_struct *str);
void				calculate_julia(t_struct *str);
void				calculate_burningship(t_struct *str);
void				calculate_tricorn(t_struct *str);
void				calculate_ship(t_struct *str);
int					set_color(t_pixel pixel, t_struct *str);
t_colors			mods_of_colors(int mod);
void				draw(t_struct *str);
t_axes				*zoom(int x, int y, t_axes *axes, double new_zoom);
int					key_hook(int keycode, t_struct *str);
int					mouse_zoom(int button, int x, int y, t_struct *str);
int					mouse_button(int button, int x, int y, t_struct *str);
int					mouse_move(int x, int y, t_struct *str);
int					expose_hook(t_struct *str);
void				mlx_put_pixel_to_image(int y, int x, int color, t_mlx *mlx);
void				tutorial(void);
#endif
