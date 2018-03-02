/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_fonc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:19:11 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/02 12:50:42 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_attribute_sort(t_pile **pb, int sort, int state)
{
	t_pile *tmp;

	tmp = *pb;
	while (tmp)
	{
		if (tmp->sort == 0 || state == 1)
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
/*
void	ft_find_last_three(t_pile **pb, int sort, t_insert *max, int len)
{
	t_pile	*tmp;
	int		i;
	int		j;
	int		*tab;

	j = 0;
	i = 0;
	if (!(tab = malloc(sizeof(int) * len) + 1))
		exit(0);
	tmp = *pb;
	while (i < len)
	{
		if (tmp->sort == sort || sort == -1)
		{
			tab[j] = tmp->content;
			j++;
		}
		i++;
		tmp = tmp->next;
	}
	ft_sort_int_tab(tab, len);
	max[2] = ft_init_t_insert(max[2], tab[len]);
	max[1] = ft_init_t_insert(max[1], tab[len - 1]);
	max[0] = ft_init_t_insert(max[0], tab[len - 2]);
}
*/
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
