/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarait.hernandez@novateva.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:29:43 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/19 11:01:17 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	int		size;
	t_node	*temp;

	size = 0;
	temp = stack->head;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

int	get_min(t_stack *stack)
{
	int		min;
	t_node	*temp;

	min = stack->head->data;
	temp = stack->head;
	while (temp)
	{
		if (temp->data < min)
			min = temp->data;
		temp = temp->next;
	}
	return (min);
}

int	is_sorted(t_stack *stack)
{
	t_node	*temp;

	temp = stack->head;
	while (temp && temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	check_duplicates(t_stack *stack, int data)
{
	t_node	*current;

	current = stack->head;
	while (current != NULL)
	{
		if (current->data == data)
		{
			destroy_stack(stack);
			error();
		}
		current = current->next;
	}
}

int	is_empty(t_stack *stack)
{
	return (stack->head == NULL);
}
