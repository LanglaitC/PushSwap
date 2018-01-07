/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 15:08:55 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/07 16:04:01 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int main(int argc, char **argv)
{
	t_pile *start;
	int	state;

	state = 0;
	start = NULL;
	if (argc > 1)
	{
		if (!ft_create_a_pile(&start, argc, argv))
		{
			ft_printf("Error\n");
			return (0);
		}
		if ((state = ft_execute_actions(&start, argc, argv)) == 0)
			ft_printf("KO\n");
		else if (state == 1)
			ft_printf("OK\n");
		else if (state == -1)
			ft_printf("Error\n");
	}
	return (0);
}
