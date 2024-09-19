/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:06:34 by sarherna          #+#    #+#             */
/*   Updated: 2024/07/09 18:07:27 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Counts the number of words in a string, where words are separated by a delimiter character.
 *
 * This function iterates through the input string and increments a counter each time it encounters a
 * non-delimiter character that follows either a delimiter character or the start of the string.
 *
 * @param s The input string to be split into words.
 * @param c The delimiter character used to separate words in the string.
 * @return int The total number of words found in the string.
 */
static int	ft_count_words(const char *s, char c)
{
    int	count;

    count = 0;
    while (*s != '\0')
    {
        while (*s == c)
            s++;
        if (*s != '\0')
            count++;
        while (*s && (*s != c))
            s++;
    }
    return (count);
}

/**
 * @brief Allocates memory for a substring of the input string, up to the first occurrence of the delimiter character.
 *
 * This function calculates the length of the substring by iterating through the input string until it encounters
 * the delimiter character or the end of the string. It then allocates memory for the substring and copies the
 * characters from the input string into the newly allocated memory using the ft_substr function.
 *
 * @param s The input string from which to extract the substring.
 * @param c The delimiter character that marks the end of the substring.
 * @return char* A pointer to the newly allocated substring, or NULL if memory allocation fails.
 */
static char	*ft_word_alloc(const char *s, char c)
{
    int		i;
    char	*word;

    i = 0;
    while (s[i] && s[i] != c)
        i++;
    word = ft_substr(s, 0, i);
    return (word);
}

/**
 * @brief Splits a string into an array of substrings based on a delimiter character.
 *
 * This function allocates memory for a new array of strings and populates it with substrings
 * extracted from the input string. The substrings are delimited by the specified character.
 * The last element of the array is set to NULL to indicate the end of the array.
 *
 * @param s The input string to be split into substrings.
 * @param c The delimiter character used to separate substrings in the input string.
 * @return char** A pointer to the newly allocated array of substrings, or NULL if memory allocation fails.
 */
char	**ft_split(char const *s, char c)
{
    int		i;
    int		j;
    char	**str_arr;

    if (!s)
        return (NULL);
    str_arr = ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
    if (!str_arr)
        return (NULL);
    i = 0;
    j = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i])
        {
            str_arr[j] = ft_word_alloc(&s[i], c);
            j++;
            while (s[i] && s[i] != c)
                i++;
        }
    }
    str_arr[j] = NULL;
    return (str_arr);
}
