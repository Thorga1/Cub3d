/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:00:06 by tordner           #+#    #+#             */
/*   Updated: 2025/08/11 21:17:08 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_data(t_data *data)
{
	data->input = NULL;
	data->map = NULL;
	data->flood_error = 0;
	data->conf.we = NULL;
	data->conf.no = NULL;
	data->conf.ea = NULL;
	data->conf.so = NULL;
	data->conf.floor_rgb[0] = -1;
	data->conf.floor_rgb[1] = -1;
	data->conf.floor_rgb[2] = -1;
	data->conf.ceiling_rgb[0] = -1;
	data->conf.ceiling_rgb[1] = -1;
	data->conf.ceiling_rgb[2] = -1;
	data->c_elem.c_no = 0;
	data->c_elem.c_so = 0;
	data->c_elem.c_ea = 0;
	data->c_elem.c_we = 0;
	data->c_elem.c_floor = 0;
	data->c_elem.c_ceiling = 0;
	return (0);
}
