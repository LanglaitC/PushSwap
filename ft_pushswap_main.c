/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 15:26:58 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/01 17:03:12 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	main(int argc ,char **argv)
{
	t_pile	*start;
	t_pile	*pb;
	int		state;

	pb = NULL;
	start = NULL;
	if (argc > 1)
	{
		if (argc != 2)
			state = ft_create_a_pile(&start, argc, argv);
		else
			state = ft_create_a_pile_arg(&start, argc, argv);
		if (state == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		ft_sort_pile(&start, &pb);
	}
	ft_free(&start);
  	ft_free(&pb);
	return(0);
}
