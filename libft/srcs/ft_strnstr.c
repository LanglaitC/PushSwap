/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:43:29 by clanglai          #+#    #+#             */
/*   Updated: 2017/11/09 14:38:26 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	i = 0;
	while (*haystack && j < len)
	{
		if (haystack[i] == needle[i])
		{
			while (haystack[i] == needle[i] || needle[i] == '\0')
			{
				if (i + j > len)
					return (NULL);
				if (needle[i] == '\0')
					return ((char*)haystack);
				i++;
			}
			i = 0;
		}
		haystack++;
		j++;
	}
	return (NULL);
}
