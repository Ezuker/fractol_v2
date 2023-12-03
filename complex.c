/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:02:48 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/03 15:50:16 by bcarolle         ###   ########.fr       */
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

u_int32_t	get_color(double iter, t_data *data)
{
	u_int8_t	r = ((data->color.r / iter) * 255);
	u_int8_t	g = ((data->color.g / iter) * 255);
	u_int8_t	b = ((data->color.b / iter) * 255);
	u_int8_t	a = data->color.t;

	return ((a << 24) | (r << 16) | (g << 8) | b);
}
