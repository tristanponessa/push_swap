/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 02:31:49 by user              #+#    #+#             */
/*   Updated: 2019/10/02 17:21:56 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		program_2nb(long **stack_a)
{
	swap(stack_a);
	return (1);
}

int		program_3nb(long **stack_a)
{
	int a;
	int b;
	int c;
	int nb_moves;

	a = (*stack_a)[0];
	b = (*stack_a)[1];
	c = (*stack_a)[2];
	nb_moves = 0;
	if (a > b && a < c && b < c)
		nb_moves += swap(stack_a);
	if (a > b && a > c && b > c)
	{
		nb_moves += swap(stack_a);
		nb_moves += rev_rotate(stack_a);
	}
	if (a > b && a > c && b < c)
		nb_moves += rotate(stack_a);
	if (a < b && a < c && b > c)
	{
		nb_moves += swap(stack_a);
		nb_moves += rotate(stack_a);
	}
	nb_moves += (a < b && a > c && b > c) ? rev_rotate(stack_a) : 0;
	return (nb_moves);
}

int		program_4nb(long **stack_a, long **stack_b)
{
	int nb_moves;
	int min;

	min = indexof_min_val(*stack_a);
	nb_moves = 0;
	nb_moves += quick_rotate_to_top(stack_a, (*stack_a)[min]);
	nb_moves += pass_to(stack_a, stack_b);
	nb_moves += program_3nb(stack_a);
	nb_moves += pass_to(stack_b, stack_a);
	return (nb_moves);
}

int		program_5nb(long **stack_a, long **stack_b)
{
	int nb_moves;
	int max;

	max = indexof_max_val(*stack_a);
	nb_moves = 0;
	nb_moves += quick_rotate_to_top(stack_a, (*stack_a)[max]);
	nb_moves += pass_to(stack_a, stack_b);
	nb_moves += program_4nb(stack_a, stack_b);
	nb_moves += pass_to(stack_b, stack_a);
	nb_moves += rotate(stack_a);
	return (nb_moves);
}

int		program_over_5nb(long **stack_a, long **stack_b)
{
	int		nb_moves;
	int		chunk[2];
	long	pos_a;
	long	pos_b;
	int		jump;

	nb_moves = 0;
	jump = init_chunk(&chunk[0], &chunk[1], stack_a);
	while (size_stack(*stack_a) > 0)
	{
		pos_a = NULL_VALUE;
		pos_b = NULL_VALUE;
		find_posa(stack_a, &pos_a, chunk);
		find_posb(stack_a, pos_a, &pos_b, chunk);
		if (pos_a == NULL_VALUE && pos_b == NULL_VALUE)
		{
			increase_chunk(jump, &chunk[0], &chunk[1]);
			continue ;
		}
		nb_moves += action(pos_a, pos_b, stack_a, stack_b);
		nb_moves += pass_to(stack_a, stack_b);
	}
	pass_b_sort_to_a(stack_b, stack_a, &nb_moves);
	return (nb_moves);
}
