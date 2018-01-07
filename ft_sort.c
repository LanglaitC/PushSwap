/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 14:41:20 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/07 15:04:14 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	ft_find_max(t_pile **pa)
{
	t_pile *tmp;
	int highest;

	tmp = *pa;
	highest = tmp->content;
	while(tmp->next)
	{
		if (highest < tmp->content)
			highest = tmp->content;
		tmp = tmp->next;	
	}
	if (highest < tmp->content)
		highest = tmp->content;
	return (highest);
}
