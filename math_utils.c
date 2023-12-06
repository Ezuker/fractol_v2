/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:39:50 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/06 13:07:20 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	world_to_screen(t_coords_d world, t_coords_i *screen, t_data *data)
{
	screen->x = (int)(world.x - data->offset.x) * data->zoom.factor_x;
	screen->y = (int)(world.y - data->offset.y) * data->zoom.factor_y;
}

void	screen_to_world(t_coords_i screen, t_coords_d *world, t_data *data)
{
	world->x = (double)(screen.x) / data->zoom.factor_x + data->offset.x;
	world->y = (double)(screen.y) / data->zoom.factor_y + data->offset.y;
}
