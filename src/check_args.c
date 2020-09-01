/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 10:01:29 by trponess          #+#    #+#             */
/*   Updated: 2019/10/09 08:56:42 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int		check_duplicates(char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

static int		check_syntax(char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		if (av[i][0] != '-' && av[i][0] != '+' && !ft_isdigit(av[i][0]))
			return (0);
		if ((av[i][0] == '-' || av[i][0] == '+') && ft_strlen(av[i]) == 1)
			return (0);
		j = 1;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

static long		ft_atol(const char *str)
{
	int		i;
	int		neg;
	long	result;

	i = 0;
	neg = 1;
	result = 0;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n' \
	|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f'))
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		result = result * 10;
		result = result + (str[i] - '0');
		i++;
	}
	return (result * neg);
}

static int		check_nb_size(char **av)
{
	int		i;
	long	l;

	i = 1;
	while (av[i])
	{
		if (ft_strlen(av[i]) > 11)
			return (0);
		l = ft_atol(av[i]);
		if (l > INT_MAX || l < INT_MIN)
			return (0);
		++i;
	}
	return (1);
}

char			**check_args(int ac, char **av)
{
	char **n_av;

	n_av = clean_av(ac, av);
	if (!check_syntax(n_av) || !check_nb_size(n_av) || !check_duplicates(n_av))
		return (NULL);
	return (n_av);
}
