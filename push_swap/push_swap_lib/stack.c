/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarait.hernandez@novateva.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:25:32 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/19 11:00:59 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		error();
	stack->head = NULL;
	stack->tail = NULL;
	return (stack);
}

void	push(t_stack *stack, int data)
{
	t_node	*new_node;

	check_duplicates(stack, data);
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		destroy_stack(stack);
		error();
	}
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (is_empty(stack))
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		new_node->prev = stack->tail;
		stack->tail->next = new_node;
		stack->tail = new_node;
	}
}

void	display_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		data;

	if (is_empty(stack))
	{
		destroy_stack(stack);
		error();
	}
	temp = stack->head;
	data = temp->data;
	if (stack->head == stack->tail)
	{
		stack->head = NULL;
		stack->tail = NULL;
	}
	else
	{
		stack->head = stack->head->next;
		stack->head->prev = NULL;
	}
	free(temp);
	return (data);
}

void	destroy_stack(t_stack *stack)
{
	while (!is_empty(stack))
		pop(stack);
	free(stack);
}
