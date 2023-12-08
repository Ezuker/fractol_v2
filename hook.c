/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:57:51 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/08 01:46:12 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_julia(t_data *data, int x1, int y1)
{
	double	x;
	double	y;

	x = (double)x1;
	y = (double)y1;
	x = x / WIDTH;
	y = y / HEIGHT;
	data->complex.real = x;
	data->complex.img = y;
}

int	ft_hook(void *param)
{
	t_data	*data;
	int		x;
	int		y;

	data = (t_data *)param;
	mlx_mouse_get_pos(data->mlx, data->mlx_win, &x, &y);
	if (ft_strcmp(data->type, "Mandelbrot") == 0)
		put_mandelbrot(data);
	else if (ft_strcmp(data->type, "Julia") == 0)
	{
		put_julia(data);
		if (data->julia_freeze == 1)
			change_julia(data, x, y);
	}
	else if (ft_strcmp(data->type, "Burning") == 0)
		put_burning_ship(data);
	else if (ft_strcmp(data->type, "Carolle") == 0)
		put_carolle(data);
	return (0);
}

int	ft_close(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)keycode;
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->mlx_img.img);
	mlx_destroy_display(data->mlx);
	free(data);
	exit(0);
	return (0);
}

int	key_hook(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 65307)
	{
		mlx_clear_window(data->mlx, data->mlx_win);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_image(data->mlx, data->mlx_img.img);
		free(data);
		exit(0);
	}
	if (keycode == 32 && data->julia_freeze == 0)
		data->julia_freeze = 1;
	else if (keycode == 32 && data->julia_freeze == 1)
		data->julia_freeze = 0;
	change_view(data, keycode);
	change_offset(data, keycode);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_data		*data;
	t_coords_i	mouse;

	data = (t_data *)param;
	mouse.x = x;
	mouse.y = y;
	update_zoom(data, mouse, button);
	return (0);
}
