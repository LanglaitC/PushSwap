/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 14:41:20 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/25 14:13:28 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	ft_find_max(t_pile **pa)
{
	t_pile *tmp;
	int highest;

	tmp = *pa;
	highest = tmp->content;
	while (tmp->next)
	{
		if (highest < tmp->content)
			highest = tmp->content;
		tmp = tmp->next;	
	}
	if (highest < tmp->content)
		highest = tmp->content;
	return (highest);
}

int	ft_find_min(t_pile **pa)
{
	t_pile	*tmp;
	int		lowest;

	tmp = *pa;
	lowest = tmp->content;
	while (tmp->next)
	{
		if (lowest > tmp->content)
			lowest = tmp->content;
		tmp = tmp->next;	
	}
	if (lowest > tmp->content)
		lowest = tmp->content;
	return (lowest);
}

int	ft_find_med(t_pile **pa, int len)
{
	t_pile	*tmp;
	int		i;
	int		med;
	int		*tab;

	i = 0;
	if (!(tab = malloc(sizeof(int) * len + 1)))
		exit (0);
	tmp = *pa;
	while (i < len)
	{
		tab[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	ft_sort_int_tab(tab, len);
	med = tab[(len / 2)];
	ft_memdel((void**)&tab);
	return (med);
}

int	ft_find_ele_x(t_pile **pa, int x)
{
	t_pile	*tmp;
	int		i;

	i = 0;
	tmp = *pa;
	while (i < x - 1)
	{
		i ++;
		tmp = tmp->next;
	}
	return (tmp->content);
}

int	ft_count_elem(t_pile **pa)
{
	t_pile *tmp;
	int	i;

	i = 0;
	if (*pa)
	{
		tmp = *pa;
		while (tmp->next)
		{
			i++;
			tmp = tmp->next;
		}
		if (tmp != NULL)
			i++;
	}
	return (i);
}
