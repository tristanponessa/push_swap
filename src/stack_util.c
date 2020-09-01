/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 02:33:35 by user              #+#    #+#             */
/*   Updated: 2019/10/03 08:40:04 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	*init_stack(int ac, char **av, char opt)
{
	long	*stack;
	int		i;

	i = 0;
	stack = (long *)malloc(sizeof(long) * (ac + 10));
	if (stack == NULL)
		return (NULL);
	while (i < ac + 10)
	{
		stack[i] = NULL_VALUE;
		++i;
	}
	i = 1;
	while (opt == 'a' && i < ac)
	{
		stack[i - 1] = (long)ft_atoi(av[i]);
		++i;
	}
	stack[ac + 9] = (opt == 'a') ? STACK_A_ID : STACK_B_ID;
	return (stack);
}

long	get_stack_id(long *stack)
{
	int i;

	i = 0;
	while (stack[i] != STACK_A_ID && stack[i] != STACK_B_ID)
		++i;
	return (stack[i]);
}

void	display_stack(long *stack, char which)
{
	int i;

	i = 0;
	ft_printf("%c[", which);
	while (stack[i] != NULL_VALUE)
	{
		ft_printf("%ld, ", stack[i]);
		i++;
	}
	if (stack[i] == NULL_VALUE)
		ft_printf("<%ld>", stack[i]);
	ft_printf("]\n");
}

int		is_sorted(long *stack)
{
	int i;

	i = 0;
	while (stack[i + 1] != NULL_VALUE)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		++i;
	}
	return (1);
}

int		size_stack(long *stack)
{
	int i;

	i = 0;
	while (stack[i] != NULL_VALUE)
		i++;
	return (i);
}
