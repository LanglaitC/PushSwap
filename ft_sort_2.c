/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:13:33 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/12 15:21:25 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_sort_pile_b_less_than_3(t_pile **pa, t_pile **pb, t_pile **re, int s)
{
	int state;
	int way;

	state = ft_check_single_inv_sort(pb, s);
	if (*pb && state)
		while (*pb && ((*pb)->sort == s || (s == -1 && *pb)))
			ft_add_at_end(re, 5, pa, pb);
	state = ft_count_elem(pb, s) == 0;
	while (state == 0)
	{
		if ((*pb)->content == ft_find_max(pb, s))
			ft_add_at_end(re, 5, pa, pb);
		else
		{
			way = ft_find_index(pb, ft_find_max(pb, s)) >
				ft_count_elem(pb, -1) / 2;
			ft_add_at_end(re, way == 1 ? 19 : 13, pa, pb);
		}
		state = ft_count_elem(pb, s) == 0;
	}
}

void	ft_sort_pile_a_less_than_3(t_pile **pa, t_pile **pb, t_pile **re, int s)
{
	int		state;

	state = ft_check_single_sort(pa, -1);
	while (state == 0)
	{
		if ((*pa)->content > (*pa)->next->content
				&& (*pa)->sort == (*pa)->next->sort
				&& ((*pa)->sort == s || s == -1))
			ft_add_at_end(re, 2, pa, pb);
		else if ((*pa)->next->sort != s)
			ft_add_at_end(re, 17, pa, pb);
		else
			ft_add_at_end(re, 11, pa, pb);
		state = ft_check_single_sort(pa, -1);
	}
}

int		ft_find_index(t_pile **pa, int x)
{
	int		i;
	t_pile	*tmp;

	tmp = *pa;
	i = 0;
	while (tmp)
	{
		if (tmp->content == x)
			break ;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		ft_find_value_below(t_pile **pa, int x, int s)
{
	t_pile *tmp;

	tmp = *pa;
	while (tmp)
	{
		if (tmp->content < x && (tmp->sort == s || s == -1))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		ft_find_value_above(t_pile **pa, int x, int s)
{
	t_pile *tmp;

	tmp = *pa;
	while (tmp)
	{
		if (tmp->content > x && (tmp->sort == s || s == -1))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
