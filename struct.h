/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:15:42 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/03 16:30:14 by bcarolle         ###   ########.fr       */
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
	double	factor;
}				t_zoom;

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct s_coords
{
	double	x;
	double	y;
}				t_coords;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	char		*type;
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	t_zoom		zoom;
	t_color		color;
	t_complex	complex;
	t_coords	world;
	t_coords	screen;
	t_coords	offset;
}				t_data;

#endif
