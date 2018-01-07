/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 13:05:47 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/07 16:05:27 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void ft_choose_actions(t_pile **pa, t_pile **pb, char *line)
{
	if (ft_strequ(line, "sa"))
		ft_sa(*pa);
	else if (ft_strequ(line, "sb"))
		ft_sb(*pb);
	else if (ft_strequ(line, "ss"))
		ft_ss(*pa, *pb);
	else if (ft_strequ(line, "pa"))
		ft_pa(pa, pb);
	else if (ft_strequ(line, "pb"))
		ft_pb(pa, pb);
	else if (ft_strequ(line, "ra"))
		ft_ra(*pa);
	else if (ft_strequ(line, "rb"))
		ft_rb(*pb);
	else if (ft_strequ(line, "rr"))
		ft_rr(*pa, *pb);
	else if (ft_strequ(line, "rra"))
		ft_rra(*pa);
	else if (ft_strequ(line, "rrb"))
		ft_rrb(*pb);
	else if (ft_strequ(line, "rrr"))
	{
		ft_rra(*pa);
		ft_rrb(*pb);
	}
}

int	ft_is_valid_action(char *line)
{	
	if (ft_strequ(line, "sa") == 1 || ft_strequ(line, "sb") == 1)
		return (1);
	if (ft_strequ(line, "ss") == 1 || ft_strequ(line, "pa") == 1)
		return (1);
	if (ft_strequ(line, "pb") == 1 || ft_strequ(line, "ra") == 1)
		return (1);
	if (ft_strequ(line, "rr") == 1 || ft_strequ(line, "rb") == 1)
		return (1);
	if (ft_strequ(line, "rra") == 1 || ft_strequ(line, "rrb") == 1)
		return (1);
	if (ft_strequ(line, "rrr") == 1)
		return (1);
	return (0);
}

int	ft_check_sort(t_pile **pa, t_pile **pb)
{
	t_pile	*tmp;
	int		prev;

	tmp = *pa;
	prev = tmp->content;
	while(tmp->next)
	{
//		ft_printf("A : %d\n", tmp->content);
		if (tmp->content < prev)
			return (0);
		prev = tmp->content;
		tmp = tmp->next;
	}	
//	ft_printf("A : %d\n", tmp->content);
	if (tmp->content < prev)
			return (0);
	tmp = *pb;
	if (tmp)
	{
		return (0);
		while(tmp->next)
		{
			ft_printf("B : %d\n", tmp->content);
			tmp = tmp->next;
		}
		ft_printf("B : %d\n", tmp->content);
	}
	return (1);
}

int ft_execute_actions(t_pile **pile_a, int argc, char **argv)
{
	char	*line;
	t_pile	*pile_b;

	line = NULL;
	pile_b = NULL;
	while(get_next_line(1, &line) == 1)
	{
		printf("Hello\n");
		if (!(ft_is_valid_action(line)))
			return (-1);
		ft_choose_actions(pile_a, &pile_b, line);
	}
	if (!(ft_check_sort(pile_a, &pile_b)))
		return (0);
	return (1);
}
