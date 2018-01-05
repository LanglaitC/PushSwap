/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:47:04 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/05 10:45:18 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <unistd.h>

int		ft_guess_size(uint64_t adr, int *i)
{
	__int128	j;
	int			k;

	j = 1;
	k = 1;
	while (adr / (j * 16) != 0)
	{
		j = j * 16;
		k++;
	}
	*i = (k - 1) * 4;
	return (k);
}

char	*ft_putadress(void *ptr, char *str)
{
	char		*res;
	uint64_t	adr;
	int			i;
	int			j;

	if (ptr == NULL)
		res = ft_strdup("0x0");
	else
	{
		adr = (uint64_t)ptr;
		if (!(res = ft_strnew(ft_guess_size(adr, &i))))
			return (NULL);
		j = 2;
		res[0] = '0';
		res[1] = 'x';
		while (i >= 0)
		{
			res[j] = str[(adr >> i) & 0xF];
			i -= 4;
			j++;
		}
		res[j] = '\0';
	}
	return (res);
}
