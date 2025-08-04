/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:38:17 by tordner           #+#    #+#             */
/*   Updated: 2025/08/04 21:33:23 by tordner          ###   ########.fr       */
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


typedef struct s_data
{
	char		**input;
	t_config	*conf;
}			t_data;

int		errors(int ac, char **av);
int		ft_exit(t_data *data);
int		ft_is_alpha(char c);
char	**ft_split(char const *s, char c);
int		handle_input(t_data *data, char **av);
int		init_data(t_data *data);

int		is_map_line(const char *line);
int		is_identifier_line(const char *line);
int		is_line_empty(const char *line);


#endif
