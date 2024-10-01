/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarait.hernandez@novateva.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:56:59 by sarherna          #+#    #+#             */
/*   Updated: 2024/10/01 17:22:26 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "lib/ft_printf/ft_printf.h"
# include "lib/get_next_line/get_next_line.h"
# include "lib/ft_printf/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
	int		collectibles;
}	t_map;

typedef struct s_flood_fill_data
{
	int		collectibles;
	int		exit_count;
	int		**visited;
	t_map	*map;
}	t_flood_fill_data;

int		is_valid_map(t_map *map);
int		has_valid_characters(t_map *map, int *exit_c, int *start_c);
int		is_rectangular(t_map *map);
int		is_enclosed_in_walls(t_map *map);
int		has_valid_path(t_map *map);
void	flood_fill(t_flood_fill_data *data, int x, int y);
int		**create_visited_array(t_map *map);
t_map	*create_map(char **map);
int		map_height(char **map);
int		map_width(char **map);
void	print_doble_array(char **arr);
void	free_doble_array(char **arr);
void	free_map(t_map *map);
void	ft_error(const char *message, void *arg);
int		count_rows(const char *filename);
char	**load_map(int fd, const char *filename);
t_map	*build_map(const char *filename);

#endif
