/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:06:34 by sarherna          #+#    #+#             */
/*   Updated: 2024/05/24 17:57:09 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
