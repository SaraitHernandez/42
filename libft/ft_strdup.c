/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:11:17 by sarherna          #+#    #+#             */
/*   Updated: 2024/07/09 17:32:51 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * \brief Allocates sufficient memory for a copy of the string s1,
 *        does the copy, and returns a pointer to it.
 *
 * \param s The string to be duplicated.
 *
 * \return On success, the function returns a pointer to the duplicated string.
 *         It returns NULL if insufficient memory was available.
 */
char	*ft_strdup(const char *s)
{
    char	*copy;
    size_t	i;

    copy = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
    if (copy == NULL)
        return (NULL);
    i = 0;
    while (s[i])
    {
        copy[i] = s[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}
