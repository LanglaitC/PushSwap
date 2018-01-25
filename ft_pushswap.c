/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:22:22 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/25 16:54:17 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int		ft_check_int(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
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

/*void	ft_sort_pile(t_pile **pa, t_pile **pb, int argc, char **argv)
{
	int		state;
	t_pile	*tmp;
	int		highest;

	state = 0;
	highest = ft_find_max(pa);
	while (state == 0)
	{
		tmp = *pa;
		if (tmp->next)
		{
			if (tmp->next->content < tmp->content && tmp->content != highest)
			{
				ft_sa(*pa);
				ft_printf("sa\n");
			}
			ft_ra(*pa);
			ft_printf("ra\n");
		}
		state = ft_check_sort(pa, pb);
	}	
}*/

int		ft_check_single_sort(t_pile **pa)
{
	t_pile *tmp;
	int		prev;

	if (!(*pa))
		return (1);
	if (!((*pa)->next))
		return (1);
	tmp = *pa;
	prev = tmp->content;
	while (tmp->next)
	{
		if (tmp->content < prev)
			return (0);
		prev = tmp->content;
		tmp = tmp->next;
	}
	if (tmp->content < prev)
		return (0);
	return (1);
}

int		ft_check_single_inv_sort(t_pile **pa)
{
	t_pile *tmp;
	int		prev;

	if (!(*pa))
		return (1);
	if (!((*pa)->next))
		return (1);
	tmp = *pa;
	prev = tmp->content;
	while (tmp->next)
	{
		if (tmp->content > prev)
			return (0);
		prev = tmp->content;
		tmp = tmp->next;
	}
	if (tmp->content > prev)
		return (0);
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
			printf("[%d] ", tmp->content);
			tmp = tmp->next;
		}
		printf("[%d]", tmp->content);
		printf("\n\n");
	}
	tmp = *pb;
	if (tmp)
	{
		printf("	Pile b = ");
		while(tmp->next)
		{
			printf("[%d] ", tmp->content);
			tmp = tmp->next;
		}
		printf("[%d]", tmp->content);
		printf("\n\n");
	}
	printf("-----------------------------------------------------------------------\n\n");
}

void	ft_sort_pile_a(t_pile **pa, t_pile **pb, t_pile **res)
{
	int state;
	int last;

	state = ft_check_single_sort(pa);
	if (ft_count_elem(pa))
	//	last = ft_find_ele_x(pa, (ft_count_elem(pa) / (ft_count_sorted(pa) > (ft_count_elem(pa)) ? 1 : 2)));
		last = ft_find_ele_x(pa, ft_count_elem(pa));
	else
		last = 0;
	while (state == 0)
	{
		if ((*pa)->content == last)
			state = 1;
		if ((*pa)->content > last)
			ft_add_at_end(res, 11, pa, pb);
		else if ((*pa)->content > (*pa)->next->content)
			ft_add_at_end(res, 2, pa, pb);
		else
			ft_add_at_end(res, 7, pa, pb);
		state = state == 1 ? 1 : ft_check_single_sort(pa);
	}
}

void	ft_sort_pile_b(t_pile **pa, t_pile **pb, t_pile **res)
{
	int		state;
	t_pile	*tmp;
	int		last;

	tmp = *res;
	state = ft_check_single_inv_sort(pb);
	if (*pb && state)
		while (*pb)
			ft_add_at_end(res, 5, pa, pb);
	if (ft_count_elem(pb))
		last = ft_find_ele_x(pb, ft_count_elem(pb));
	else
		last = 0;
	while (state == 0)
	{	
		if ((*pb)->content == last)
			state = 1;
		else if ((*pb)->content < last)
			ft_add_at_end(res, 13, pa, pb);
		else if ((*pb)->content < (*pb)->next->content)
			ft_add_at_end(res, 3, pa, pb);
		else
			ft_add_at_end(res, 5, pa, pb);
		state = (state == 1) ? 1 : ft_check_single_inv_sort(pb);
	}
}

void	ft_sort_pile(t_pile **pa, t_pile **pb)
{
	int		state;
	t_pile	*res;

	state = 0;
	res = ft_lstnewpile(0);
	while (state == 0)
	{
		ft_sort_pile_a(pa, pb, &res);
		ft_sort_pile_b(pa, pb, &res);
		state = ft_check_sort(pa, pb);
	}
	//print_state(pa, pb);
	ft_print_res(&res);
}
