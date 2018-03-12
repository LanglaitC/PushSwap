/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:22:22 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/12 13:14:52 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int		ft_check_int(char *str)
{
	int i;
	int state = 1;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 && (str[i] != '-' || state != 1))
			return (0);
		if (ft_isdigit(str[i]) == 1)
			state = 0;
		i++;
	}
	return (1);
}

t_pile	*ft_lstnewpile(int i)
{
	t_pile *new;

	if (!(new = malloc(sizeof(t_pile))))
		exit(0);
	new->content = i;
	new->sort = 0;
	new->next = NULL;
	return (new);
}

int		ft_create_a_pile(t_pile **start, int argc, char **argv)
{
	t_pile	*tmp;
	int		i;
	int		number;

	i = 1;
	if (ft_check_int(argv[i]) == 0)
		return (0);
	*start = ft_lstnewpile(ft_atoi(argv[i++]));
	tmp = *start;
	while (i < argc)
	{
		if (ft_check_int(argv[i]) == 0)
			return (0);
		number = ft_atoi(argv[i]);
		tmp->next = ft_lstnewpile(number);
		if (ft_check_double_input(start, number) == 0)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int		ft_create_a_pile_arg(t_pile **start, int argc, char **argv)
{
	t_pile	*tmp;
	int		i;
	int		number;
	char	**tab;

	i = 0;
	tab = ft_strsplit(argv[1], ' ');
	if (ft_check_int(tab[i]) == 0)
		return (0);
	*start = ft_lstnewpile(ft_atoi(tab[i++]));
	tmp = *start;
	while (tab[i])
	{
		if (ft_check_int(tab[i]) == 0)
			return (0);
		number = ft_atoi(tab[i]);
		tmp->next = ft_lstnewpile(number);
		if (ft_check_double_input(start, number) == 0)
			return (0);
		tmp = tmp->next;
		free(tab[i]);
		i++;
	}
	free(tab);
	return (1);
}

void	ft_sort_first_pile_a(t_pile **pa, t_pile **pb, t_pile **res, int s)
{
	int state;
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

void	ft_sort_pile_a(t_pile **pa, t_pile **pb, t_pile **res, int s)
{
	int state;
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
	while ((way == 1 || ft_find_sort_x(pa, ft_count_elem(pa, -1)) == s) && ft_find_min(pa, s) <= last)
	{
		way = way == 0 ? 0 : (*pa)->next->sort == s || s == -1;
		if (((*pa)->content < last))
			ft_add_at_end(res, 7, pa, pb);
		else
			ft_add_at_end(res, way == 1 ? 11 : 17, pa, pb);
		j++;
	}
}

void	ft_sort_pile_b(t_pile **pa, t_pile **pb, t_pile **res, int s)
{
	int			i;
	int			way;
	int			last;
	int			j;
	int			k;

	if (ft_count_elem(pb, s))
		last = ft_find_med(pb, ft_count_elem(pb, s), s);
	else
		last = 0;
	if (*pb)
	{
	i = ft_count_elem(pb, s);
	j = 0;
	k = 0;
	way = (*pb)->next->sort == s || s == -1;
	while ((way == 1 || ft_find_sort_x(pb, ft_count_elem(pb, -1)) == s) && ft_find_max(pb, s) >= last)
	{
		if (i == j && ft_count_elem(pb, -1) == ft_count_elem(pb, s))
			break;
		way = way == 0 ? 0 : (*pb)->next->sort == s || s == -1;
		if ((*pb)->content > last && ((*pb)->sort == s || s == -1))
		{
			k++;
			ft_add_at_end(res, 5, pa, pb);
		}
		else
			ft_add_at_end(res, way == 1 ? 13 : 19, pa, pb);
		j++;
	}
	}
}

void	ft_sort_pile(t_pile **pa, t_pile **pb)
{
	int		state;
	t_pile	*res;
	int		sort;
	int		i;

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
	sort--;
	while (ft_check_sort(pa, pb) == 0)
	{
		ft_sort_pile_b(pa, pb, &res, ft_count_elem(pb, -2) ? -2 : sort);
		ft_attribute_sort(pa, -2, 2);
		while (ft_count_elem(pa, ft_count_elem(pa, -2) ? -2 : sort) > 3)
			ft_sort_pile_a(pa, pb, &res, ft_count_elem(pa, -2) ? -2 : sort);
		ft_sort_pile_a_less_than_3(pa, pb, &res, -1);
		ft_attribute_sort(pa, 0, 1);
		if (ft_check_single_sort(pa, -1) && ft_count_elem(pb, -2) <= 3)
		{
			ft_sort_pile_b_less_than_3(pa, pb, &res, -2);
			ft_sort_pile_b_less_than_3(pa, pb, &res, sort);
			ft_attribute_sort(pa, 0, 1);
			sort--;
		}
	}
	ft_print_res(&res);
}
