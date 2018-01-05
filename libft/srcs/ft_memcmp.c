/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:29:21 by clanglai          #+#    #+#             */
/*   Updated: 2017/11/10 13:02:20 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				res;

	i = 0;
	while (i < n)
	{
		if (((unsigned const char*)s1)[i] != ((unsigned const char*)s2)[i])
		{
			res = ((unsigned const char*)s1)[i] - ((unsigned const char*)s2)[i];
			return (res);
		}
		i++;
	}
	return (0);
}
