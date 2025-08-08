/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 19:43:22 by tordner           #+#    #+#             */
/*   Updated: 2025/08/08 19:52:24 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_there_map(char **input)
{
	int	i;

	if (!input)
		return (0);
	i = 0;
	while (input[i])
	{
		if (is_map_line(input[i]))
			return (1);
		i++;
	}
	return (0);
}

