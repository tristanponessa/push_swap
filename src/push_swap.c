/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:34:23 by trponess          #+#    #+#             */
/*   Updated: 2019/10/03 12:41:54 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int				push_swap(long **stack_a, long **stack_b)
{
	int nb_moves;
	int len_stack_a;

	len_stack_a = size_stack(*stack_a);
	nb_moves = 0;
	if (is_sorted(*stack_a))
		;
	else if (size_stack(*stack_a) == 2)
		nb_moves = program_2nb(stack_a);
	else if (size_stack(*stack_a) == 3)
		nb_moves = program_3nb(stack_a);
	else if (size_stack(*stack_a) == 4)
		nb_moves = program_4nb(stack_a, stack_b);
	else if (size_stack(*stack_a) == 5)
		nb_moves = program_5nb(stack_a, stack_b);
	else
		nb_moves = program_over_5nb(stack_a, stack_b);
	clean_stack(stack_a, len_stack_a);
	clean_stack(stack_b, size_stack(*stack_b));
	if (!is_sorted(*stack_a))
		ft_printf("FAILED\n");
	return (nb_moves);
}
