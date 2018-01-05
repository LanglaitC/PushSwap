/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:15:29 by clanglai          #+#    #+#             */
/*   Updated: 2017/11/10 16:48:30 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	int		j;

	if (src == dst)
		return (dst);
	if (((unsigned long)src + len) >= (unsigned long)dst && src < dst)
	{
		j = len - 1;
		while (j >= 0)
		{
			((unsigned char*)dst)[j] = ((const unsigned char*)src)[j];
			j--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((unsigned char*)dst)[i] = ((const unsigned char*)src)[i];
			i++;
		}
	}
	return (dst);
}
