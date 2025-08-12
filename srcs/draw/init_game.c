/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:56:41 by yurwang           #+#    #+#             */
/*   Updated: 2025/08/12 21:42:38 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//the function is used to set the first ray's direction vector
int	init_ray(t_data *data)
{
	double	distance;

	distance = 0;
	printf("HERE X!!! %f\n", data->player.dir_x);
	printf("HERE Y!!! %f\n", data->player.dir_y);
	data->ray.dir_x = data->player.dir_x * cos(-to_rad(FOV_ANGLE) / 2)
		- data->player.dir_y * sin(-to_rad(FOV_ANGLE) / 2);
	data->ray.dir_y = data->player.dir_x * sin(-to_rad(FOV_ANGLE) / 2)
		+ data->player.dir_y * cos(-to_rad(FOV_ANGLE) / 2);
	printf("AAAAAAAAAAAAAAAAAAAAAAAAA \tdir_x = %f, dir_y = %f, distance = %f\n", data->ray.dir_x, data->ray.dir_y, distance);
	distance = hypot(data->ray.dir_x, data->ray.dir_y);
	data->ray.dir_x /= distance;
	data->ray.dir_y /= distance;
	data->ray.wallhit_x = 0;
	data->ray.wallhit_y = 0;
	data->ray.distance = 0;
	data->ray.wallhit_side = 0;
	data->ray.color = 0x87CEEB;
	draw_ceiling_and_floor(data);
	return (0);
}
