/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 08:46:13 by clanglai          #+#    #+#             */
/*   Updated: 2017/11/28 15:25:01 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		j;

	i = start;
	j = 0;
	if (!s)
	{
		str = NULL;
		return (str);
	}
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len + start)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
