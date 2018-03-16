/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 14:41:20 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/16 13:08:43 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	ft_find_max(t_pile **pa, int sort)
{
	t_pile	*tmp;
	int		highest;

	tmp = *pa;
	highest = tmp->content;
	while (tmp)
	{
		if (highest < tmp->content && (tmp->sort == sort || sort == -1))
			highest = tmp->content;
		tmp = tmp->next;
	}
	return (highest);
}

int	ft_find_min(t_pile **pa, int sort)
{
	t_pile	*tmp;
	int		lowest;

	tmp = *pa;
	lowest = tmp->content;
	while (tmp)
	{
		if (lowest > tmp->content && (tmp->sort == sort || sort == -1))
			lowest = tmp->content;
		tmp = tmp->next;
	}
	return (lowest);
}

int	ft_find_med(t_pile **pa, int len, int sort)
{
	t_pile	*tmp;
	int		i;
	int		med;
	int		*tab;
	int		j;

	j = 0;
	i = 0;
	if (!(tab = malloc(sizeof(int) * len + 1)))
		exit(0);
	tmp = *pa;
	while (tmp)
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
		i++;
		tmp = tmp->next;
	}
	return (tmp->content);
}

int	ft_count_elem(t_pile **pa, int sort)
{
	t_pile	*tmp;
	int		i;

	i = 0;
	if (*pa)
	{
		tmp = *pa;
		while (tmp)
		{
			if (tmp->sort == sort || sort == -1)
				i++;
			tmp = tmp->next;
		}
		if (tmp != NULL)
		{
			if (tmp->sort == sort || sort == -1)
				i++;
		}
	}
	return (i);
}
