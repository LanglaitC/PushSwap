/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:22:17 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/12 15:22:02 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	ft_check_double_input(t_pile **pile, int number)
{
	t_pile	*tmp;

	tmp = *pile;
	while (tmp->next)
	{
		if (tmp->content == number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_count_sorted(t_pile **pa)
{
	t_pile	*tmp;
	int		prev;
	int		res;

	res = 1;
	if (!(*pa))
		return (-1);
	if (!(*pa)->next)
		return (-1);
	tmp = *pa;
	prev = tmp->content;
	while (tmp->next)
	{
		if (tmp->content < prev)
			return (res);
		prev = tmp->content;
		res++;
		tmp = tmp->next;
	}
	if (tmp->content < prev)
		return (res);
	return (res);
}

int	ft_count_inv_sorted(t_pile **pa)
{
	t_pile	*tmp;
	int		prev;
	int		res;

	res = 0;
	if (!(*pa))
		return (-1);
	if (!(*pa)->next)
		return (-1);
	tmp = *pa;
	prev = tmp->content;
	while (tmp->next)
	{
		if (tmp->content > prev)
			return (res);
		prev = tmp->content;
		res++;
		tmp = tmp->next;
	}
	if (tmp->content > prev)
		return (res);
	return (-1);
}

int	ft_is_next(t_pile **pa)
{
	int		number;
	t_pile	*tmp;

	tmp = *pa;
	number = tmp->content;
	while (tmp->next)
	{
		if (number == (*pa)->content && tmp->content > number)
			number = tmp->content;
		if (tmp->content < number && tmp->content > (*pa)->content)
			number = tmp->content;
		tmp = tmp->next;
	}
	return (number);
}
