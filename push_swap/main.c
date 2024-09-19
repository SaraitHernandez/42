/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarait.hernandez@novateva.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:25:02 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/19 13:27:24 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib/push_swap.h"

static void	handle_four_elements(t_stack *stack_a)
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

static void	process_input(t_stack *stack_a, int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		push(stack_a, parse_int(argv[i], stack_a));
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	int		size;

	if (argc < 2)
		return (0);
	stack_a = create_stack();
	process_input(stack_a, argc, argv);
	size = stack_len(stack_a);
	if (is_sorted(stack_a) || size == 1)
	{
		destroy_stack(stack_a);
		return (0);
	}
	if (size == 2 || size == 3)
		min_sort(stack_a, size);
	else if (size == 4)
		handle_four_elements(stack_a);
	else
		push_swap(stack_a);
	destroy_stack(stack_a);
	return (0);
}
