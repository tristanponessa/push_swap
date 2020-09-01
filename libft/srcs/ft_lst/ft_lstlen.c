/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trponess <trponess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:49:44 by trponess          #+#    #+#             */
/*   Updated: 2019/10/02 10:33:16 by trponess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_lstlen(t_list *elem)
{
	size_t len;

	len = 0;
	while (elem && elem->next)
	{
		len++;
		elem = elem->next;
	}
	return (len);
}
