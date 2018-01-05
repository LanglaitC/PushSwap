/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:24:16 by clanglai          #+#    #+#             */
/*   Updated: 2017/11/10 16:45:09 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)dst)[0] = ((unsigned char*)src)[i];
		dst++;
		if (((const unsigned char*)src)[i] == (unsigned char)c)
			return (dst);
		i++;
	}
	return (NULL);
}
