/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:22:22 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/24 13:57:02 by clanglai         ###   ########.fr       */
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

void	ft_sort_pile_a(t_pile **pa, t_pile **pb)
{
	int state;

	state = ft_check_single_sort(pa);
	while (state == 0)
	{
		if ((*pa)->content > ft_find_ele_x(pa, ft_count_elem(pa)))
		{
			ft_ra(*pa);
			printf("ra\n");
		}
		else if ((*pa)->content > (*pa)->next->content)
		{
			ft_sa(*pa);
			printf("sa\n");
		}
		else
		{
			ft_pb(pa, pb);
			printf("pb\n");
		}
		state = ft_check_single_sort(pa);
		//print_state(pa, pb);
	}
}

void	ft_sort_pile_b(t_pile **pa, t_pile **pb, t_list **res)
{
	int		state;
	t_list	*tmp;

	tmp = *res;
	state = ft_check_single_inv_sort(pb);
	if (*pb && state)
		while (*pb)
		{
			ft_pa(pa, pb);

			printf("pa\n");
			state = 1;
		}
	while (state == 0)
	{	
		if ((*pb)->content < ft_find_ele_x(pb, ft_count_elem(pb)))
		{
			ft_rb(*pb);
			printf("rb\n");
		}
		else if ((*pb)->content < (*pb)->next->content)
		{
			ft_sb(*pb);
			printf("sb\n");
		}
		else
		{
			ft_pa(pa, pb);
			printf("pa\n");
		}
		state = ft_check_single_inv_sort(pb);
		//print_state(pa, pb);
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
}
