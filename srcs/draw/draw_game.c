/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:12:35 by yurwang           #+#    #+#             */
/*   Updated: 2025/08/12 21:03:16 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling_and_floor(t_data *data)
{
	unsigned int	ceiling;
	unsigned int	floor;
	int				row;
	int				col;

	row = 0;
	ceiling = rgb_to_color(data->conf.ceiling_rgb[0], \
					data->conf.ceiling_rgb[1], data->conf.ceiling_rgb[2]);
	floor = rgb_to_color(data->conf.floor_rgb[0], \
					data->conf.floor_rgb[1], data->conf.floor_rgb[2]);
	while (row < H)
	{
		col = 0;
		while (col < W)
		{
			if (row < H / 2)
				add_color_to_pixel_via_mlx(&data->img, row, col++, ceiling);
			else
				add_color_to_pixel_via_mlx(&data->img, row, col++, floor);
		}
		row++;
	}
}

void	ray_direction(t_data *data)
{
	if (data->ray.dir_x > 0)
		data->ray.is_facing_right = 1;
	else
		data->ray.is_facing_right = 0;
	if (data->ray.dir_y > 0)
		data->ray.is_facing_down = 1;
	else
		data->ray.is_facing_down = 0;
}

void	rotate_ray(t_data *data)
{
	double	distance;

	data->ray.dir_x = data->ray.dir_x * cos(-to_rad(FOV_ANGLE) / W) - \
		data->ray.dir_y * sin(-to_rad(FOV_ANGLE) / W);
	data->ray.dir_y = data->ray.dir_x * sin(-to_rad(FOV_ANGLE) / W) + \
		data->ray.dir_y * cos(-to_rad(FOV_ANGLE) / W);
	distance = hypot(data->ray.dir_x, data->ray.dir_y);
	data->ray.dir_x /= distance;
	data->ray.dir_y /= distance;
}

int	draw_game(t_data *data)
{
	int		col;
	double	ray_angle;
	double	player_facing_angle;

	col = 0;
	init_ray(data);
	while (col < W)
	{
		ray_angle = ft_atan2(data->ray.dir_y, data->ray.dir_x);
		player_facing_angle = ft_atan2(data->player.dir_y, data->player.dir_x);
		ray_direction(data);
		horizontal_hit(data, ray_angle);
		vertical_hit(data, ray_angle);
		choose_nearest_hit_dist(data);
		data->ray.distance /= TILE_SIZE;
		data->ray.distance = fix_fisheye(data, ray_angle, player_facing_angle);
		data->wall.height = (double)floor(H / data->ray.distance);
		data->wall.top = (H / 2) - (data->wall.height / 2);
		data->wall.bottom = (H / 2) + (data->wall.height / 2);
		texture_hit_x(data);
		draw_strip(data, col++);
		rotate_ray(data);
	}
	mlx_put_image_to_window(data->mlx.ptr, \
		data->mlx.win_ptr, data->img.ptr, 0, 0);
}
