/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:02:48 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/06 18:14:43 by bcarolle         ###   ########.fr       */
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

int	get_color(double iter, t_data *data)
{
	int	r = ((data->color.r / iter) * 255);
	int	g = ((data->color.g / iter) * 255);
	int	b = ((data->color.b / iter) * 255);
	int	a = data->color.t;

	return ((a << 24) | (r << 16) | (g << 8) | b);
}
