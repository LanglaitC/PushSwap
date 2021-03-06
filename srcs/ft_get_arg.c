/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:50:10 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/20 16:17:15 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_pushswap.h"

int		ft_check_int(char *str)
{
	int i;
	int state;
	int j;
	int val;

	state = 1;
	i = 0;
	j = 0;
	val = ft_atoi(str);
	if ((j = ft_strlen(ft_strlchr(str, '-'))) > 10)
		return (0);
	if (j == 10 && ((ft_count_char_start(str, '-') % 2 && val > 0)
				|| (!(ft_count_char_start(str, '-') % 2) && val < 0)))
		return (0);
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

int		ft_create_a_pile(t_win *win, int argc, char **argv)
{
	t_pile	*tmp;
	int		i;
	int		number;

	i = win->c_flag ? 2 : 1;
	if (ft_check_int(argv[i]) == 0)
		return (0);
	win->pa = ft_lstnewpile(ft_atoi(argv[i++]));
	tmp = win->pa;
	while (i < argc)
	{
		if (ft_check_int(argv[i]) == 0)
			return (0);
		number = ft_atoi(argv[i]);
		tmp->next = ft_lstnewpile(number);
		if (ft_check_double_input(&win->pa, number) == 0)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int		ft_create_a_pile_arg(t_win *win, char **argv)
{
	t_pile	*tmp;
	int		i;
	int		number;
	char	**tab;

	i = 0;
	tab = ft_strsplit(argv[win->c_flag ? 2 : 1], ' ');
	if (ft_check_int(tab[i]) == 0)
		return (0);
	free(tab[i]);
	win->pa = ft_lstnewpile(ft_atoi(tab[i++]));
	tmp = win->pa;
	while (tab[i])
	{
		if (ft_check_int(tab[i]) == 0)
			return (0);
		number = ft_atoi(tab[i]);
		tmp->next = ft_lstnewpile(number);
		if (ft_check_double_input(&win->pa, number) == 0)
			return (0);
		tmp = tmp->next;
		free(tab[i++]);
	}
	free(tab);
	return (1);
}
