/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:52:58 by yurwang           #+#    #+#             */
/*   Updated: 2025/08/12 21:02:03 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_horizontal_hit(t_data *data, double xstep, double ystep)
{
	while (data->ray.intercept_x >= 0 && \
		data->ray.intercept_x < data->map.max_width * TILE_SIZE && \
		data->ray.intercept_y >= 0 && \
		data->ray.intercept_y < data->map.max_height * TILE_SIZE)
	{
		if (hit_horizontal_wall(data, data->ray.intercept_x, \
			data->ray.intercept_y))
		{
			data->ray.wallhit_x = data->ray.intercept_x;
			data->ray.wallhit_y = data->ray.intercept_y;
			data->ray.wallhit_side = 0;
			data->ray.wallhit_hor_dist = hypot(data->ray.wallhit_x - \
				data->player.pos_x * (double)TILE_SIZE,
					data->ray.wallhit_y - data->player.pos_y
					* (double)TILE_SIZE);
			return ;
		}
		data->ray.intercept_x += xstep;
		data->ray.intercept_y += ystep;
	}
	data->ray.wallhit_x = data->player.pos_x * TILE_SIZE;
	data->ray.wallhit_y = data->player.pos_y * TILE_SIZE;
	data->ray.wallhit_hor_dist = INF_DIST;
}

void	horizontal_hit(t_data *data, double ray_angle)
{
	double	xstep;
	double	ystep;
	double	t;

	if (data->ray.is_facing_down == 1)
		data->ray.intercept_y = floor(data->player.pos_y) \
			* TILE_SIZE + TILE_SIZE;
	else
		data->ray.intercept_y = floor(data->player.pos_y) * TILE_SIZE;
	t = ft_tan(ray_angle);
	data->ray.intercept_x = data->player.pos_x * TILE_SIZE + \
		(data->player.pos_y * TILE_SIZE - \
			data->ray.intercept_y) / t;
	ystep = TILE_SIZE;
	if (data->ray.is_facing_down == 0)
		ystep = -TILE_SIZE;
	xstep = TILE_SIZE / t;
	if (data->ray.is_facing_right == 0 && xstep > 0)
		xstep *= -1;
	if (data->ray.is_facing_right == 1 && xstep < 0)
		xstep *= -1;
	find_horizontal_hit(data, xstep, ystep);
}

void	find_vertical_hit(t_data *data, double xstep, double ystep)
{
	while (data->ray.intercept_x >= 0 && \
		data->ray.intercept_x < data->map.max_width * TILE_SIZE && \
		data->ray.intercept_y >= 0 && \
		data->ray.intercept_y < data->map.max_height * TILE_SIZE)
	{
		if (hit_vertical_wall(data, data->ray.intercept_x, \
				data->ray.intercept_y))
		{
			data->ray.wallhit_x = data->ray.intercept_x;
			data->ray.wallhit_y = data->ray.intercept_y;
			data->ray.wallhit_side = 1;
			data->ray.wallhit_ver_dist = hypot(data->ray.wallhit_x - \
				data->player.pos_x * (double)TILE_SIZE,
					data->ray.wallhit_y - data->player.pos_y
					* (double)TILE_SIZE);
			return ;
		}
		data->ray.intercept_x += xstep;
		data->ray.intercept_y += ystep;
	}
	data->ray.wallhit_x = data->player.pos_x * (double)TILE_SIZE;
	data->ray.wallhit_y = data->player.pos_y * (double)TILE_SIZE;
	data->ray.wallhit_ver_dist = INF_DIST;
}

void	vertical_hit(t_data *data, double ray_angle)
{
	double	xstep;
	double	ystep;
	double	t;

	if (data->ray.is_facing_right == 1)
		data->ray.intercept_x = floor(data->player.pos_x) * \
			TILE_SIZE + TILE_SIZE;
	else
		data->ray.intercept_x = floor(data->player.pos_x) * TILE_SIZE;
	t = ft_tan(ray_angle);
	data->ray.intercept_y = data->player.pos_y * TILE_SIZE + \
		(data->player.pos_x * TILE_SIZE - \
			data->ray.intercept_x) * t;
	xstep = TILE_SIZE;
	if (data->ray.is_facing_right == 0)
		xstep = -TILE_SIZE;
	ystep = TILE_SIZE * t;
	if (data->ray.is_facing_down == 0 && ystep > 0)
		ystep *= -1;
	if (data->ray.is_facing_down == 1 && ystep < 0)
		ystep *= -1;
	find_vertical_hit(data, xstep, ystep);
}
