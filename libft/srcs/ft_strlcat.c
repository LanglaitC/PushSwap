/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:13:24 by clanglai          #+#    #+#             */
/*   Updated: 2017/11/09 14:16:22 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static	int	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	ft_check_bullshit(char *dst, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (dst[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;
	int		init;

	init = ft_strlen(dst);
	j = 0;
	i = ft_strlen(dst);
	if (ft_check_bullshit(dst, size))
		return (ft_strlen(src) + size);
	while (i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (init + ft_strlen(src));
}
