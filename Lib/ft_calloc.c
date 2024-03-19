/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarait.hernandez@novateva.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:02:32 by sarherna          #+#    #+#             */
/*   Updated: 2024/03/18 20:06:14 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t count, size_t size) {
    unsigned char *tmp;
    size_t i;

    i = 0;
    tmp = (unsigned char *)malloc(count * size);
    
    if (tmp == NULL) {
        return NULL;
    }

    while (i < count * size) 
    {
        tmp[i] = 0;
        i++;
    }

    return (void *)tmp;
}
