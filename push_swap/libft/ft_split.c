/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:06:34 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/23 15:39:10 by sarherna         ###   ########.fr       */
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

static void	ft_free_split(char **str_arr, int j)
{
	while (j >= 0)
	{
		free(str_arr[j]);
		j--;
	}
	free(str_arr);
}

int	ft_split_helper(char const *s, char c, char **str_arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			str_arr[j] = ft_word_alloc(&s[i], c);
			if (!str_arr[j])
				return (0);
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	str_arr[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = ft_count_words(s, c);
	str_arr = ft_calloc(word_count + 1, sizeof(char *));
	if (!str_arr)
		return (NULL);
	if (!ft_split_helper(s, c, str_arr))
	{
		ft_free_split(str_arr, word_count - 1);
		return (NULL);
	}
	return (str_arr);
}
