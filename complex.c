/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:02:48 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/07 23:25:34 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	pow_2(t_complex z)
{
	return (z.real * z.real + (z.img * z.img));
}

t_complex	mandelbrot_calcul(t_complex pixel, t_complex c)
{
	t_complex	result;

	result.real = (pixel.real * pixel.real) - (pixel.img * pixel.img) + c.real;
	result.img = 2 * pixel.real * pixel.img + c.img;
	return (result);
}

int	get_color(double iter, t_data *data, t_complex pixel)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
	double			result_log;

	result_log = log(sqrt(pow(pixel.real, 2.0) + pow(pixel.img, 2.0)));
	iter = iter + 1.0 - result_log / log (2.0);
	r = (unsigned char)(sin(0.017 * iter + 4.0) * data->color.r + 25.0);
	g = (unsigned char)(sin(0.113 * iter + 2.0) * data->color.g + 25.0);
	b = (unsigned char)(sin(0.01 * iter + 1.0) * data->color.b + 25.0);
	a = 255.0;
	return (a << 24 | r << 16 | g << 8 | b);
}
