/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarait.hernandez@novateva.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:13:02 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/19 13:07:18 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char *op)
{
	t_node	*first;
	t_node	*second;

	if (stack->head && stack->head->next)
	{
		first = stack->head;
		second = stack->head->next;
		first->next = second->next;
		if (second->next)
			second->next->prev = first;
		second->prev = NULL;
		second->next = first;
		first->prev = second;
		stack->head = second;
		if (stack->tail == second)
			stack->tail = first;
	}
	if (op)
		write(1, op, 3);
}

void	push_and_put(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!is_empty(b))
	{
		node = b->head;
		if (b->head == b->tail)
		{
			b->head = NULL;
			b->tail = NULL;
		}
		else
		{
			b->head = b->head->next;
			b->head->prev = NULL;
		}
		put(a, node);
	}
}

void	rotate(t_stack *a, char *op)
{
	t_node	*first;

	if (a->head && a->head != a->tail)
	{
		first = a->head;
		a->head = first->next;
		a->head->prev = NULL;
		first->next = NULL;
		first->prev = a->tail;
		a->tail->next = first;
		a->tail = first;
	}
	if (op)
		write(1, op, 3);
}

void	reverse_rotation(t_stack *a, char *op)
{
	t_node	*last;

	if (a->head && a->head != a->tail)
	{
		last = a->tail;
		a->tail = last->prev;
		a->tail->next = NULL;
		last->prev = NULL;
		last->next = a->head;
		a->head->prev = last;
		a->head = last;
	}
	if (op)
		write(1, op, 4);
}
