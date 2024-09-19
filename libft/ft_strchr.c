/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:02:05 by sarherna          #+#    #+#             */
/*   Updated: 2024/07/09 17:16:03 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of a character in a string.
 *
 * This function scans the string pointed to by @p s for the first occurrence of the character @p c (converted to a char).
 *
 * @param s The string to be scanned.
 * @param c The character to be located.
 *
 * @return A pointer to the first occurrence of @p c in @p s, or a null pointer if @p c is not found.
 *
 * If @p c is '\0', the function returns a pointer to the terminating null character of @p s.
 */
char	*ft_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if ((char)c == '\0')
        return ((char *)s);
    return (NULL);
}
