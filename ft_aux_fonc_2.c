/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_fonc_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:21:13 by clanglai          #+#    #+#             */
/*   Updated: 2018/02/28 16:52:14 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_print_state(t_pile **pa, t_pile **pb)
{
	t_pile *tmp;

	printf("\n-----------------------------------------------------------------------\n\n");
	tmp = *pa;
	if (tmp)
	{
		printf("	Pile a = ");
		while(tmp->next)
		{
			printf("[%d %d] ", tmp->content, tmp->sort);
			tmp = tmp->next;
		}
		printf("[%d %d]", tmp->content, tmp->sort);
		printf("\n\n");
	}
	tmp = *pb;
	if (tmp)
	{
		printf("	Pile b = ");
		while(tmp->next)
		{
			printf("[%d %d] ", tmp->content, tmp->sort);
			tmp = tmp->next;
		}
		printf("[%d %d]", tmp->content, tmp->sort);
		printf("\n\n");
	}
	printf("-----------------------------------------------------------------------\n\n");
}
