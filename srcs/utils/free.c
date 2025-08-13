/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:31:36 by tordner           #+#    #+#             */
/*   Updated: 2025/08/13 21:36:46 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_input(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

void	free_parse_stuff(t_data *data)
{
	if (data->conf.no)
		free(data->conf.no);
	if (data->conf.so)
		free(data->conf.so);
	if (data->conf.ea)
		free(data->conf.ea);
	if (data->conf.we)
		free(data->conf.we);
	free_input(data->input);
	free_input(data->map.map);
	free_input(data->map.dup_map);
}

void	ft_free_all(t_data *data)
{
	int	i;

	if (!data)
		return ;
	free_parse_stuff(data);
	i = 0;
	while (i < 4)
	{
		if (data->textures[i].ptr)
			mlx_destroy_image(data->mlx.ptr, data->textures[i].ptr);
		i++;
	}
	if (data->img.ptr)
		mlx_destroy_image(data->mlx.ptr, data->img.ptr);
	if (data->mlx.win_ptr)
		mlx_destroy_window(data->mlx.ptr, data->mlx.win_ptr);
	if (data->mlx.ptr)
		mlx_destroy_display(data->mlx.ptr);
	free(data->mlx.ptr);
	free(data);
}
