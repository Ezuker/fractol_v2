/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:15:42 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/08 00:31:53 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_complex
{
	double	real;
	double	img;
}				t_complex;

typedef struct s_zoom
{
	double	x;
	double	y;
	double	factor_x;
	double	factor_y;
}				t_zoom;

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct s_coords_d
{
	double	x;
	double	y;
}				t_coords_d;

typedef struct s_coords_i
{
	int	x;
	int	y;
}			t_coords_i;

typedef struct s_mouse
{
	double	x;
	double	y;
}				t_mouse;

typedef struct s_mlximg
{
	void	*img;
	char	*addr;
	int		bit_pix;
	int		line_length;
	int		endian;
}				t_mlximg;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_win;
	char			*type;
	double			xmin;
	double			xmax;
	double			ymin;
	double			ymax;
	int				julia_freeze;
	int				mandelbrot_pow;
	t_zoom			zoom;
	t_color			color;
	t_complex		complex;
	t_coords_d		world;
	t_coords_i		screen;
	t_coords_d		offset;
	t_mlximg		mlx_img;
}				t_data;

#endif
