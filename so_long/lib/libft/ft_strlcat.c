/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 07:20:25 by sarherna          #+#    #+#             */
/*   Updated: 2024/05/16 19:12:08 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	space_for_copy;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst >= size)
		len_dst = size;
	space_for_copy = size - len_dst;
	if (space_for_copy == 0)
		return (len_dst + len_src);
	if (space_for_copy >= len_src + 1)
	{
		ft_memcpy(dst + len_dst, src, len_src + 1);
	}
	else
	{
		ft_memcpy(dst + len_dst, src, space_for_copy - 1);
		dst[size - 1] = '\0';
	}
	return (len_dst + len_src);
}
