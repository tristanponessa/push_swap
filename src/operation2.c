/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 10:59:52 by trponess          #+#    #+#             */
/*   Updated: 2019/10/03 11:01:54 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		sswap(long **stack)
{
	long tmp;

	if (size_stack(*stack) < 2)
		return (1);
	tmp = (*stack)[0];
	(*stack)[0] = (*stack)[1];
	(*stack)[1] = tmp;
	return (1);
}

int		rrotate(long **stack)
{
	int		i;
	long	tmp;

	i = 0;
	tmp = (*stack)[0];
	while ((*stack)[i + 1] != NULL_VALUE)
	{
		(*stack)[i] = (*stack)[i + 1];
		++i;
	}
	(*stack)[i] = tmp;
	return (1);
}

int		rrev_rotate(long **stack)
{
	int		i;
	long	tmp;

	i = size_stack(*stack) - 1;
	if (size_stack(*stack) - 1 < 0)
		return (1);
	tmp = (*stack)[size_stack(*stack) - 1];
	while (i - 1 >= 0)
	{
		(*stack)[i] = (*stack)[i - 1];
		--i;
	}
	(*stack)[0] = tmp;
	return (1);
}

int		ppass_to(long **src, long **dest)
{
	long tmp;

	if (size_stack(*src) == 0)
		return (1);
	decale_right(dest);
	tmp = (*dest)[0];
	(*dest)[0] = (*src)[0];
	(*dest)[size_stack(*dest)] = tmp;
	decale_left(src);
	(*src)[size_stack(*src) - 1] = NULL_VALUE;
	return (1);
}
