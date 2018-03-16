/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 15:26:58 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/16 13:48:56 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	main(int argc, char **argv)
{
	t_win	win;
	int		state;

	win.pa = NULL;
	win.c_flag = 0;
	win.pb = NULL;
	if (argc > 1)
	{
		if (argc != 2)
			state = ft_create_a_pile(&win, argc, argv);
		else
			state = ft_create_a_pile_arg(&win, argv);
		if (state == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		ft_sort_pile(&win.pa, &win.pb);
	}
	ft_free(&win.pa);
	ft_free(&win.pb);
	return (0);
}
