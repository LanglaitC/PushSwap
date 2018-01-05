/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:18:17 by clanglai          #+#    #+#             */
/*   Updated: 2017/12/14 14:13:21 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlengh(const char *s1)
{
	int i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		sum;
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	sum = ft_strlengh(s1) + ft_strlengh(s2);
	if (!(str = (char*)malloc(sizeof(char) * sum + 1)))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
