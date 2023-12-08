/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:13:04 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/08 18:23:56 by bcarolle         ###   ########.fr       */
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
	ft_printf(" => Burning ship\n");
	ft_printf(" => Carolle\n\n");
	ft_printf("Keys :\n\n");
	ft_printf("  M -> Mandelbrot\n");
	ft_printf("  J -> Julia\n");
	ft_printf("  B -> Burning Ship\n");
	ft_printf("  C -> Carolle\n");
	ft_printf("  K -> Add power Mandelbrot\n");
	ft_printf("  I -> Decrease power Mandelbrot\n");
	ft_printf("SPACE -> Enable / Disable Julia Animation\n");
	ft_printf("  T -> Change color R\n");
	ft_printf("  Y -> Change color G\n");
	ft_printf("  U -> Change color B\n\n");
}

void	init(char **option, t_data *data, int argc)
{
	data->type = option[1];
	if (!strcmp(option[1], "Julia") && argc == 4)
	{
		data->complex.real = ft_atof(option[2]);
		data->complex.img = ft_atof(option[3]);
	}
	else
	{
		data->complex.real = 1.0;
		data->complex.img = 1.0;
	}
	data->xmax = 1.6;
	data->xmin = -2.1;
	data->ymax = 1.2;
	data->ymin = -1.2;
	data->zoom.factor_x = 1.0;
	data->zoom.factor_y = 1.0;
	data->color.t = 0;
	data->color.r = 230;
	data->color.g = 230;
	data->color.b = 230;
	data->offset.x = 0.0;
	data->offset.y = 0.0;
	data->julia_freeze = 0;
	data->mandelbrot_pow = 2;
}

void	display_window(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract'ol");
	data->mlx_img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->mlx_img.addr = mlx_get_data_addr(data->mlx_img.img,
			&data->mlx_img.bit_pix,
			&data->mlx_img.line_length,
			&data->mlx_img.endian);
	mlx_key_hook(data->mlx_win, key_hook, data);
	mlx_hook(data->mlx_win, 17, 0, ft_close, data);
	mlx_mouse_hook(data->mlx_win, mouse_hook, data);
	mlx_loop_hook(data->mlx, ft_hook, data);
	mlx_loop(data->mlx);
}

int	check_args(char **argv, int argc)
{
	if (!ft_strcmp(argv[1], "Mandelbrot"))
		return (1);
	if (!ft_strcmp(argv[1], "Julia"))
		return (1);
	if (!ft_strcmp(argv[1], "Carolle"))
		return (1);
	if (argc == 3)
	{
		if (!ft_strcmp(argv[1], "Burning") && !ft_strcmp(argv[2], "ship"))
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc >= 2 && check_args(argv, argc))
	{
		data = malloc(sizeof(t_data));
		init(argv, data, argc);
		display_window(data);
		free(data);
	}
	else
	{
		print_option();
	}
	return (0);
}
