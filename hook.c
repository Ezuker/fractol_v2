/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:57:51 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/03 17:29:14 by bcarolle         ###   ########.fr       */
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
	if (keycode == 100)
		data->offset.x += 10.0;
	if (keycode == 97)
		data->offset.x -= 10.0;
	if (keycode == 119)
		data->offset.y += 10.0;
	if (keycode == 115)
		data->offset.y -= 10.0;
	printf("Offset x = %f\n", data->offset.x);
	printf("Offset y = %f\n", data->offset.y);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)x;
	(void)y;
	if (button == 4)
		data->zoom.factor *= 1.02;
	else if (button == 5)
		data->zoom.factor *= 0.98;
	return (0);
}
