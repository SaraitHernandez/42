/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarait.hernandez@novateva.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:11:17 by sarherna          #+#    #+#             */
/*   Updated: 2024/03/18 20:16:34 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s1) {

    char *copy;
    size_t i;
    
    copy = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char)); 

    if (copy == NULL) {
        return NULL;
    }

    i = 0;
    while (s1[i]) {
        copy[i] = s1[i];
        i++;
    }
    
    copy[i] = '\0';

    return (copy);
}
