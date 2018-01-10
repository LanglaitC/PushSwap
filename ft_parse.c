/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:22:17 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/10 09:51:26 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	ft_check_double_input(t_pile **pile, int number)
{
	t_pile *tmp;

	tmp = *pile;
	while (tmp->next)
	{
		if (tmp->content == number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
