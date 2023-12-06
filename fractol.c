/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:13:04 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/06 19:53:21 by bcarolle         ###   ########.fr       */
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
	ft_printf(" => \"Burning ship\"\n\n");
}

void	init(char *option, t_data *data)
{
	data->type = option;
	if (strcmp(option, "Julia") == 0)
	{
		data->complex.real = 1;
		data->complex.img = 1;
	}
	data->xmax = 1.6;
	data->xmin = -2.1;
	data->ymax = 1.2;
	data->ymin = -1.2;
	data->zoom.factor_x = 1.0;
	data->zoom.factor_y = 1.0;
	data->color.t = 0;
	data->color.r = 100;
	data->color.g = 34;
	data->color.b = 21;
	data->offset.x = 0.0;
	data->offset.y = 0.0;
}

void	display_window(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract'ol");
	data->mlx_img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->mlx_img.addr = mlx_get_data_addr(data->mlx_img.img, &data->mlx_img.bits_per_pixel, &data->mlx_img.line_length, &data->mlx_img.endian);

	mlx_hook(data->mlx_win, 17, 0, ft_close, data);
	mlx_key_hook(data->mlx_win, key_hook, data);
	mlx_mouse_hook(data->mlx_win, mouse_hook, data);
	mlx_loop_hook(data->mlx, ft_hook, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc >= 2 && (!ft_strcmp(argv[1], "Mandelbrot")
			|| !ft_strcmp(argv[1], "Julia") || !ft_strcmp(argv[1], "Burning ship")))
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
