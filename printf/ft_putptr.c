/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:39:55 by sarherna          #+#    #+#             */
/*   Updated: 2024/06/20 12:45:12 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	char			*base;
	char			hex[19];
	int				i;
	int				len;

	addr = (unsigned long)ptr;
	base = "0123456789abcdef";
	i = 18;
	len = 0;
	hex[i--] = '\0';
	if (addr == 0)
		len += ft_putstr("(nil)");
	else
	{
		while (addr > 0)
		{
			hex[i--] = base[addr % 16];
			addr /= 16;
		}
		len += ft_putstr("0x");
		len += ft_putstr(&hex[i + 1]);
	}
	return (len);
}
