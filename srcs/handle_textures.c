/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:17:23 by tordner           #+#    #+#             */
/*   Updated: 2025/08/06 21:38:43 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	has_xpm_extension(const char *path)
{
	int	len = ft_strlen(path);
	if (len < 4)
		return (0);
	return (ft_strcmp(path + len - 4, ".xpm") == 0);
}

int	is_valid_file(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	validate_texture(char *path, const char *label)
{
	if (!path || path[0] == '\0')
		return (printf("Error: %s path is empty\n", label), 1);
	if (!has_xpm_extension(path))
		return (printf("Error: %s must be a .xpm file\n", label), 1);
	if (!is_valid_file(path))
		return (printf("Error: %s file cannot be opened\n", label), 1);
	return (0);
}