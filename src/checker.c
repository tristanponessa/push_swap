/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:32:29 by trponess          #+#    #+#             */
/*   Updated: 2019/10/13 23:59:35 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		rot_actions(long *stack_a, long *stack_b, char *act)
{
	if (ft_strcmp("ra", act) == 0)
		rrotate(&stack_a);
	if (ft_strcmp("rb", act) == 0)
		rrotate(&stack_b);
	if (ft_strcmp("rr", act) == 0)
	{
		rrotate(&stack_a);
		rrotate(&stack_b);
	}
	if (ft_strcmp("rra", act) == 0)
		rrev_rotate(&stack_a);
	if (ft_strcmp("rrb", act) == 0)
		rrev_rotate(&stack_b);
	if (ft_strcmp("rrr", act) == 0)
	{
		rrev_rotate(&stack_a);
		rrev_rotate(&stack_b);
	}
}

static void		pass_actions(long *stack_a, long *stack_b, char *act)
{
	if (ft_strcmp("pa", act) == 0)
		ppass_to(&stack_b, &stack_a);
	if (ft_strcmp("pb", act) == 0)
		ppass_to(&stack_a, &stack_b);
}

static void		swap_actions(long *stack_a, long *stack_b, char *act)
{
	if (ft_strcmp("sa", act) == 0)
		sswap(&stack_a);
	if (ft_strcmp("sb", act) == 0)
		sswap(&stack_b);
	if (ft_strcmp("ss", act) == 0)
	{
		sswap(&stack_a);
		sswap(&stack_b);
	}
}

static void		launch_actions(long *stack_a, long *stack_b, char *act)
{
	rot_actions(stack_a, stack_b, act);
	swap_actions(stack_a, stack_b, act);
	pass_actions(stack_a, stack_b, act);
}

void			checker(long *stack_a, long *stack_b)
{
	char	act_list[1000][1000];
	int		end;
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (!is_ope(line) || i > 999999)
		{
			ft_putendl_fd("Error", 2);
			return ;
		}
		ft_strcpy(act_list[i], line);
		++i;
	}
	end = i;
	i = 0;
	while (i < end)
		launch_actions(stack_a, stack_b, act_list[i++]);
	if (is_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
