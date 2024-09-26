/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:56:40 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/26 11:27:16 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_stack *stack_a, char **split_arg)
{
	if (stack_a != NULL)
		destroy_stack(stack_a);
	if (split_arg != NULL)
		free_split(split_arg);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
