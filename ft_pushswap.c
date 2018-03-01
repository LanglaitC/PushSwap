/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:22:22 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/01 14:55:14 by clanglai         ###   ########.fr       */
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

int		ft_check_single_sort(t_pile **pa, int sort)
{
	t_pile *tmp;
	int		prev;
	int		state;
	int		prev_s;

	if (!(*pa))
		return (1);
	if ((*pa)->sort != sort && sort != -1)
		return (1);
	if (!((*pa)->next))
		return (1);
	tmp = *pa;
	prev = tmp->content;
	prev = tmp->sort;
	state = 1;
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
	t_pile *tmp;
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

void	print_state(t_pile **pa, t_pile **pb)
{
	t_pile *tmp;

	printf("\n-----------------------------------------------------------------------\n\n");
	tmp = *pa;
	if (tmp)
	{
		printf("	Pile a = ");
		while(tmp->next)
		{
			printf("[%d %d] ", tmp->content, tmp->sort);
			tmp = tmp->next;
		}
		printf("[%d %d]", tmp->content, tmp->sort);
		printf("\n\n");
	}
	tmp = *pb;
	if (tmp)
	{
		printf("	Pile b = ");
		while(tmp->next)
		{
			printf("[%d %d] ", tmp->content, tmp->sort);
			tmp = tmp->next;
		}
		printf("[%d %d]", tmp->content, tmp->sort);
		printf("\n\n");
	}
	printf("-----------------------------------------------------------------------\n\n");
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
	way = (*pa)->next->sort == s;
	while (j <= i)
	{
		if (((*pa)->content < last))
			ft_add_at_end(res, 7, pa, pb);
		else
			ft_add_at_end(res, way == 1 ? 17 : 11, pa, pb);
		j++;
	}
}
/*
void	ft_sort_pile_b(t_pile **pa, t_pile **pb, t_pile **res, int s)
{
	int	state;
	int	way;
	int i;
   
	state = ft_check_single_inv_sort(pb, s);
	i = ft_find_max(pb, s);
	way = ft_find_index(pa, i) > ft_count_elem(pb, -1) / 2;
	while ((*pb)->content != i)
		ft_add_at_end(res, way == 1 ? 19 : 13, pa, pb);
	ft_add_at_end(res, 5, pa, pb);
}*/

void	ft_sort_pile_b(t_pile **pa, t_pile **pb, t_pile **res, int s)
{
	int			i;
	int			way;
	int			last;
	int			j;
//	int			state;

//	state = ft_check_single_inv_sort(pb, s);
//	if (*pb && state)
//		while ((*pb)->sort == s || (s == -1 && *pb))
//			ft_add_at_end(res, 5, pa, pb);
	if (ft_count_elem(pb, s))
		last = ft_find_med(pb, ft_count_elem(pb, s), s);
	else
		last = 0;
	i = ft_count_elem(pb, s);
	way = (*pb)->next->sort == s;
	j = 0;
	while (j <= i)
	{
		if ((*pb)->content > last && ((*pb)->sort == s || s == -1))
			ft_add_at_end(res, 5, pa, pb);
		else
			ft_add_at_end(res, way == 1 ? 13 : 19, pa, pb);
		j++;
	}
}

void	ft_sort_pile_b_less_than_3(t_pile **pa, t_pile **pb, t_pile **res, int s)
{
	int state;
	int way;

	state = ft_check_single_inv_sort(pb, s);
	if (*pb && state)
		while (*pb && ((*pb)->sort == s || (s == -1 && *pb)))
			ft_add_at_end(res, 5, pa, pb);
	while (state == 0)
	{
		if ((*pb)->content == ft_find_max(pb, s))
			ft_add_at_end(res, 5, pa, pb);
		else
		{
			way = ft_find_index(pb, ft_find_max(pb, s)) > ft_count_elem(pb, -1) / 2;
			ft_add_at_end(res, way == 1 ? 19 : 13, pa, pb);
		}
		state = ft_count_elem(pb, s) == 0;
	}
}

void	ft_sort_pile_a_less_than_3(t_pile **pa, t_pile **pb, t_pile **res, int s)
{
	int		state;
	
	state = ft_check_single_sort(pa, s);
	while (state == 0)
	{
		if ((*pa)->content > (*pa)->next->content && (*pa)->sort == (*pa)->next->sort
				&& ((*pa)->sort == s || s == -1))
			ft_add_at_end(res, 2, pa, pb);
		else if ((*pa)->next->sort != s)
			ft_add_at_end(res, 17, pa, pb);
		else
			ft_add_at_end(res, 11, pa, pb);
		state = ft_check_single_sort(pa, -1);
	}
}

void	ft_sort_pile(t_pile **pa, t_pile **pb)
{
	int		state;
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
			ft_sort_pile_a(pa, pb, &res, -1);
			ft_attribute_sort(pb, sort, 0);
			sort++;
		}
	}
	sort--;
	while (ft_check_sort(pa, pb) == 0)
	{
		while (ft_count_elem(pb, sort) > 3)
			ft_sort_pile_b(pa, pb, &res, sort);
		while (ft_count_elem(pa, sort) > 3)
			ft_sort_pile_a(pa, pb, &res, sort);
		ft_sort_pile_a_less_than_3(pa, pb, &res, -1);
		if (ft_check_single_sort(pa, -1) && ft_count_elem(pb, sort) <= 3)
		{
			ft_sort_pile_b_less_than_3(pa, pb, &res, sort);
			sort--;
		}
	}
	ft_print_res(&res);
}
