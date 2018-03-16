/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visualize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 13:42:55 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/16 15:17:11 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_initialize_window(t_win *win, t_pile *pa)
{
	int i;

	i = 0;
	win->nb_ele = ft_count_elem(&pa, -1);
	if (!(win->tab = malloc(sizeof(int) * (win->nb_ele + 1))))
		exit(1);
	if (win->nb_ele > 600)
		win->size_l = 1;
	else
		win->size_l = win->nb_ele > 300 ? 2 : 1;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, T_WIDTH, T_HEIGHT, "Push_Swap");
	win->img = mlx_new_image(win->mlx, T_WIDTH, T_HEIGHT);
	win->str = mlx_get_data_addr(win->img, &(win->bpp), &(win->s_p),
			&(win->end));
	while (pa)
	{
		win->tab[i] = pa->content;
		pa = pa->next;
		i++;
	}
	win->tab[i] = 0;
	ft_sort_int_tab(win->tab, win->nb_ele);
}

void	ft_pixel_put_image(t_win *info, int x, int y, unsigned int col)
{
	unsigned int color;

	color = (((float)col / info->nb_ele) * 100) * 0x00001000;
	info->str[x * info->bpp / 8 + y * info->s_p + 3] = (color >> 24);
	info->str[x * info->bpp / 8 + y * info->s_p + 2] = (color >> 16) & 0xFE;
	info->str[x * info->bpp / 8 + y * info->s_p + 1] = (color >> 8) & 0xFE;
	info->str[x * info->bpp / 8 + y * info->s_p] = (color) & 0xFE;
}

void	ft_line(int height, int width, int s, t_win *win)
{
	float x;
	float y;
	int i;
	int j;

	x = (s == 1 ? T_WIDTH / 16 : T_WIDTH / 16 * 9) + T_WIDTH / 6 - T_WIDTH / 6 *
		((float)width / win->nb_ele);
	y = (T_HEIGHT / 10) * 9 - height * 3;
	i = x;
	while (i < x + T_WIDTH / 6 * ((float)width / win->nb_ele) * 2)
	{
		j = 0;
		while (j < win->size_l)
		{
			ft_pixel_put_image(win, i, j + y, width);
			j++;
		}
		i++;
	}
}



void	ft_print_graph(t_pile *pa, t_pile *pb, t_win *win)
{
	int i;

	i = ft_count_elem(&pa, -1);
	while (i > 0)
	{
		ft_line(i, ft_tab_index(win->tab, ft_find_ele_x(&pa, i), win->nb_ele) + 1, 1, win);
		i--;
	}
	i = ft_count_elem(&pb, -1);
	while (i > 0)
	{
		ft_line(i, ft_tab_index(win->tab, ft_find_ele_x(&pb, i), win->nb_ele), 2, win);
		i--;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	mlx_destroy_image(win->mlx, win->img);
	win->img = mlx_new_image(win->mlx, T_WIDTH, T_HEIGHT);
	win->str = mlx_get_data_addr(win->img, &(win->bpp), &(win->s_p),
			&(win->end));
}
