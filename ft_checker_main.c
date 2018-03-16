/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 15:08:55 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/16 13:34:07 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	main(int argc, char **argv)
{
	t_win	win;
	int		state;

	win.pa = NULL;
	win.pb = NULL;
	if (argc > 1)
	{
		if (argc == 2 || (argc == 3 && ft_strequ(argv[1], "-c")))
			state = ft_create_a_pile_arg(&win, argv);
		else
			state = ft_create_a_pile(&win, argc, argv);
		if (!state)
			ft_printf("Error\n");
		else
		{
			win.c_flag = ft_strequ(argv[1], "-c");
			if (win.c_flag)
				ft_initialize_window(&win, win.pa);
			if ((state = ft_execute_actions(&win)) == 0)
				ft_printf("KO\n");
			else
				ft_printf("%s\n",state == -1 ?  "Error" : "OK");
		}
	}
	return (0);
}
