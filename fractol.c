/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:13:04 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/03 17:39:40 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	print_option(void)
{
	ft_printf("\033[38;2;255;0;0m	 _____               _   _       _\n");
	ft_printf("\033[38;2;255;128;0m	| ____|             | | ( )     | |\n");
	ft_printf("\033[38;2;255;255;0m	|__ _ __ __ _    ___| |_ \\| ___ | |\n");
	ft_printf("\033[38;2;128;255;0m	|  __| '__/ _` |/ __| __|  / _ \\| |\n");
	ft_printf("\033[38;2;0;255;0m	| |  | | | (_| | (__| |_  | (_) | |\n");
	ft_printf("\033[38;2;0;255;128m	|_|  |_|  \\__,_|\\___|\\__|  \\___/|_|\n");
	ft_printf("\033[38;2;20;100;20m\n");
	ft_printf("\n	Good usage -> ./fractol [Fractal Name]\n");
	ft_printf("\nChoose a fractal :\n\n");
	ft_printf(" => Mandelbrot\n");
	ft_printf(" => Julia\n");
	ft_printf(" => Other\n\n");
}



void	init(char *option, t_data *data)
{
	data->type = option;
	data->xmax = 1.6;
	data->xmin = -2.1;
	data->ymax = 1.2;
	data->ymin = -1.2;
	data->zoom.factor = 1.0;
	data->color.t = 0;
	data->color.r = 100;
	data->color.g = 34;
	data->color.b = 21;
	data->offset.x = 0.0;
	data->offset.y = 0.0;
}

void	put_pixel_mandelbrot(double x, double y, t_data *data)
{
	t_complex	pixel;
	t_complex	pixel_2;
	t_complex	c;
	double		i;

	pixel.real = 0;
	pixel.img = 0;
	pixel_2.real = 0;
	pixel_2.img = 0;
	c.real = (data->xmin + (x / WIDTH) * (data->xmax - data->xmin)) / data->zoom.factor;
	c.img = (data->ymin + (y / HEIGHT) * (data->ymax - data->ymin)) / data->zoom.factor;
	i = 0.0;
	while (i < 500.0 && (pixel_2.real + pixel_2.img) <= 4)
	{
		pixel.img = 2 * pixel.real * pixel.img + c.img;
		pixel.real = pixel_2.real - pixel_2.img + c.real;
		pixel_2.real = pixel.real * pixel.real;
		pixel_2.img = pixel.img * pixel.img;
		i++;
	}
	if (i == 500.0)
	{
		mlx_pixel_put(data->mlx, data->mlx_win, x - data->offset.x, y - data->offset.y, 0xFF000000);
		//mlx_pixel_put(data->mlx, data->mlx_win, x - data->offset.x, HEIGHT - y - data->offset.y, 0xFF000000);
	}
	else
	{
		mlx_pixel_put(data->mlx, data->mlx_win, x - data->offset.x, y - data->offset.y, get_color(i, data));
		//mlx_pixel_put(data->mlx, data->mlx_win, x - data->offset.x, HEIGHT - y - data->offset.y, get_color(i, data));
	}
}

void	put_mandelbrot(t_data *data)
{
	double	x;
	double	y;

	x = 0.0;
	y = 0.0;
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			put_pixel_mandelbrot(x, y, data);
			y++;
		}
		y = 0.0;
		x++;
	}
}

void	display_window(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract'ol");

	mlx_hook(data->mlx_win, 17, 0, ft_close, data);
	mlx_key_hook(data->mlx_win, key_hook, data);
	put_mandelbrot(data);
	mlx_mouse_hook(data->mlx_win, mouse_hook, data);
	mlx_loop_hook(data->mlx, ft_hook, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc >= 2 && (!ft_strcmp(argv[1], "Mandelbrot")
			|| !ft_strcmp(argv[1], "Julia")))
	{
		data = malloc(sizeof(t_data));
		init(argv[1], data);
		display_window(data);
	}
	else
	{
		print_option();
	}
	return (0);
}
