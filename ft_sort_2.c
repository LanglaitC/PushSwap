/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:13:33 by clanglai          #+#    #+#             */
/*   Updated: 2018/02/15 10:50:06 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_sort_elem_pile_a(t_pile **pa, t_pile **pb, t_pile **res, int s)
{
	int		state;
	t_pile	*tmp;

	state = 0;
	if (ft_count_elem(pa, s))
		state = 1;
	else if (ft_count_elem(pa, s) == 2)
	{
		if ((*pa)->content > (*pa)->next->content)
			ft_add_at_end(res, 2, pa, pb);
	}
	else if (ft_count_elem(pa, s) == 3)
	{
		if ((*pa)->content < (*pa)->next->content && (*pa)->next->content > (*pa)->next->next->content)
		{
			ft_add_at_end(res, 11, pa, pb);
			ft_add_at_end(res, 2, pa, pb);
			ft_add_at_end(res, 17, pa, pb);
		}
		else if ((*pa)->content > (*pa)->next->content && (*pa)->next->content > (*pa)->next->next->content)
		{
			ft_add_at_end(res, 2, pa, pb);
			ft_add_at_end(res, 11, pa, pb);
			ft_add_at_end(res, 2, pa, pb);
			ft_add_at_end(res, 17, pa, pb);
			ft_add_at_end(res, 2, pa, pb);
		}
		else if ((*pa)->content > (*pa)->next->content)
			ft_add_at_end(res, 2, pa, pb);
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
			break;
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
		if (tmp->content <= x && (tmp ->sort == s || s == -1))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
