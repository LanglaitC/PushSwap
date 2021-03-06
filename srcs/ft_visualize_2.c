/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visualize_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 12:14:04 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/20 16:27:22 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_pushswap.h"

int		ft_tab_index(int *tab, int val, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (tab[i] == val)
			return (len - i);
		i++;
	}
	return (-1);
}

int		ft_handle_keys(int keycode, t_win *win)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 12)
		if (win->acts)
			ft_exec_all(win);
	return (1);
}

int		ft_handle_keypressing(t_win *win)
{
	mlx_hook(win->win, 2, (1L << 0), ft_handle_keys, win);
	return (1);
}

void	ft_exec_all(t_win *win)
{
	t_list *next;

	ft_choose_actions(&win->pa, &win->pb, win->acts->content);
	next = win->acts->next;
	free(win->acts->content);
	free(win->acts);
	win->acts = next;
	if (win->c_flag)
		ft_print_graph(win->pa, win->pb, win);
}
