/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:08:34 by clanglai          #+#    #+#             */
/*   Updated: 2018/02/14 16:59:33 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_sa(t_pile *pa)
{
	int tmp;
	int	sort;

	if (pa)
	{
		if (pa->next)
		{
			tmp = pa->content;
			pa->content = pa->next->content;
			pa->next->content = tmp;
			sort = pa->sort;
			pa->sort = pa->next->sort;
			pa->next->sort = sort;
		}
	}
}

void	ft_sb(t_pile *pb)
{
	int tmp;
	int	sort;

	if (pb)
	{
		if (pb->next)
		{
			tmp = pb->content;
			pb->content = pb->next->content;
			pb->next->content = tmp;
			sort = pb->sort;
			pb->sort = pb->next->sort;
			pb->next->sort = sort;
		}
	}

}

void	ft_ss(t_pile *pa, t_pile *pb)
{
	ft_sb(pa);
	ft_sa(pb);
}

void	ft_pa(t_pile **pa, t_pile **pb)
{
	t_pile *tmp;

	if (*pb)
	{
		tmp = (*pb)->next;
		(*pb)->next = *pa;
		*pa = *pb;
		*pb = tmp;
	}
}

void	ft_pb(t_pile **pa, t_pile **pb)
{
	t_pile *tmp;

	if (*pa)
	{
		tmp = (*pa)->next;
		(*pa)->next = *pb;
		*pb = *pa;
		*pa = tmp;
	}
}
