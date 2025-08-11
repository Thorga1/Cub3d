/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 20:15:16 by tordner           #+#    #+#             */
/*   Updated: 2025/08/11 21:54:09 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_spawn(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	flood_fill(int *flood_error, char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || x >= (int)ft_strlen(map[y]))
	{
		*flood_error = 1;
		return ;
	}
	if (map[y][x] == ' ')
	{
		*flood_error = 1;
		return ;
	}
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	flood_fill(flood_error, map, x + 1, y);
	flood_fill(flood_error, map, x - 1, y);
	flood_fill(flood_error, map, x, y + 1);
	flood_fill(flood_error, map, x, y - 1);
}

int	error_flood_fill(t_data *data, int spawn_count)
{
	if (spawn_count != 1)
		return (write(1, "Error: Invalid number of players\n", 34), 1);
	if (data->flood_error)
		return (write(1, "Error: Map is not closed\n", 25), 1);
	return (0);
}

int	init_flood_fill(t_data *data)
{
	int	i;
	int	j;
	int	spawn_count;

	data->flood_error = 0;
	spawn_count = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (is_spawn(data->map[i][j]))
			{
				spawn_count++;
				flood_fill(&data->flood_error, data->map, j, i);
			}
			j++;
		}
		i++;
	}
	if (error_flood_fill(data, spawn_count))
		return (1);
	return (0);
}
