/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 21:26:33 by tordner           #+#    #+#             */
/*   Updated: 2025/08/13 21:39:37 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_front(t_data *data)
{
	data->player.pos_x += data->player.dir_x * SPEED;
	data->player.pos_y += data->player.dir_y * SPEED;
}

void	move_back(t_data *data)
{
	data->player.pos_x -= data->player.dir_x * SPEED;
	data->player.pos_y -= data->player.dir_y * SPEED;
}

void	move_left(t_data *data)
{
	data->player.pos_x += data->player.dir_y * SPEED;
	data->player.pos_y -= data->player.dir_x * SPEED;
}

void	move_right(t_data *data)
{
	data->player.pos_x -= data->player.dir_y * SPEED;
	data->player.pos_y += data->player.dir_x * SPEED;
}

int	ft_key(int key, t_data *data)
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
