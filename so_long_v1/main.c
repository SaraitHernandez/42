/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:09:54 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/26 17:37:22 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "main.h"
#include <stdlib.h>
#include <string.h>

void	free_map(t_map *map)
{
	for (int i = 0; i < map->height; i++)
		free(map->map[i]);
	free(map->map);
	free(map);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (ptr && old_size > 0)
	{
		// Copia el contenido antiguo al nuevo bloque
		if (old_size < new_size)
		{
			memcpy(new_ptr, ptr, old_size);
		}
		else
		{
			memcpy(new_ptr, ptr, new_size);
		}
		free(ptr);
	}
	return (new_ptr);
}


// Prototipo para cargar el mapa desde el archivo
t_map	*load_map(const char *file_path);

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		ft_printf("Uso: %s <map_file>\n", argv[0]);
		return (1);
	}

	// Cargar el mapa desde el archivo proporcionado
	map = load_map(argv[1]);
	if (!map)
	{
		ft_printf("Error cargando el mapa.\n");
		return (1);
	}

	// Validar el mapa
	if (is_valid_map(map))
		ft_printf("El mapa es válido.\n");
	else
		ft_printf("El mapa no es válido.\n");

	// Liberar la memoria usada por el mapa
	free_map(map);
	return (0);
}

t_map	*load_map(const char *file_path)
{
	int		fd;
	char	*line;
	int		row_count = 0;
	t_map	*map;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error al abrir el archivo.\n");
		return (NULL);
	}

	// Inicializar la estructura del mapa
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);

	// Leer el mapa línea por línea
	map->map = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		// Guardar la línea en el mapa
        size_t old_size = (row_count) * sizeof(char *); // Tamaño antes de la re-asignación
        map->map = ft_realloc(map->map, old_size, (row_count + 1) * sizeof(char *));
		map->map[row_count] = line;
		row_count++;
	}
	map->height = row_count;
	map->width = ft_strlen(map->map[0]);
    ft_printf("map len %d\n", ft_strlen(map->map[0])); // Asumimos que el mapa es rectangular

	close(fd);
	return (map);
}

