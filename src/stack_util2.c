/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:48:15 by user              #+#    #+#             */
/*   Updated: 2019/10/03 08:39:38 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		indexof_min_val(long *stack)
{
	int		i;
	long	min;
	int		pos;

	pos = -1;
	i = 0;
	min = NULL_VALUE;
	while (stack[i] != NULL_VALUE)
	{
		if (stack[i] < min)
		{
			min = stack[i];
			pos = i;
		}
		++i;
	}
	return (pos);
}

int		indexof_max_val(long *stack)
{
	int		i;
	long	max;
	int		pos;

	pos = -1;
	i = 0;
	max = (NULL_VALUE * -1) - 1;
	while (stack[i] != NULL_VALUE)
	{
		if (stack[i] > max)
		{
			max = stack[i];
			pos = i;
		}
		++i;
	}
	return (pos);
}

int		indexof_val(long *stack, long value)
{
	int i;

	i = 0;
	while (stack[i] != NULL_VALUE)
	{
		if (stack[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int		quick_rotate_to_top(long **stack, long nb)
{
	int middle;
	int opt;
	int nb_moves;

	middle = size_stack(*stack) / 2;
	nb_moves = 0;
	if (indexof_val(*stack, nb) <= middle)
		opt = 1;
	else
		opt = 2;
	while ((*stack)[0] != nb)
	{
		if (opt == 2)
			nb_moves += rev_rotate(stack);
		else
			nb_moves += rotate(stack);
	}
	return (nb_moves);
}

void	clean_stack(long **stack, int len)
{
	int i;

	i = len;
	while ((*stack)[i] != NULL_VALUE)
	{
		(*stack)[i] = NULL_VALUE;
		++i;
	}
}
