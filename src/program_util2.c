/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:20:10 by trponess          #+#    #+#             */
/*   Updated: 2019/10/03 10:14:19 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void			find_posa(long **stack_a, long *pos_a, int chunk[2])
{
	int i;

	i = 0;
	while (i < size_stack(*stack_a))
	{
		if (*pos_a == NULL_VALUE && (*stack_a)[i] >= chunk[0] \
		&& (*stack_a)[i] <= chunk[1])
			*pos_a = i;
		if (*pos_a != NULL_VALUE)
			break ;
		++i;
	}
}

void			find_posb(long **stack_a, long pos_a, long *pos_b, int chunk[2])
{
	int i;

	i = size_stack(*stack_a) - 1;
	while (i >= 0)
	{
		if (*pos_b == NULL_VALUE && (long)i != pos_a \
		&& (*stack_a)[i] >= chunk[0] && (*stack_a)[i] <= chunk[1])
			*pos_b = i;
		if (*pos_b != NULL_VALUE)
			break ;
		--i;
	}
}

void			ft_dmemdel(char ***arrptr)
{
	char	**arr;
	int		i;

	i = 0;
	arr = *arrptr;
	while (arr[i])
	{
		if (arr[i])
			free((void*)arr[i]);
		i++;
	}
	free((void*)arr);
	*arrptr = NULL;
}
