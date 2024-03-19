/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarait.hernandez@novateva.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:23:54 by sarherna          #+#    #+#             */
/*   Updated: 2024/03/18 19:56:14 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int ft_isspace(int c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'); //revisar
}

int ft_atoi(const char *str) {
    int sign = 1; 
    int result = 0;

    while (ft_isspace(*str))
        str++;

    if (*str == '+' || *str == '-') {
        if (*str == '-')
            sign = -1;
        str++;
    }

    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    return sign * result;
}