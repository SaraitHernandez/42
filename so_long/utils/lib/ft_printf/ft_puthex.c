/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:41:01 by sarherna          #+#    #+#             */
/*   Updated: 2024/06/20 09:07:53 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int uppercase)
{
	char	*base;
	char	hex[9];
	int		i;
	int		len;

	if (uppercase == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 8;
	len = 0;
	hex[i--] = '\0';
	if (n == 0)
		hex[i--] = '0';
	while (n > 0)
	{
		hex[i--] = base[n % 16];
		n /= 16;
	}
	len += ft_putstr(&hex[i + 1]);
	return (len);
}
