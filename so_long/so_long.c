/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarait.hernandez@novateva.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:09:54 by sarherna          #+#    #+#             */
/*   Updated: 2024/10/01 17:23:51 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map *map;
	if (argc != 2)
	{
		ft_printf("Uso: %s <map_file>\n", argv[0]);
		return (1);
	}
	map = build_map(argv[1]);
	if (is_valid_map(map))
		ft_printf("El mapa es válido.\n");
	else
		ft_printf("El mapa no es válido.\n");
	free_map(map);
	return (0);
}