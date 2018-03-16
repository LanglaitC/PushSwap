/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:30:08 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/15 16:14:42 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "stdlib.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*nelm;

	if (!(nelm = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		nelm->content = NULL;
		nelm->content_size = 0;
	}
	else
	{
		if (!(nelm->content = malloc(content_size)))
		{
			free(nelm);
			return (NULL);
		}
		ft_memcpy(nelm->content, content, content_size);
		nelm->content_size = content_size;
	}
	nelm->next = NULL;
	return (nelm);
}
