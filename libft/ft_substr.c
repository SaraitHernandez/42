/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:41:12 by sarherna          #+#    #+#             */
/*   Updated: 2024/05/27 11:12:42 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
