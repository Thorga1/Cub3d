/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:38:17 by tordner           #+#    #+#             */
/*   Updated: 2025/08/06 21:40:23 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include "mlx.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_config
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor_rgb[3];
	int		ceiling_rgb[3];
}	t_config;

typedef	struct s_count_elements
{
	int	c_no;
	int	c_so;
	int	c_ea;
	int	c_we;
	int	c_floor;
	int	c_ceiling;
}	t_c_elem;

typedef struct s_data
{
	char		**input;
	t_config	conf;
	t_c_elem	c_elem;
}			t_data;

int		errors(int ac, char **av);
int		ft_exit(t_data *data);

char	**ft_split(char const *s, char c);
int		ft_is_alpha(char c);
int		ft_isspace(int c);
char	*ft_strdup(const char *s);
int		ft_strcmp(const char *s1, const char *s2);

int		init_data(t_data *data);

int		handle_input(t_data *data, char **av);

int		is_map_line(const char *line);
int		is_identifier_line(const char *line);
int		is_line_empty(const char *line);

void	get_no(t_data *data, const char *line);
void	get_so(t_data *data, const char *line);
void	get_ea(t_data *data, const char *line);
void	get_we(t_data *data, const char *line);

int		get_identifiers(t_data *data, const char *line);

int		validate_texture(char *path, const char *label);

#endif
