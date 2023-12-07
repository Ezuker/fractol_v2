/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:32:59 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/08 00:33:22 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 900
# define WIDTH 900
# include "./mlx-linux/mlx.h"
# include "./mlx-linux/mlx_int.h"
# include "./ft_printf/ft_printf.h"
# include "struct.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <math.h>

double		pow_2(t_complex z);
t_complex	mandelbrot_calcul(t_complex pixel, t_complex c);
int			get_color(double iter, t_data *data, t_complex pixel);
int			ft_hook(void *param);
int			ft_close(int keycode, void *param);
int			key_hook(int keycode, void *param);
int			mouse_hook(int button, int x, int y, void *param);
void		put_mandelbrot(t_data *data);
void		screen_to_world(t_coords_i screen, t_coords_d *world, t_data *data);
void		world_to_screen(t_coords_d world, t_coords_i *screen, t_data *data);
void		put_julia(t_data *data);
void		my_mlx_pixel_put(t_mlximg *data, int x, int y, int color);
void		put_burning_ship(t_data *data);
void		init(char **option, t_data *data);
void		change_view(t_data *data, int keycode);
void		update_zoom(t_data *data, t_coords_i mouse, int button);
void		change_offset(t_data *data, int keycode);
void		reset(t_data *data);
#endif
