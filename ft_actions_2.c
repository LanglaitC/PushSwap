/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:47:17 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/07 14:31:56 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_ra(t_pile *pa)
{
	t_pile *tmp;
	int		first;
	
	tmp = pa;
	first = tmp->content;
	while (tmp->next)
	{
		tmp->content = tmp->next->content;
		tmp = tmp->next;
	}
	tmp->content = first;
}

void	ft_rb(t_pile *pb)
{
	t_pile	*tmp;
	int		first;

	tmp = pb;
	first = tmp->content;
	while (tmp->next)
	{
		tmp->content = tmp->next->content;
		tmp = tmp->next;
	}
	tmp->content = first;
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

	if (pa)
	{
		current = pa->content;
		tmp = pa;
		while (tmp->next)
		{
			prev = current;
			current = tmp->content;
			tmp->content = prev;
			tmp = tmp->next;
		}
		pa->content = tmp->content;
		tmp->content = current;
	}
}

void	ft_rrb(t_pile *pb)
{
	t_pile *tmp;
	int		prev;
	int		current;

	if (pb)
	{
		current = pb->content;
		tmp = pb;
		while (tmp->next)
		{
			prev = current;
			current = tmp->content;
			tmp->content = prev;
			tmp = tmp->next;
		}
		pb->content = tmp->content;
		tmp->content = current;
	}
}
