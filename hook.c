/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:57:51 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/07 19:30:39 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_julia(t_data *data, int x1, int y1)
{
	double	x;
	double	y;

	x = (double)x1;
	y = (double)y1;
	// if (x < WIDTH / 2)
	// 	x = -x;
	// if (y < HEIGHT / 2)
	// 	y = -y;
	x = x / WIDTH;
	y = y / HEIGHT;
	printf("%f %f\n", x, y);
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
		change_julia(data, x, y);
	}
	else if (ft_strcmp(data->type, "Burning ship") == 0)
		put_burning_ship(data);
	return (0);
}

int	ft_close(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)keycode;
	if (data->mlx)
	{
		mlx_clear_window(data->mlx, data->mlx);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_image(data->mlx, data->mlx_img.img);
		free(data);
		exit(0);
	}
	return (0);
}

void	change_view(t_data *data, int keycode)
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

int	key_hook(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 65307)
	{
		mlx_clear_window(data->mlx, data->mlx);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_image(data->mlx, data->mlx_img.img);
		free(data);
		exit(0);
	}
	change_view(data, keycode);
	return (0);
}

static void	update_zoom(t_data *data, t_coords_i mouse, int button)
{
	t_coords_d	*mouse_after;
	t_coords_d	*mouse_before;

	mouse_after = malloc(sizeof(t_coords_d));
	mouse_before = malloc(sizeof(t_coords_d));
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
	free(mouse_after);
	free(mouse_before);
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
