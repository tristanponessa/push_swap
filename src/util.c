/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 02:30:56 by user              #+#    #+#             */
/*   Updated: 2019/10/02 16:59:14 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_exit(char *msg)
{
	ft_printf("%s\n", msg);
	exit(0);
}

int		error_msg(int r, char *msg)
{
	ft_printf("%s\n", msg);
	return (r);
}

int		count(int len)
{
	static int i;

	if (i == len)
	{
		i = 0;
		return (-1);
	}
	else
		++i;
	return (i);
}

int		decale_right(long **stack)
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

int		decale_left(long **stack)
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
