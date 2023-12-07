/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:02:48 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/07 18:48:54 by bcarolle         ###   ########.fr       */
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
	(void) data;

	iter = iter + 1 - (log(sqrt(pow(pixel.real, 2) + pow(pixel.img, 2))) / log (2));
	r = (unsigned char)(sin(0.017 * iter + 4) * 230 + 25);
	g = (unsigned char)(sin(0.113 * iter + 2) * 230 + 25);
	b = (unsigned char)(sin(0.01 * iter + 1) * 230 + 25);
	a = 255;

	return (a << 24 | r << 16 | g << 8 | b);
}
