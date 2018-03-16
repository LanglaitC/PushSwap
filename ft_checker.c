/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 13:05:47 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/16 13:29:31 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_choose_actions(t_pile **pa, t_pile **pb, char *line)
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

int		ft_is_valid_action(t_win *win, char *line)
{
	t_list	*tmp;
	char	*act;
	
	tmp = win->acts;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew(act = ft_strdup(line), ft_strlen(line));
		free(act);
	}
	else
		win->acts = ft_lstnew(line, ft_strlen(line));

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

int		ft_check_sort(t_pile **pa, t_pile **pb)
{
	t_pile	*tmp;
	int		prev;

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
	tmp = *pb;
	if (tmp)
	{
		return (0);
	}
	return (1);
}

void	ft_exec_all(t_win *win)
{
	ft_choose_actions(&win->pa, &win->pb, win->acts->content);
	free(win->acts->content);
	free(win->acts);
	win->acts = win->acts->next;
	if (win->c_flag)
		ft_print_graph(win->pa, win->pb, win);
}

int	ft_handle_keys(int keycode, t_win *win)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 12)
		if (win->acts)
			ft_exec_all(win);
	return (1);
}

int		ft_execute_actions(t_win *win)
{
	char	*line;

	line = NULL;
	win->acts = NULL;
	while (get_next_line(0, &line) == 1)
	{
		if (!(ft_is_valid_action(win, line)))
			return (-1);
		free(line);
	}
	free(line);
	ft_exec_all(win);
	if (win->c_flag)
	{
		mlx_loop_hook(win->mlx, ft_handle_keypressing, win);
		mlx_loop(win->mlx);
	}
	else
		while (win->acts)
			ft_exec_all(win);
	if (!(ft_check_sort(&win->pa, &win->pb)))
		return (0);
	ft_free(&win->pa);
	ft_free(&win->pb);
	return (1);
}
