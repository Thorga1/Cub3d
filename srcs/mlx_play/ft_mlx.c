/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 21:10:33 by tordner           #+#    #+#             */
/*   Updated: 2025/08/12 21:29:57 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_key(int key, t_data *data)
{
	if (key == XK_w)
		move_front(data);
	else if (key == XK_s)
		move_back(data);
	else if (key == XK_a)
		move_left(data);
	else if (key == XK_d)
		move_right(data);
	else if (key == XK_Escape)
		ft_exit(data, 0);
	else if (key == XK_Right)
		rotate_right(data);
	else if (key == XK_Left)
		rotate_left(data);
	return (1);
}

void    init_mlx2(t_data *data)
{
	data->textures[0].ptr = mlx_xpm_file_to_image(data->mlx.ptr, \
	data->conf.no, &data->textures[0].width, &data->textures[0].height);
	if (!data->textures[0].ptr)
		ft_exit(data, 1);
	data->textures[1].ptr = mlx_xpm_file_to_image(data->mlx.ptr, \
	data->conf.so, &data->textures[1].width, &data->textures[1].height);
	if (!data->textures[1].ptr)
		ft_exit(data, 1);
	data->textures[2].ptr = mlx_xpm_file_to_image(data->mlx.ptr, \
	data->conf.ea, &data->textures[2].width, &data->textures[2].height);
	if (!data->textures[2].ptr)
		ft_exit(data, 1);
	data->textures[3].ptr = mlx_xpm_file_to_image(data->mlx.ptr, \
	data->conf.we, &data->textures[3].width, &data->textures[3].height);
	if (!data->textures[3].ptr)
		ft_exit(data, 1);
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

void    init_mlx(t_data *data)
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