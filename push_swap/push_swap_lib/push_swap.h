/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarait.hernandez@novateva.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:25:47 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/19 13:54:20 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
}	t_stack;

typedef struct s_costs
{
	int	*costs_a;
	int	*costs_b;
	int	*index_b;
}	t_costs;

void	error(void);
int		parse_int(const char *str, t_stack *stack);
int		ft_atoi(const char *str, t_stack *stack);
t_stack	*create_stack(void);
int		is_empty(t_stack *stack);
void	check_duplicates(t_stack *stack, int data);
void	push(t_stack *stack, int data);
void	display_stack(t_stack *stack);
int		pop(t_stack *stack);
void	destroy_stack(t_stack *stack);
int		stack_len(t_stack *stack);
void	swap(t_stack *stack, char *op);
void	doble_swap(t_stack *a, t_stack *b);
void	put(t_stack *stack, t_node *node);
void	push_and_put(t_stack *a, t_stack *b);
void	rotate(t_stack *a, char *op);
void	doble_rotation(t_stack *a, t_stack *b);
void	reverse_rotation(t_stack *a, char *op);
void	doble_reverse_rotation(t_stack *a, t_stack *b);
int		get_min_position(t_stack *stack);
int		calculate_cost_to_top(t_stack *stack, int index);
void	final_rotate(t_stack *stack_a);
void	push_swap(t_stack *stack_a);
void	initialize_stack_b(t_stack *stack_a, t_stack **stack_b);
void	move_elements_to_stack_b(t_stack *stack_a, t_stack *stack_b);
void	move_elements_back_to_stack_a(t_stack *stack_a, t_stack *stack_b);
void	calculate_costs(t_stack *stack_a, t_stack *stack_b, t_costs *costs);
int		find_cheapest_element(t_stack *stack_a, int *costs_a, int *costs_b);
void	perform_stack_rotation(t_stack *stack, int move, char stack_id);
void	perform_simultaneous_rotations(t_stack *s_a, t_stack *s_b, int move);
void	execute_moves(t_stack *stack_a, t_stack *stack_b,
			int index_a, int index_b);
void	sort_three(t_stack *stack_a, int a, int b, int c);
void	sort_two(t_stack *stack_a, int a, int b);
void	min_sort(t_stack *stack_a, int size);
void	move_stack_a(t_stack *stack_a, int position);
int		is_sorted(t_stack *stack);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);
int		get_target_position(t_stack *stack_b, int value);

#endif