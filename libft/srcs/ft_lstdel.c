/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:09:23 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/10 12:08:28 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;
	t_list	*tmp_next;

	if (alst && del)
	{
		tmp = *alst;
		if (tmp)
		{
			while (tmp->next)
			{
				tmp_next = tmp->next;
				ft_lstdelone(&tmp, del);
				tmp = tmp_next;
			}
		}
		ft_lstdelone(&tmp, del);
		*alst = NULL;
	}
}
