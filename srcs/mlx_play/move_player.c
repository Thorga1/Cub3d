/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 21:26:33 by tordner           #+#    #+#             */
/*   Updated: 2025/08/12 21:26:50 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    move_front(t_data *data)
{
    data->player.pos_x += data->player.dir_x * SPEED;
    data->player.pos_y += data->player.dir_y * SPEED;
}

void    move_back(t_data *data)
{
    data->player.pos_x -= data->player.dir_x * SPEED;
    data->player.pos_y -= data->player.dir_y * SPEED;
}

void    move_left(t_data *data)
{
    data->player.pos_x += data->player.dir_y * SPEED;
    data->player.pos_y -= data->player.dir_x * SPEED;
}

void    move_right(t_data *data)
{
    data->player.pos_x -= data->player.dir_y * SPEED;
    data->player.pos_y += data->player.dir_x * SPEED;
}
