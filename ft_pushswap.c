/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:22:22 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/16 13:44:23 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static void	ft_sort_first_pile_a(t_pile **pa, t_pile **pb, t_pile **res, int s)
{
	int last;
	int	way;
	int	i;
	int	j;

	if (ft_count_elem(pa, s))
		last = ft_find_med(pa, ft_count_elem(pa, s), s);
	else
		last = 0;
	j = 0;
	i = ft_count_elem(pa, s);
	way = (*pa)->next->sort == s || s == -1;
	while (j < i)
	{
		way = way == 0 ? 0 : (*pa)->next->sort == s || s == -1;
		if (((*pa)->content < last))
			ft_add_at_end(res, 7, pa, pb);
		else
			ft_add_at_end(res, way == 1 ? 11 : 17, pa, pb);
		j++;
	}
}

static void	ft_sort_pile_a(t_pile **pa, t_pile **pb, t_pile **res, int s)
{
	int last;
	int	way;
	int	i;
	int	j;

	if (ft_count_elem(pa, s))
		last = ft_find_med(pa, ft_count_elem(pa, s), s);
	else
		last = 0;
	j = 0;
	i = ft_count_elem(pa, s);
	way = (*pa)->next->sort == s || s == -1;
	while ((way == 1 || ft_find_sort_x(pa, ft_count_elem(pa, -1)) == s)
			&& ft_find_min(pa, s) <= last)
	{
		way = way == 0 ? 0 : (*pa)->next->sort == s || s == -1;
		if (((*pa)->content < last))
			ft_add_at_end(res, 7, pa, pb);
		else
			ft_add_at_end(res, way == 1 ? 11 : 17, pa, pb);
		j++;
	}
}

static void	ft_sort_pile_b(t_pile **pa, t_pile **pb, t_pile **res, int s)
{
	int			i;
	int			way;
	int			last;
	int			j;

	if (ft_count_elem(pb, s))
		last = ft_find_med(pb, ft_count_elem(pb, s), s);
	else
		last = 0;
	i = ft_count_elem(pb, s);
	j = 0;
	way = (*pb)->next->sort == s || s == -1;
	while ((way == 1 || ft_find_sort_x(pb, ft_count_elem(pb, -1)) == s) &&
			ft_find_max(pb, s) >= last)
	{
		if (i == j && ft_count_elem(pb, -1) == ft_count_elem(pb, s))
			break ;
		way = way == 0 ? 0 : (*pb)->next->sort == s || s == -1;
		if ((*pb)->content > last && ((*pb)->sort == s || s == -1))
			ft_add_at_end(res, 5, pa, pb);
		else
			ft_add_at_end(res, way == 1 ? 13 : 19, pa, pb);
		j++;
	}
}

static void	ft_sort_pile_2(t_pile **pa, t_pile **pb, t_pile *res, int sort)
{
	while (ft_check_sort(pa, pb) == 0)
	{
		while (ft_count_elem(pb, sort) > 6)
			ft_sort_pile_b(pa, pb, &res, sort);
		while (ft_count_elem(pa, sort) > 3)
			ft_sort_pile_a(pa, pb, &res, sort);
		ft_sort_pile_a_less_than_3(pa, pb, &res, -1);
		ft_attribute_sort(pa, 0, -1);
		if (ft_check_single_sort(pa, -1))
		{
			ft_sort_pile_b_less_than_3(pa, pb, &res, sort);
			ft_attribute_sort(pa, 0, 1);
			sort--;
		}
	}
}

void		ft_sort_pile(t_pile **pa, t_pile **pb)
{
	t_pile	*res;
	int		sort;

	res = ft_lstnewpile(0);
	sort = 1;
	while (ft_check_single_sort(pa, -1) == 0)
	{
		if (ft_count_elem(pa, -1) <= 3)
			ft_sort_pile_a_less_than_3(pa, pb, &res, -1);
		else
		{
			ft_sort_first_pile_a(pa, pb, &res, -1);
			ft_attribute_sort(pb, sort, 0);
			sort++;
		}
	}
	ft_sort_pile_2(pa, pb, res, sort - 1);
	ft_print_res(&res);
}
