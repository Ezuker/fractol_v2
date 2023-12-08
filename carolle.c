/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carolle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:27:37 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/08 02:05:38 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_divide(t_complex a, t_complex b)
{
	t_complex	result;
	double		denominator;

	if (b.real == 0.0 && b.img == 0.0)
	{
		result.real = 0.0;
		result.img = 0.0;
		return (result);
	}
	denominator = (b.real * b.real) + (b.img * b.img);
	result.real = (a.real * b.real + a.img * b.img) / denominator;
	result.img = (a.img * b.real - a.real * b.img) / denominator;
	return (result);
}

t_complex	cos_complex(t_complex z)
{
	t_complex	result;

	result.real = cos(z.real) * cosh(z.img);
	result.img = -sin(z.real) * sinh(z.img);
	return (result);
}

void	put_pixel_carolle(double x, double y, t_data *data)
{
	t_complex	pixel;
	t_complex	pixel_old;
	t_complex	c;
	double		i;

	pixel.real = 0;
	pixel.img = 0;
	pixel_old.real = 0;
	pixel_old.img = 0;
	c.real = (data->xmin + (x / WIDTH) * (data->xmax - data->xmin));
	c.img = (data->ymin + (y / HEIGHT) * (data->ymax - data->ymin));
	i = 0.0;
	while (i < 50.0 && pow(pixel.real, 2) + pow(pixel.img, 2) <= 4.0)
	{
		pixel = cos_complex(complex_divide(pixel, c));
		i++;
		if (pixel.real == pixel_old.real && pixel.img == pixel_old.img)
			i = 50.0;
	}
	x = (x - data->offset.x) * data->zoom.factor_x;
	y = (y - data->offset.y) * data->zoom.factor_y;
	if (i == 50.0)
		my_mlx_pixel_put(&data->mlx_img, x, y, 0xFF000000);
	else
		my_mlx_pixel_put(&data->mlx_img, x, y, get_color(i, data, pixel));
}

void	put_carolle(t_data *data)
{
	double	x;
	double	y;

	x = data->offset.x / data->zoom.factor_x;
	y = data->offset.y / data->zoom.factor_y;
	while (x < (WIDTH / data->zoom.factor_x + data->offset.x))
	{
		while (y < (HEIGHT / data->zoom.factor_y + data->offset.y))
		{
			put_pixel_carolle(x, y, data);
			y += (1.0 / data->zoom.factor_y);
		}
		y = data->offset.y / data->zoom.factor_y;
		x += (1.0 / data->zoom.factor_x);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img.img, 0, 0);
}
