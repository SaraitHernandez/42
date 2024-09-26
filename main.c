/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:25:02 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/26 11:02:57 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib/push_swap.h"
/*
#include <stdio.h>

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
*/

static void	process_input(t_stack *stack_a, int argc, char *argv[])
{
	int		i;
	char	**arg;

	if (argc == 2)
	{
		arg = ft_split(argv[1], ' ');
		if (!arg)
			error(NULL, NULL);
		i = 0;
		while (arg[i] != NULL)
		{
			push(stack_a, parse_int(arg[i], stack_a, arg));
			i++;
		}
		free_split(arg);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			push(stack_a, parse_int(argv[i], stack_a, NULL));
			i++;
		}
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
		sort_four(stack_a);
	else
		push_swap(stack_a);
	destroy_stack(stack_a);
	return (0);
}
