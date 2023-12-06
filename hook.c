/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:57:51 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/06 12:59:15 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	put_mandelbrot(data);
	return (0);
}

int	ft_close(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)keycode;
	if (data->mlx)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
	}
	return (0);
}

int	key_hook(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	if (keycode == 65363)
		data->offset.x += (10.0 / data->zoom.factor_x);
	if (keycode == 65361)
		data->offset.x -= (10.0 / data->zoom.factor_x);
	if (keycode == 65364)
		data->offset.y += (10.0 / data->zoom.factor_y);
	if (keycode == 65362)
		data->offset.y -= (10.0 / data->zoom.factor_y);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_data		*data;
	t_coords_d	*mouse_after;
	t_coords_d	*mouse_before;
	t_coords_i	mouse;

	data = (t_data *)param;
	mouse.x = x;
	mouse.y = y;
	mouse_after = malloc(sizeof(t_coords_d));
	mouse_before = malloc(sizeof(t_coords_d));
	printf("%d %d\n", mouse.x, mouse.y);
	if (button == 4)
	{
		screen_to_world(mouse, mouse_before, data);
		data->zoom.factor_y *= 1.01;
		data->zoom.factor_x *= 1.01;
		screen_to_world(mouse, mouse_after, data);
		data->offset.x += (mouse_before->x - mouse_after->x);
		data->offset.y += (mouse_before->y - mouse_after->y);
	}
	else if (button == 5)
	{
		screen_to_world(mouse, mouse_before, data);
		data->zoom.factor_y *= 0.99;
		data->zoom.factor_x *= 0.99;
		screen_to_world(mouse, mouse_after, data);
		data->offset.x += (mouse_before->x - mouse_after->x);
		data->offset.y += (mouse_before->y - mouse_after->y);
	}
	printf("%f %f\n", data->offset.x, data->offset.y);
	printf("%f %f\n", data->zoom.factor_x, data->zoom.factor_y);
	free(mouse_after);
	free(mouse_before);
	return (0);
}
