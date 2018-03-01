/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:13:33 by clanglai          #+#    #+#             */
/*   Updated: 2018/02/15 12:54:24 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_sort_elem_pile_a(t_pile **pa, t_pile **pb, t_pile **res, int s)
{

}

void	ft_sort_elem_pile_b(t_pile **pa, t_pile **pb, t_pile **res, int s)
{
	t_pile	*tmp;


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
		if (tmp->content < x && (tmp ->sort == s || s == -1))
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
		if (tmp->content > x && (tmp ->sort == s || s == -1))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
