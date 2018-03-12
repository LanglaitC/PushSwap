/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_fonc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:19:11 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/12 13:49:20 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_attribute_sort(t_pile **pb, int sort, int state)
{
	t_pile *tmp;

	tmp = *pb;
	while (tmp)
	{
		if (state == 0 && tmp->sort == 0)
			tmp->sort = sort;
		else if ((tmp->sort == state || state == -1) && tmp->sort != 0)
			tmp->sort = sort;
		tmp = tmp->next;
	}
}

t_insert	ft_init_t_insert(t_insert ins, int n)
{
	ins.content = n;
	ins.found = 0;
	return (ins);
}

int		ft_find_min_index(t_pile **pb, t_insert* max, int len)
{
	int		min;
	int		i;

	i = 0;
	while (i < len)
	{
		if (max[i].found == 0 || i == len - 1)
		{
			min = ft_find_index(pb, max[i].content);
			break;
		}
	}
	i = 0;
	while (i < len)
	{
		if (ft_find_index(pb, max[i].content) < min && max[i].found != 1)
			min = ft_find_index(pb, max[i].content);
		i++;
	}
	return (min);
}
