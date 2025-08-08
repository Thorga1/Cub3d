/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:07:33 by tordner           #+#    #+#             */
/*   Updated: 2025/08/08 19:51:51 by tordner          ###   ########.fr       */
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
	if (data->c_elem.c_no != 1 || \
		data->c_elem.c_so != 1 || \
		data->c_elem.c_ea != 1 || \
		data->c_elem.c_ea != 1 || \
		data->c_elem.c_ceiling != 1 || \
		data->c_elem.c_floor != 1)
	{
		printf("Duplicate identifiers detected.\n");
		return (0);
	}
	if (!validate_texture(data, data->conf.no, "NO") || \
		!validate_texture(data, data->conf.so, "SO") || \
		!validate_texture(data, data->conf.ea, "EA") || \
		!validate_texture(data, data->conf.we, "WE"))
		return (0);
	return (1);
}

int	parse_identifiers(t_data *data)
{
	int	i;

	i = 0;
	if (!is_there_map(data->input))
		return (1);
	while (!is_map_line(data->input[i]))
	{
		if (is_line_empty(data->input[i]))
		{
			i++;
			continue ;
		}
		if (!is_identifier_line(data->input[i]))
			return (1);
		if (!get_identifiers(data, data->input[i]))
			return (1);
		i++;
	}
	if (!check_identifiers(data))
		return (1);
	return (0);
}

void	print_strs(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		printf("[%d] %s\n", i, arr[i]);
		i++;
	}
}

void print_config(t_config *conf)
{
    printf("NO: %s\n", conf->no ? conf->no : "(null)");
    printf("SO: %s\n", conf->so ? conf->so : "(null)");
    printf("WE: %s\n", conf->we ? conf->we : "(null)");
    printf("EA: %s\n", conf->ea ? conf->ea : "(null)");
    printf("Floor RGB: %d, %d, %d\n",
        conf->floor_rgb[0], conf->floor_rgb[1], conf->floor_rgb[2]);
    printf("Ceiling RGB: %d, %d, %d\n",
        conf->ceiling_rgb[0], conf->ceiling_rgb[1], conf->ceiling_rgb[2]);
}

int	handle_input(t_data *data, char **av)
{
	if (get_input(data, av[1]))
		return (1);
	if (parse_identifiers(data))
		return (1);
	print_config(&data->conf);
	return (0);
}
