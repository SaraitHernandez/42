/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:21:06 by sarherna          #+#    #+#             */
/*   Updated: 2024/06/20 12:45:14 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print(const char format, va_list args, int printed_chars)
{
	if (format == 'c')
		printed_chars += ft_putchar(va_arg(args, int));
	else if (format == 's')
		printed_chars += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		printed_chars += ft_putptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		printed_chars += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		printed_chars += ft_putunbr(va_arg(args, unsigned int));
	else if (format == 'x')
		printed_chars += ft_puthex(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		printed_chars += ft_puthex(va_arg(args, unsigned int), 1);
	else if (format == '%')
		printed_chars += ft_putchar('%');
	else
		printed_chars += ft_putchar(format);
	return (printed_chars);
}

int	ft_vprintf(const char *format, va_list args)
{
	int	i;
	int	printed_chars;

	i = 0;
	printed_chars = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			printed_chars = print(format[i], args, printed_chars);
		}
		else
		{
			printed_chars += ft_putchar(format[i]);
		}
		i++;
	}
	return (printed_chars);
}
