/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:43:29 by clanglai          #+#    #+#             */
/*   Updated: 2017/11/09 14:39:28 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;

	if (*needle == '\0')
		return ((char*)haystack);
	i = 0;
	while (*haystack)
	{
		if (haystack[i] == needle[i])
		{
			while (haystack[i] == needle[i] || needle[i] == '\0')
			{
				if (needle[i] == '\0')
					return ((char*)haystack);
				i++;
			}
			i = 0;
		}
		haystack++;
	}
	return (NULL);
}
