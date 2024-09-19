/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:02:32 by sarherna          #+#    #+#             */
/*   Updated: 2024/05/24 14:22:25 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = (unsigned char *)malloc(nmemb * size);
	if (tmp == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		tmp[i] = 0;
		i++;
	}
	return ((void *)tmp);
}
