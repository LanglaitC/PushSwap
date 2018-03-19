/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:01:58 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/19 16:23:00 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_pushswap.h"

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

void	ft_concat_rb_rrb(t_pile **res, int s)
{
	int count;
	int i;

	count = 1;
	i = 0;
	while ((*res)->next && count)
		if ((s == 13 || s == 19) && ((*res)->next->content == 13 ||
					(*res)->next->content == 19))
		{
			if (s == 13)
				count += ((*res)->next->content == 13) ? 1 : -1;
			else if (s == 19)
				count += ((*res)->next->content == 19) ? 1 : -1;
			*res = (*res)->next;
		}
		else
			break ;
	while (i < count)
	{
		if (s == 13)
			ft_printf("rb\n");
		else
			ft_printf("rrb\n");
		i++;
	}
}

void	ft_concat_ra_rra(t_pile **res, int s)
{
	int count;
	int i;

	count = 1;
	i = 0;
	while ((*res)->next && count)
		if ((s == 11 || s == 17) && ((*res)->next->content == 11 ||
					(*res)->next->content == 17))
		{
			if (s == 11)
				count += ((*res)->next->content == 11) ? 1 : -1;
			else if (s == 17)
				count += ((*res)->next->content == 17) ? 1 : -1;
			*res = (*res)->next;
		}
		else
			break ;
	while (i < count)
	{
		if (s == 11)
			ft_printf("ra\n");
		else
			ft_printf("rra\n");
		i++;
	}
}

void	ft_print_res(t_pile **res)
{
	t_pile	*tmp;
	int		state;

	tmp = *res;
	while (tmp)
	{
		state = tmp->next ? tmp->content * tmp->next->content : 0;
		if (state == 6 || state == 143)
			ft_printf("%s\n", state == 6 ? "ss" : "rr");
		else if (state == 323)
			ft_printf("rrr\n");
		else if (tmp->content == 2 || tmp->content == 3)
			ft_printf("%s\n", tmp->content == 2 ? "sa" : "sb");
		else if (tmp->content == 5 || tmp->content == 7)
			ft_printf("%s\n", tmp->content == 5 ? "pa" : "pb");
		else if (tmp->content == 11 || tmp->content == 17)
			ft_concat_ra_rra(&tmp, tmp->content);
		else if (tmp->content == 13 || tmp->content == 19)
			ft_concat_rb_rrb(&tmp, tmp->content);
		tmp = state == 6 || state == 143 || state == 323 ?
			tmp->next->next : tmp->next;
	}
	ft_free(res);
}

void	ft_free(t_pile **list)
{
	t_pile *tmp;
	t_pile *next;

	tmp = *list;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}
