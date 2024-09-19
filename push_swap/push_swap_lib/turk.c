/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarait.hernandez@novateva.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:25:17 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/19 13:53:47 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_movements(int index, int stack_len)
{
	int	move;

	if (index <= stack_len / 2)
		move = 1;
	else
		move = -1;
	return (move);
}

void	execute_moves(t_stack *stack_a, t_stack *stack_b, int i_a, int i_b)
{
	int	move_a;
	int	move_b;
	int	cost_a;
	int	cost_b;

	cost_a = calculate_cost_to_top(stack_a, i_a);
	cost_b = calculate_cost_to_top(stack_b, i_b);
	move_a = calculate_movements(i_a, stack_len(stack_a));
	move_b = calculate_movements(i_b, stack_len(stack_b));
	while (cost_a > 0 && cost_b > 0 && move_a == move_b)
	{
		perform_simultaneous_rotations(stack_a, stack_b, move_a);
		cost_a--;
		cost_b--;
	}
	while (cost_a > 0)
	{
		perform_stack_rotation(stack_a, move_a, 'a');
		cost_a--;
	}
	while (cost_b > 0)
	{
		perform_stack_rotation(stack_b, move_b, 'b');
		cost_b--;
	}
}

void	min_sort(t_stack *stack_a, int size)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->head->data;
	b = stack_a->head->next->data;
	if (size == 2)
		sort_two(stack_a, a, b);
	else
	{
		c = stack_a->tail->data;
		sort_three(stack_a, a, b, c);
	}
}

void	move_stack_a(t_stack *stack_a, int position)
{
	int	size;
	int	i;

	size = stack_len(stack_a);
	if (position <= size / 2)
	{
		i = 0;
		while (i < position)
		{
			rotate(stack_a, "ra\n");
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < size - position)
		{
			reverse_rotation(stack_a, "rra\n");
			i++;
		}
	}
}

void	final_rotate(t_stack *stack_a)
{
	int	position;

	position = get_min_position(stack_a);
	move_stack_a(stack_a, position);
}
