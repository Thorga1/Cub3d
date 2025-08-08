/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_find_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:11:34 by tordner           #+#    #+#             */
/*   Updated: 2025/08/08 19:48:56 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
		c == '\v' || c == '\f' || c == '\r');
}

int	is_line_empty(const char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace((unsigned char)line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_identifier_line(const char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace((unsigned char)line[i]))
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O' && ft_isspace(line[i + 2]))
		return (1);
	if (line[i] == 'S' && line[i + 1] == 'O' && ft_isspace(line[i + 2]))
		return (1);
	if (line[i] == 'W' && line[i + 1] == 'E' && ft_isspace(line[i + 2]))
		return (1);
	if (line[i] == 'E' && line[i + 1] == 'A' && ft_isspace(line[i + 2]))
		return (1);
	if ((line[i] == 'F' || line[i] == 'C') && ft_isspace(line[i + 1]))
		return (1);
	return (0);
}

int	is_map_line(const char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace((unsigned char)line[i]))
		i++;
	if (line[i] == '1' || line[i] == '0')
		return (1);
	return (0);
}
