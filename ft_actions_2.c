/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:47:17 by clanglai          #+#    #+#             */
/*   Updated: 2018/02/14 17:25:14 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_ra(t_pile *pa)
{
	t_pile *tmp;
	int		first;
	int		sort;
	
	tmp = pa;
	first = tmp->content;
	sort = tmp->sort;
	while (tmp->next)
	{
		tmp->content = tmp->next->content;
		tmp->sort = tmp->next->sort;
		tmp = tmp->next;
	}
	tmp->content = first;
	tmp->sort = sort;
}

void	ft_rb(t_pile *pb)
{
	t_pile	*tmp;
	int		first;
	int		sort;

	tmp = pb;
	first = tmp->content;
	sort = tmp->sort;
	while (tmp->next)
	{
		tmp->content = tmp->next->content;
		tmp->sort = tmp->next->sort;
		tmp = tmp->next;
	}
	tmp->content = first;
	tmp->sort = sort;
}

void	ft_rr(t_pile *pa, t_pile *pb)
{
	ft_ra(pa);
	ft_rb(pb);
}

void	ft_rra(t_pile *pa)
{
	t_pile *tmp;
	int		prev;
	int		current;
	int		p_sort;
	int		c_sort;

	if (pa)
	{
		current = pa->content;
		tmp = pa;
		c_sort = pa->sort;
		while (tmp->next)
		{
			p_sort = c_sort;
			prev = current;
			c_sort = tmp->sort;
			current = tmp->content;
			tmp->sort = p_sort;
			tmp->content = prev;
			tmp = tmp->next;
		}
		pa->content = tmp->content;
		pa->sort = tmp->sort;
		tmp->content = current;
		tmp->sort = c_sort;
	}
}

void	ft_rrb(t_pile *pb)
{
	t_pile *tmp;
	int		prev;
	int		current;
	int		p_sort;
	int		c_sort;

	if (pb)
	{
		current = pb->content;
		c_sort = pb->sort;
		tmp = pb;
		while (tmp->next)
		{
			p_sort = c_sort;
			prev = current;
			c_sort = tmp->sort;
			current = tmp->content;
			tmp->content = prev;
			tmp->sort = p_sort;
			tmp = tmp->next;
		}
		pb->content = tmp->content;
		pb->sort = tmp->sort;
		tmp->content = current;
		tmp->sort = c_sort;
	}
}
