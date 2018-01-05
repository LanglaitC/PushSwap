/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:22:22 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/05 15:44:35 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/inc/libft.h"
#include "ft_pushswap.h"

t_pile	*ft_lstnewpile(int i)
{
	t_pile *new;

	if (!(new = malloc(sizeof(t_pile))))
		exit(0);
	new->content = i;
	new->next = NULL;
	return (new);
}

void	ft_create_a_pile(t_pile **start, int argc, char **argv)
{
	t_pile	*tmp;
	int		i;

	i = 1;
	*start = ft_lstnewpile(ft_atoi(argv[i++]));
	tmp = *start;
	while (i < argc)
	{
		tmp->next = ft_lstnewpile(ft_atoi(argv[i]));
		tmp = tmp->next;
		i++;
	}
}

int main(int argc, char **argv)
{
	t_pile	*start;
	//t_pile	*tmp;

	start = NULL;
	if (argc > 1)
	{
		ft_create_a_pile(&start, argc, argv);
		ft_sort_pile(&start, argc, argv);
		/*
		tmp = start;
		while(tmp->next)
		{
			printf("%d\n", tmp->content);
			tmp = tmp->next;
		}
		*/
	}
	return (0);
}
