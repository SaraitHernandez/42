/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:08:37 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/26 15:51:56 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <stdio.h>
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
	int		collectibles_count;
}	t_map;

int	is_valid_map(t_map *map);
int	has_valid_characters(t_map *map, int *exit_c, int *start_c);
int	is_rectangular(t_map *map);
int	is_enclosed_in_walls(t_map *map);;
int	has_valid_path(t_map *map);
void	flood_fill(t_map *map, int x, int y, int **visited, int *collectibles_count, int *exit_count);
int	**create_visited_array(t_map *map);
void	free_visited_array(int **visited, int height);
t_map	*create_map(char **map);
int	map_height(char **map);
int	map_width(char **map);


#endif
