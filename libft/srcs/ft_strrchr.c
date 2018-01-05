/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:14:46 by clanglai          #+#    #+#             */
/*   Updated: 2017/11/09 14:38:55 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int	ft_get_count(const char *s, int c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

char		*ft_strrchr(const char *s, int c)
{
	int i;
	int count;
	int second_count;

	i = 0;
	count = ft_get_count(s, c);
	second_count = 1;
	while (*s)
	{
		if (*s == c)
		{
			if (second_count == count)
				return ((char*)s);
			second_count++;
		}
		s++;
	}
	if (*s == c)
		return ((char*)s);
	return (NULL);
}
