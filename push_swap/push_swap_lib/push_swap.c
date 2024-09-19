/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarait.hernandez@novateva.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:29:10 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/19 13:35:04 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *stack_a)
{
	t_stack	*stack_b;

	initialize_stack_b(stack_a, &stack_b);
	move_elements_to_stack_b(stack_a, stack_b);
	min_sort(stack_a, 3);
	move_elements_back_to_stack_a(stack_a, stack_b);
	final_rotate(stack_a);
	destroy_stack(stack_b);
}

void	initialize_stack_b(t_stack *stack_a, t_stack **stack_b)
{
	*stack_b = create_stack();
	push_and_put(*stack_b, stack_a);
	write(1, "pb\n", 3);
	push_and_put(*stack_b, stack_a);
	write(1, "pb\n", 3);
}

static void	free_memory(int *costs_a, int *costs_b, int *index_b)
{
	free(costs_a);
	free(costs_b);
	free(index_b);
}

void	move_elements_to_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	int		size_a;
	t_costs	costs;
	int		index;

	size_a = stack_len(stack_a);
	while (size_a > 3)
	{
		costs.costs_a = (int *)malloc(size_a * sizeof(int));
		costs.costs_b = (int *)malloc(size_a * sizeof(int));
		costs.index_b = (int *)malloc(size_a * sizeof(int));
		if (!costs.costs_a || !costs.costs_b || !costs.index_b)
		{
			destroy_stack(stack_a);
			error();
		}
		calculate_costs(stack_a, stack_b, &costs);
		index = find_cheapest_element(stack_a, costs.costs_a, costs.costs_b);
		execute_moves(stack_a, stack_b, index, costs.index_b[index]);
		push_and_put(stack_b, stack_a);
		write(1, "pb\n", 3);
		size_a--;
		free_memory(costs.costs_a, costs.costs_b, costs.index_b);
	}
}

void	move_elements_back_to_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	target_position;

	while (!is_empty(stack_b))
	{
		target_position = get_target_position(stack_a, stack_b->head->data);
		move_stack_a(stack_a, target_position);
		push_and_put(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
}
