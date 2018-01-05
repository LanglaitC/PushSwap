/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:34:41 by clanglai          #+#    #+#             */
/*   Updated: 2017/11/11 16:59:17 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	if (!(first = malloc(sizeof(t_list))))
		return (NULL);
	first = f(lst);
	tmp = first;
	while (lst->next)
	{
		first->next = f(lst->next);
		first = first->next;
		lst = lst->next;
	}
	first->next = NULL;
	return (tmp);
}
