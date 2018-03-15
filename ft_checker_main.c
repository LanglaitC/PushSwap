/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 15:08:55 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/15 15:31:49 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	main(int argc, char **argv)
{
	t_pile	*start;
	int		state;
	t_pile	*pb;

	pb = NULL;
	start = NULL;
	if (argc > 1)
	{
		if (argc == 2)
			state = ft_create_a_pile_arg(&start, argv);
		else
			state = ft_create_a_pile(&start, argc, argv);
		if (!state)
		{
			ft_printf("Error\n");
			return (0);
		}
		if ((state = ft_execute_actions(&start, &pb)) == 0)
			ft_printf("KO\n");
		else if (state == 1)
			ft_printf("OK\n");
		else if (state == -1)
			ft_printf("Error\n");
	}
	return (0);
}
