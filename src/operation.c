/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 02:29:27 by user              #+#    #+#             */
/*   Updated: 2019/10/13 23:57:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		swap(long **stack)
{
	long tmp;

	if (size_stack(*stack) < 2)
		return (1);
	if (get_stack_id(*stack) == STACK_A_ID)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
	tmp = (*stack)[0];
	(*stack)[0] = (*stack)[1];
	(*stack)[1] = tmp;
	return (1);
}

int		rotate(long **stack)
{
	int		i;
	long	tmp;

	i = 0;
	if (get_stack_id(*stack) == STACK_A_ID)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
	tmp = (*stack)[0];
	while ((*stack)[i + 1] != NULL_VALUE)
	{
		(*stack)[i] = (*stack)[i + 1];
		++i;
	}
	(*stack)[i] = tmp;
	return (1);
}

int		rev_rotate(long **stack)
{
	int		i;
	long	tmp;

	if (get_stack_id(*stack) == STACK_A_ID)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
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

int		pass_to(long **src, long **dest)
{
	long tmp;

	if (size_stack(*src) == 0)
		return (1);
	if (get_stack_id(*dest) == STACK_A_ID)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
	decale_right(dest);
	tmp = (*dest)[0];
	(*dest)[0] = (*src)[0];
	(*dest)[size_stack(*dest)] = tmp;
	decale_left(src);
	(*src)[size_stack(*src) - 1] = NULL_VALUE;
	return (1);
}

int		is_ope(char *line)
{
	if (ft_strcmp(line, "sa") != 0 && \
		ft_strcmp(line, "sb") != 0 && \
		ft_strcmp(line, "ss") != 0 && \
		ft_strcmp(line, "ra") != 0 && \
		ft_strcmp(line, "rb") != 0 && \
		ft_strcmp(line, "rr") != 0 && \
		ft_strcmp(line, "rra") != 0 && \
		ft_strcmp(line, "rrb") != 0 && \
		ft_strcmp(line, "rrr") != 0 && \
		ft_strcmp(line, "pa") != 0 && \
		ft_strcmp(line, "pb") != 0)
		return (0);
	return (1);
}
