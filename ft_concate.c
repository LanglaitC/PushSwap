/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:01:58 by clanglai          #+#    #+#             */
/*   Updated: 2018/02/14 14:57:31 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_add_at_end(t_pile **start, int act, t_pile **pa, t_pile **pb)
{
	t_pile *tmp;

	tmp = *start;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_lstnewpile(act);
	if (act == 2)
		ft_sa(*pa);
	if (act == 3)
		ft_sb(*pb);
	if (act == 5)
		ft_pa(pa, pb);
	if (act == 7)
		ft_pb(pa, pb);
	if (act == 11)
		ft_ra(*pa);
	if (act == 13)
		ft_rb(*pb);
	if (act == 17)
		ft_rra(*pa);
	if (act == 19)
		ft_rrb(*pb);
}

void	ft_print_res(t_pile **res)
{
	t_pile *tmp;
	int		state;

	tmp = *res;
	while (tmp)
	{
		if (tmp->next)
			state = tmp->content * tmp->next->content;
		else
			state = 0;
		if (state == 6 || state == 143 || state == 323)
		{
			tmp = tmp->next;
			if (state == 6)
				ft_printf("ss\n");
			if (state == 143)
				ft_printf("rr\n");
			if (state == 323)
				ft_printf("rrr\n");
		}
		else
		{
			if (tmp->content == 2)
				ft_printf("sa\n");
			if (tmp->content == 3)
				ft_printf("sb\n");
			if (tmp->content == 5)
				ft_printf("pa\n");			
			if (tmp->content == 7)
				ft_printf("pb\n");
			if (tmp->content == 11)
				ft_printf("ra\n");
			if (tmp->content == 13)
				ft_printf("rb\n");
			if (tmp->content == 17)
				ft_printf("rra\n");
			if (tmp->content == 19)
				ft_printf("rrb\n");
		}
		tmp = tmp->next;
	}
}

