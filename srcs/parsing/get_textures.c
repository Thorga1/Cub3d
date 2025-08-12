/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:46:06 by thorgal           #+#    #+#             */
/*   Updated: 2025/08/12 19:30:37 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	trim_trailing_spaces(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	while (len > 0 && ft_isspace((unsigned char)str[len - 1]))
		str[--len] = '\0';
}

void	get_no(t_data *data, const char *line)
{
	int		i;
	char	*path;

	i = 0;
	while (line[i] && ft_isspace((unsigned char)line[i]))
		i++;
	path = ft_strdup(line + i);
	if (!path)
		ft_exit(data);
	trim_trailing_spaces(path);
	if (data->conf.no)
		free(data->conf.no);
	data->conf.no = path;
}

void	get_so(t_data *data, const char *line)
{
	int		i;
	char	*path;

	i = 0;
	while (line[i] && ft_isspace((unsigned char)line[i]))
		i++;
	path = ft_strdup(line + i);
	if (!path)
		ft_exit(data);
	trim_trailing_spaces(path);
	if (data->conf.so)
		free(data->conf.so);
	data->conf.so = path;
}

void	get_ea(t_data *data, const char *line)
{
	int		i;
	char	*path;

	i = 0;
	while (line[i] && ft_isspace((unsigned char)line[i]))
		i++;
	path = ft_strdup(line + i);
	if (!path)
		ft_exit(data);
	trim_trailing_spaces(path);
	if (data->conf.ea)
		free(data->conf.ea);
	data->conf.ea = path;
}

void	get_we(t_data *data, const char *line)
{
	int		i;
	char	*path;

	i = 0;
	while (line[i] && ft_isspace((unsigned char)line[i]))
		i++;
	path = ft_strdup(line + i);
	if (!path)
		ft_exit(data);
	trim_trailing_spaces(path);
	if (data->conf.we)
		free(data->conf.we);
	data->conf.we = path;
}
