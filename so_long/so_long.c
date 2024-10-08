/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:09:54 by sarherna          #+#    #+#             */
/*   Updated: 2024/10/08 10:52:38 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	map = build_map(argv[1]);
	if (is_valid_map(map, argv[1]))
	{
		game = game_constructor(map);
		init_game(game);
		mlx_loop(game->mlx);
	}
	else
	{
		free_map(map);
		ft_error("Is not a valid map.", NULL);
	}
	free_map(map);
	return (0);
}
