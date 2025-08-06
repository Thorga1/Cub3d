/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorgal <thorgal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:31:45 by thorgal           #+#    #+#             */
/*   Updated: 2025/08/06 16:49:09 by thorgal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_north_south(t_data *data, const char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'N' && line[i + 1] == 'O' && ft_isspace(line[i + 2]))
	{
		data->c_elem->c_no++;
		get_no(data, line[i]);
		return ;
	}
	if (line[i] == 'S' && line[i + 1] == 'O' && ft_isspace(line[i + 2]))
	{
		data->c_elem->c_so++;
		get_so(data, line[i]);
		return ;
	}
	return ;
}

int	get_identifiers(t_data *data, const char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace((unsigned char)line[i]))
		i++;
	check_north_south
	return (1);
}
