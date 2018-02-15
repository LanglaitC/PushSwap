/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_fonc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:19:11 by clanglai          #+#    #+#             */
/*   Updated: 2018/02/14 16:36:31 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_attribute_sort(t_pile **pb, int sort)
{
	t_pile *tmp;

	tmp = *pb;
	while (tmp)
	{
		if (tmp->sort == 0)
			tmp->sort = sort;
		tmp = tmp->next;
	}
}
