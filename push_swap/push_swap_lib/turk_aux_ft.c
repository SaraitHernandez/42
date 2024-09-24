/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_aux_ft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:25:25 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/23 11:03:20 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_position(t_stack *stack)
{
	int		min;
	int		position;
	int		index;
	t_node	*temp;

	min = get_min(stack);
	position = 0;
	index = 0;
	temp = stack->head;
	while (temp)
	{
		if (temp->data == min)
		{
			position = index;
			break ;
		}
		index++;
		temp = temp->next;
	}
	return (position);
}

int	get_target_position(t_stack *stack_b, int value)
{
	t_node	*temp;
	t_node	*next_node;
	int		index;
	int		size_b;

	temp = stack_b->head;
	index = 0;
	size_b = stack_len(stack_b);
	while (temp != NULL && index < size_b)
	{
		if (temp->next != NULL)
			next_node = temp->next;
		else
			next_node = stack_b->head;
		if (temp->data > next_node->data)
		{
			if (value > temp->data || value < next_node->data)
				return ((index + 1) % size_b);
		}
		else if (value > temp->data && value < next_node->data)
			return (index + 1);
		index++;
		temp = temp->next;
	}
	return (0);
}

int	calculate_cost_to_top(t_stack *stack, int index)
{
	int	size;

	size = stack_len(stack);
	if (index <= size / 2)
		return (index);
	else
		return (size - index);
}

void	calculate_costs(t_stack *stack_a, t_stack *stack_b, t_costs *costs)
{
	int		index;
	t_node	*temp;
	int		index_b;

	index = 0;
	temp = stack_a->head;
	index_b = 0;
	while (temp)
	{
		costs->costs_a[index] = calculate_cost_to_top(stack_a, index);
		costs->index_b[index] = get_target_position(stack_b, temp->data);
		index_b = costs->index_b[index];
		costs->costs_b[index] = calculate_cost_to_top(stack_b, index_b);
		index++;
		temp = temp->next;
	}
}

int	find_cheapest_element(t_stack *stack_a, int *costs_a, int *costs_b)
{
	int		index;
	int		min_total_cost;
	int		min_index;
	t_node	*temp;
	int		cost;

	index = 0;
	min_total_cost = 2147483647;
	min_index = 0;
	temp = stack_a->head;
	while (temp)
	{
		cost = costs_a[index] + costs_b[index];
		if (cost < min_total_cost)
		{
			min_total_cost = cost;
			min_index = index;
		}
		index++;
		temp = temp->next;
	}
	return (min_index);
}
