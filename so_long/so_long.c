/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarait.hernandez@novateva.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:09:54 by sarherna          #+#    #+#             */
/*   Updated: 2024/10/02 11:28:09 by sarherna         ###   ########.fr       */
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
	if (is_valid_map(map, argv[1]))
	{
		ft_printf("Mapa valido: %s\n", argv[1]);
		void *mlx_ptr;
		void *win_ptr;

		mlx_ptr = mlx_init();
		if (!mlx_ptr)
			ft_error("mlx error.", NULL);
		win_ptr = mlx_new_window(mlx_ptr, 600, 400, "hi :)");
		if (!win_ptr){
			free(mlx_ptr);
			ft_error("win ptr error.", NULL);
		}
		//mlx_destroy_window(mlx_ptr, win_ptr);
		//mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
	}
	else
		ft_error("Is not a valid map.", NULL);
	free_map(map);
	return (0);
}