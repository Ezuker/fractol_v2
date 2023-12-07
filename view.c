/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:48:53 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/07 23:17:27 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	update_offset_zoom(t_data *data, t_coords_i mouse, double factor)
{
	t_coords_d	*mouse_after;
	t_coords_d	*mouse_before;

	mouse_after = malloc(sizeof(t_coords_d));
	mouse_before = malloc(sizeof(t_coords_d));
	screen_to_world(mouse, mouse_before, data);
	data->zoom.factor_y *= factor;
	data->zoom.factor_x *= factor;
	screen_to_world(mouse, mouse_after, data);
	data->offset.x += (mouse_before->x - mouse_after->x);
	data->offset.y += (mouse_before->y - mouse_after->y);
	free(mouse_after);
	free(mouse_before);
}

void	update_zoom(t_data *data, t_coords_i mouse, int button)
{
	if (button == 4)
		update_offset_zoom(data, mouse, 1.01);
	else if (button == 5)
		update_offset_zoom(data, mouse, 0.99);
}

void	change_view(t_data *data, int keycode)
{
	if (keycode == 109)
		data->type = "Mandelbrot";
	if (keycode == 106)
		data->type = "Julia";
	if (keycode == 98)
		data->type = "Burning ship";
	if (keycode == 114)
		init(data->type, data);
	if (keycode == 107)
		data->mandelbrot_pow += 1;
	if (keycode == 105)
		data->mandelbrot_pow -= 1;
	if (keycode == 116)
		data->color.r += 5;
	if (keycode == 121)
		data->color.g += 5;
	if (keycode == 117)
		data->color.b += 5;
}

void	change_offset(t_data *data, int keycode)
{
	if (keycode == 65363)
		data->offset.x += (10.0 / data->zoom.factor_x);
	if (keycode == 65361)
		data->offset.x -= (10.0 / data->zoom.factor_x);
	if (keycode == 65364)
		data->offset.y += (10.0 / data->zoom.factor_y);
	if (keycode == 65362)
		data->offset.y -= (10.0 / data->zoom.factor_y);
}
