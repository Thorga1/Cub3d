/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:37:39 by tordner           #+#    #+#             */
/*   Updated: 2025/08/12 21:17:51 by tordner          ###   ########.fr       */
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

void	ft_free_all(t_data *data)
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
	free(data);
}

int	ft_exit(t_data *data, int end)
{
	ft_free_all(data);
	exit(end);
}

int	ft_end(t_data *data)
{
	ft_exit(data, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	init_data(data);
	if (errors(ac, av))
		ft_exit(data, 1);
	if (handle_input(data, av))
		ft_exit(data, 1);
	init_mlx(data);
	mlx_loop_hook(data->mlx.ptr, draw_game, data);
	mlx_hook(data->mlx.win_ptr, 2, (1L << 0), ft_key, data);
	mlx_hook(data->mlx.win_ptr, 17, 0, ft_end, data);
	mlx_loop(data->mlx.ptr);
	ft_exit(data, 0);
	return (0);
}
