/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:22:22 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/07 14:34:14 by clanglai         ###   ########.fr       */
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

	i = 1;
	if (ft_check_int(argv[i]) == 0)
		return (0);
	*start = ft_lstnewpile(ft_atoi(argv[i++]));
	tmp = *start;
	while (i < argc)
	{
		if (ft_check_int(argv[i]) == 0)
			return (0);
		tmp->next = ft_lstnewpile(ft_atoi(argv[i]));
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void	ft_sort_pile(t_pile **pa, t_pile **pb, int argc, char argv)
{
	int		state;
	t_pile	*tmp;

	state = 0;
	while(state == 0)
	{
		tmp = *pa;
		if (tmp->next)
		{
			if (tmp->next->content < tmp->content)
			{
				ft_sa(*pa);
				ft_printf("sa\n");
			}
			ft_ra(pa);
			ft_printf("ra");
		}
		state = ft_check_sort(pa, pb);
	}	
}

int main(int argc, char **argv)
{
	t_pile	*start;
	t_pile	*pb;

	pb = NULL;
	start = NULL;
	if (argc > 1)
	{
		if (!(ft_create_a_pile(&start, argc, argv)))
		{
			ft_printf("Error\n");
			return (0);
		}
		ft_sort_pile(&start, &pb, argc, argv);
	}
	return (0);
}
