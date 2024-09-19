/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_aux_ft.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarait.hernandez@novateva.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:25:56 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/19 12:19:17 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	doble_swap(t_stack *a, t_stack *b)
{
	swap(a, '\0');
	swap(b, '\0');
	write(1, "ss\n", 3);
}

void	put(t_stack *stack, t_node *node)
{
	if (is_empty(stack))
	{
		node->next = NULL;
		node->prev = NULL;
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		node->next = stack->head;
		stack->head->prev = node;
		node->prev = NULL;
		stack->head = node;
	}
}

void	doble_rotation(t_stack *a, t_stack *b)
{
	rotate(a, '\0');
	rotate(b, '\0');
	write(1, "rr\n", 3);
}

void	doble_reverse_rotation(t_stack *a, t_stack *b)
{
	reverse_rotation(a, '\0');
	reverse_rotation(b, '\0');
	write(1, "rrr\n", 4);
}
