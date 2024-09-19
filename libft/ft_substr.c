/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:41:12 by sarherna          #+#    #+#             */
/*   Updated: 2024/07/09 17:50:11 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Extracts a substring from a given string.
 *
 * This function allocates and returns a substring from the string 's'.
 * The substring begins at index 'start' and is of length 'len'.
 * If 'start' is out of bounds, an empty string is returned.
 * If 'start' + 'len' is out of bounds, the substring is truncated to the end of 's'.
 *
 * @param s The string from which to extract the substring.
 * @param start The starting index of the substring in 's'.
 * @param len The maximum length of the substring.
 * @return char* A pointer to the newly allocated substring.
 *         NULL if the memory allocation fails or if 's' is NULL.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t	substr_len;
    char	*substr;
    size_t	i;

    if (!s)
        return (NULL);
    substr_len = 0;
    if (start < ft_strlen(s))
    {
        substr_len = len;
        if (start + len > ft_strlen(s))
            substr_len = ft_strlen(s) - start;
    }
    substr = malloc((substr_len + 1) * sizeof(char));
    if (!substr)
        return (NULL);
    i = 0;
    while (i < substr_len)
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[substr_len] = '\0';
    return (substr);
}
