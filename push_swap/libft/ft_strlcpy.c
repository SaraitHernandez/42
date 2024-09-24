/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:18:22 by sarherna          #+#    #+#             */
/*   Updated: 2024/05/16 17:02:22 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < dst_size)
		ft_memcpy(dst, src, src_len + 1);
	else if (dst_size > 0)
	{
		ft_memcpy(dst, src, dst_size - 1);
		dst[dst_size - 1] = '\0';
	}
	return (src_len);
}
