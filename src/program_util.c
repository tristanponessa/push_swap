/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:19:16 by trponess          #+#    #+#             */
/*   Updated: 2019/10/03 08:40:47 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		increase_chunk(int jump, int *c1, int *c2)
{
	*c1 += jump;
	*c2 += jump;
}

void		pass_b_sort_to_a(long **stack_b, long **stack_a, int *nb_moves)
{
	while (size_stack(*stack_b) > 0)
	{
		*nb_moves += quick_rotate_to_top(stack_b, \
		(*stack_b)[indexof_max_val(*stack_b)]);
		*nb_moves += pass_to(stack_b, stack_a);
	}
}

int			action(long pos_a, long pos_b, long **stack_a, long **stack_b)
{
	int nb_moves;

	nb_moves = 0;
	if (size_stack(*stack_b) != 0)
		nb_moves += quick_rotate_to_top(stack_b,
		(*stack_b)[indexof_min_val(*stack_b)]);
	if (pos_a != NULL_VALUE && pos_b != NULL_VALUE)
	{
		if (pos_a < size_stack(*stack_a) - pos_b)
			nb_moves += quick_rotate_to_top(stack_a, (*stack_a)[pos_a]);
		else
			nb_moves += quick_rotate_to_top(stack_a, (*stack_a)[pos_b]);
	}
	if (pos_b == NULL_VALUE && pos_a != NULL_VALUE)
		nb_moves += quick_rotate_to_top(stack_a, (*stack_a)[pos_a]);
	if (pos_b != NULL_VALUE && pos_a == NULL_VALUE)
		nb_moves += quick_rotate_to_top(stack_a, (*stack_a)[pos_b]);
	return (nb_moves);
}

int			init_chunk(int *chunk1, int *chuck2, long **stack_a)
{
	int lowest;
	int max;
	int jump;

	lowest = (*stack_a)[indexof_min_val(*stack_a)];
	max = (*stack_a)[indexof_max_val(*stack_a)];
	if (size_stack(*stack_a) >= 100 && size_stack(*stack_a) < 500)
		jump = max / 5;
	else if (size_stack(*stack_a) >= 500)
		jump = max / 11;
	else
		jump = INT_MAX;
	*chunk1 = lowest;
	*chuck2 = lowest + jump;
	return (jump);
}
