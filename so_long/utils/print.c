/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarait.hernandez@novateva.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:53:21 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/27 16:59:05 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
void	print_doble_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		ft_printf("%s", arr[i]);
		i++;
	}
	ft_printf("\n");
}
