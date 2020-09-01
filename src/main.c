/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:31:21 by trponess          #+#    #+#             */
/*   Updated: 2019/10/21 15:18:26 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	get_exec_nb(char *path)
{
	int		i;

	i = ft_strlen(path) - 1;
	while (i > 0 && path[i] != '/')
		i--;
	++i;
	if (ft_strcmp(&path[i], "checker") == 0)
		return (1);
	if (ft_strcmp(&path[i], "push_swap") == 0)
		return (2);
	return (0);
}

static int	d_len(char **n_av)
{
	int i;

	i = 0;
	while (n_av[i])
		++i;
	return (i);
}

char		**clean_av(int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	char	**tmp;
	char	**new_av;

	new_av = ft_dstrnew(1000, 1000);
	i = 1;
	k = 1;
	while (i < ac)
	{
		j = 0;
		tmp = ft_split_spaces(av[i], ' ');
		while (tmp[j])
		{
			ft_strcpy(new_av[k], tmp[j]);
			++j;
			++k;
		}
		++i;
	}
	new_av[k] = NULL;
	return (new_av);
}

int			main(int ac, char **av)
{
	long	*stack_a;
	long	*stack_b;
	int		ex_nb;
	char	**n_av;

	if (!(n_av = check_args(ac, av)))
	{
		ft_printf("Error\n");
		return (0);
	}
	stack_a = init_stack(d_len(n_av), n_av, 'a');
	stack_b = init_stack(d_len(n_av), n_av, 'b');
	if (!stack_a || !stack_b)
		return (0);
	if (size_stack(stack_a) != 0)
	{
		ex_nb = get_exec_nb(av[0]);
		if (ex_nb == 1)
			checker(stack_a, stack_b);
		if (ex_nb == 2)
			push_swap(&stack_a, &stack_b);
	}
	ft_memdel((void *)&stack_a);
	ft_memdel((void *)&stack_b);
}
