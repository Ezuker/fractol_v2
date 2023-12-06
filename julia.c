/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:30:06 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/06 19:48:00 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_julia(double x, double y, t_data *data)
{
	t_complex	pixel;
	t_complex	pixel_old;
	double		i;
	double		temp_x;

	pixel_old.real = 0;
	pixel_old.img = 0;
	pixel.real = (data->xmin + (x / WIDTH) * (data->xmax - data->xmin));
	pixel.img = (data->ymin + (y / HEIGHT) * (data->ymax - data->ymin));
	i = 0.0;
	while (i < 50.0 && (pixel.real * pixel.real) + (pixel.img * pixel.img) <= 4.0)
	{
		temp_x = (pixel.real * pixel.real) - (pixel.img * pixel.img) + data->complex.real;
		pixel.img = 2.0 * pixel.real * pixel.img + data->complex.img;
		pixel.real = temp_x;
		i++;
		if (pixel.real == pixel_old.real && pixel.img == pixel_old.img)
			i = 50.0;
	}
	x = ((x - data->offset.x) * data->zoom.factor_x);
	y = ((y - data->offset.y) * data->zoom.factor_y);
	if (i == 50.0)
		my_mlx_pixel_put(&data->mlx_img, x, y, 0xFF000000);
	else
		my_mlx_pixel_put(&data->mlx_img, x, y, get_color(i, data));
}

void	put_julia(t_data *data)
{
	double	x;
	double	y;
	
	x = data->offset.x / data->zoom.factor_x;
	y = data->offset.y / data->zoom.factor_y;
	while (x < (WIDTH / data->zoom.factor_x + data->offset.x))
	{
		while (y < (HEIGHT / data->zoom.factor_y + data->offset.y))
		{
			put_pixel_julia(x, y, data);
			y += (1.0 / data->zoom.factor_y);
		}
		y = data->offset.y / data->zoom.factor_y;
		x += (1.0 / data->zoom.factor_x);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img.img, 0, 0);
}
