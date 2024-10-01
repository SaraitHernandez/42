/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:29:20 by sarherna          #+#    #+#             */
/*   Updated: 2024/05/15 18:29:52 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*str_dst;
	const unsigned char	*str_src;

	str_dst = (unsigned char *) dst;
	str_src = (const unsigned char *) src;
	i = 0;
	if (str_src < str_dst && str_dst < (str_src + n))
	{
		while (n-- > 0)
		{
			str_dst[n] = str_src[n];
		}
	}
	else
	{
		while (i < n)
		{
			str_dst[i] = str_src[i];
			i++;
		}
	}
	return (str_dst);
}
