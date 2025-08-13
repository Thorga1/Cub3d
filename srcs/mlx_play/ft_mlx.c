/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 21:10:33 by tordner           #+#    #+#             */
/*   Updated: 2025/08/13 21:39:11 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_data *data, t_img *tex, char *path)
{
	tex->ptr = mlx_xpm_file_to_image(data->mlx.ptr, path, \
		&tex->width, &tex->height);
	if (!tex->ptr)
		ft_exit(data, 1);
	tex->addr = mlx_get_data_addr(tex->ptr, &tex->bpp, \
		&tex->ll, &tex->endian);
	if (!tex->addr)
		ft_exit(data, 1);
}

void	init_mlx2(t_data *data)
{
	init_texture(data, &data->textures[0], data->conf.no);
	init_texture(data, &data->textures[1], data->conf.so);
	init_texture(data, &data->textures[2], data->conf.ea);
	init_texture(data, &data->textures[3], data->conf.we);
}

void	rotate_right(t_data *data)
{
	double	distance;

	data->player.dir_x = data->player.dir_x * cos(PI / TURN_ANGLE) \
	- data->player.dir_y * sin(PI / TURN_ANGLE);
	data->player.dir_y = data->player.dir_x * sin(PI / TURN_ANGLE) \
	+ data->player.dir_y * cos(PI / TURN_ANGLE);
	distance = hypot(data->player.dir_x, data->player.dir_y);
	data->player.dir_x /= distance;
	data->player.dir_y /= distance;
}

void	rotate_left(t_data *data)
{
	double	distance;

	data->player.dir_x = data->player.dir_x * cos(PI / TURN_ANGLE) \
	+ data->player.dir_y * sin(PI / TURN_ANGLE);
	data->player.dir_y = data->player.dir_y * cos(PI / TURN_ANGLE) \
	- data->player.dir_x * sin(PI / TURN_ANGLE);
	distance = hypot(data->player.dir_x, data->player.dir_y);
	data->player.dir_y /= distance;
	data->player.dir_x /= distance;
}

void	init_mlx(t_data *data)
{
	data->mlx.ptr = mlx_init();
	if (!data->mlx.ptr)
		ft_exit(data, 1);
	data->mlx.win_ptr = mlx_new_window(data->mlx.ptr, W, H, "cub3d");
	if (!data->mlx.win_ptr)
		ft_exit(data, 1);
	data->img.ptr = mlx_new_image(data->mlx.ptr, W, H);
	if (!data->img.ptr)
		ft_exit(data, 1);
	data->img.addr = mlx_get_data_addr(data->img.ptr, &data->img.bpp, \
	&data->img.ll, &data->img.endian);
	if (!data->img.addr)
		ft_exit(data, 1);
	init_mlx2(data);
}
