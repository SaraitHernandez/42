/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarait.hernandez@novateva.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:56:59 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/28 18:07:03 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map/map.h"
#include <fcntl.h>

void	print_doble_array(char **arr);
void free_doble_array(char **arr);
void	free_map(t_map *map);
void	ft_error(const char *message, void *arg);
int count_rows(const char *filename);
char	**load_map(int fd, const char *filename);
t_map	*build_map(const char *filename);