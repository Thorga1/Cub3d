/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:07:33 by tordner           #+#    #+#             */
/*   Updated: 2025/08/05 19:12:15 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_input(t_data *data, char *file)
{
	int		fd;
	char	buf[2049];
	ssize_t	size;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (write(1, "Error: invalid file, cannot be opened\n", 39), 1);
	size = read(fd, buf, 2048);
	if (size < 0)
		return (write(1, "Error: failed to read file\n", 28), 1);
	buf[size] = '\0';
	close(fd);
	data->input = ft_split(buf, '\n');
	return (0);
}

int	check_identifiers(t_data *data)
{
	if (data->c_elem->c_no != 1 || \
		data->c_elem->c_so != 1 || \
		data->c_elem->c_ea != 1 || \
		data->c_elem->c_we != 1)
		return (1);
	return (0);
}

int	parse_identifiers(t_data *data)
{
	int	i;

	i = 0;
	while (!is_map_line(data->input[i]))
	{
		if (is_line_empty(data->input[i]))
		{
			i++;
			continue ;
		}
		if ()
	}

}

int	handle_input(t_data *data, char **av)
{
	if (get_input(data, av[1]))
		return (1);
	if (parse_identifiers)
	return (0);
}
