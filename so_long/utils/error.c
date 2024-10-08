/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarait.hernandez@novateva.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:46:20 by sarherna          #+#    #+#             */
/*   Updated: 2024/10/01 17:17:15 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_error(const char *message, void *arg)
{
	ft_printf("Error: %s\n", message);
	if (arg)
		free(arg);
	exit(EXIT_FAILURE);
}
