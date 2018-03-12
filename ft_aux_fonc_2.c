/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_fonc_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:21:13 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/12 15:38:16 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_print_state(t_pile **pa, t_pile **pb)
{
	t_pile *tmp;

	ft_printf("\n----------------------------------------------------\n\n");
	tmp = *pa;
	if (tmp)
	{
		printf("	Pile a = ");
		while (tmp)
		{
			ft_printf("[%d %d] ", tmp->content, tmp->sort);
			tmp = tmp->next;
		}
		ft_printf("\n\n");
	}
	tmp = *pb;
	if (tmp)
	{
		ft_printf("	Pile b = ");
		while (tmp)
		{
			ft_printf("[%d %d] ", tmp->content, tmp->sort);
			tmp = tmp->next;
		}
	}
	ft_printf("\n\n------------------------------------------------------\n\n");
}

int		ft_check_single_sort(t_pile **pa, int sort)
{
	t_pile	*tmp;
	int		prev;
	int		prev_s;

	if (!(*pa))
		return (1);
	if ((*pa)->sort != sort && sort != -1)
		return (1);
	if (!((*pa)->next))
		return (1);
	tmp = *pa;
	prev = tmp->content;
	prev_s = tmp->sort;
	while (tmp)
	{
		if (tmp->content < prev && (tmp->sort == prev_s || sort == -1))
			return (0);
		prev = tmp->content;
		prev_s = tmp->sort;
		tmp = tmp->next;
	}
	return (1);
}

int		ft_check_single_inv_sort(t_pile **pa, int sort)
{
	t_pile	*tmp;
	int		prev;
	int		prev_s;

	if (!(*pa))
		return (1);
	if ((*pa)->sort != sort && sort != -1)
		return (1);
	if (!((*pa)->next))
		return (1);
	tmp = *pa;
	prev = tmp->content;
	prev_s = tmp->sort;
	while (tmp)
	{
		if (tmp->content > prev && (tmp->sort == prev_s || sort == -1))
			return (0);
		prev = tmp->content;
		prev_s = tmp->sort;
		tmp = tmp->next;
	}
	return (1);
}

int		ft_find_sort_x(t_pile **pa, int x)
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
	return (tmp->sort);
}
