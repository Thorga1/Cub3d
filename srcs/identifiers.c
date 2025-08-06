/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:31:45 by thorgal           #+#    #+#             */
/*   Updated: 2025/08/06 21:16:41 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_north_south(t_data *data, const char *line)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
	{
		data->c_elem.c_no++;
		get_no(data, line + 3);
		return (1);
	}
	if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
	{
		data->c_elem.c_so++;
		get_so(data, line + 3);
		return (1);
	}
	return (0);
}

int	check_east_west(t_data *data, const char *line)
{
	if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
	{
		data->c_elem.c_ea++;
		get_ea(data, line + 3);
		return (1);
	}
	if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
	{
		data->c_elem.c_we++;
		get_we(data, line + 3);
		return (1);
	}
	return (0);
}

int	get_identifiers(t_data *data, const char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace((unsigned char)line[i]))
		i++;
	if (!check_north_south(data, line + i) && \
	(!check_east_west(data, line + i)))
		return (0);
	return (1);
}
