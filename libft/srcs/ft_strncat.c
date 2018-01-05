/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:39:00 by clanglai          #+#    #+#             */
/*   Updated: 2017/11/09 14:37:15 by clanglai         ###   ########.fr       */
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

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	j;

	i = ft_strlen(s1);
	j = 0;
	while (s2[j] != '\0' && j < n)
	{
		s1[i] = s2[j];
		j++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
