/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:27:37 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/07 18:12:39 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_mandelbrot(double x, double y, t_data *data)
{
	t_complex	pixel;
	t_complex	pixel_old;
	t_complex	c;
	double		i;
	double		temp_x;

	pixel.real = 0;
	pixel.img = 0;
	pixel_old.real = 0;
	pixel_old.img = 0;
	c.real = (data->xmin + (x / WIDTH) * (data->xmax - data->xmin));
	c.img = (data->ymin + (y / HEIGHT) * (data->ymax - data->ymin));
	i = 0.0;
	while (i < 50.0 && (pixel.real * pixel.real) + (pixel.img * pixel.img) <= 4.0)
	{
		temp_x = (pixel.real * pixel.real) - (pixel.img * pixel.img) + c.real;
		pixel.img = 2.0 * pixel.real * pixel.img + c.img;
		pixel.real = temp_x;
		i++;
		if (pixel.real == pixel_old.real && pixel.img == pixel_old.img)
			i = 50.0;
	}
	if (i == 50.0)
		my_mlx_pixel_put(&data->mlx_img, (x - data->offset.x) * data->zoom.factor_x, (y - data->offset.y) * data->zoom.factor_y, 0xFF000000);
	else
		my_mlx_pixel_put(&data->mlx_img, (x - data->offset.x) * data->zoom.factor_x, (y - data->offset.y) * data->zoom.factor_y, get_color(i, data, pixel));
}

void	put_mandelbrot(t_data *data)
{
	double	x;
	double	y;

	x = data->offset.x / data->zoom.factor_x;
	y = data->offset.y / data->zoom.factor_y;
	while (x < (WIDTH / data->zoom.factor_x + data->offset.x))
	{
		while (y < (HEIGHT / data->zoom.factor_y + data->offset.y))
		{
			put_pixel_mandelbrot(x, y, data);
			y += (1.0 / data->zoom.factor_y);
		}
		y = data->offset.y / data->zoom.factor_y;
		x += (1.0 / data->zoom.factor_x);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img.img, 0, 0);
}
