/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_aux_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:21:49 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/26 11:01:09 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack_a, int a, int b)
{
	if (a > b)
		swap(stack_a, "sa\n");
}

void	sort_three(t_stack *stack_a, int a, int b, int c)
{
	if (a > b && b < c && a < c)
		swap(stack_a, "sa\n");
	else if (a > b && b > c)
	{
		swap(stack_a, "sa\n");
		reverse_rotation(stack_a, "rra\n");
	}
	else if (a > b && b < c && a > c)
		rotate(stack_a, "ra\n");
	else if (a < b && b > c && a < c)
	{
		swap(stack_a, "sa\n");
		rotate(stack_a, "ra\n");
	}
	else if (a < b && b > c && a > c)
		reverse_rotation(stack_a, "rra\n");
}

void	sort_four(t_stack *stack_a)
{
	t_stack	*stack_b;
	int		target_position;

	stack_b = create_stack();
	push_and_put(stack_b, stack_a);
	write(1, "pb\n", 3);
	min_sort(stack_a, 3);
	target_position = get_target_position(stack_a, stack_b->head->data);
	move_stack_a(stack_a, target_position);
	push_and_put(stack_a, stack_b);
	write(1, "pa\n", 3);
	final_rotate(stack_a);
	destroy_stack(stack_b);
}

void	perform_simultaneous_rotations(t_stack *s_a, t_stack *s_b, int move)
{
	if (move == 1)
		doble_rotation(s_a, s_b);
	else
		doble_reverse_rotation(s_a, s_b);
}

void	perform_stack_rotation(t_stack *stack, int move, char stack_id)
{
	if (stack_id == 'a')
	{
		if (move == 1)
			rotate(stack, "ra\n");
		else
			reverse_rotation(stack, "rra\n");
	}
	else if (stack_id == 'b')
	{
		if (move == 1)
			rotate(stack, "rb\n");
		else
			reverse_rotation(stack, "rrb\n");
	}
}
