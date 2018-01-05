/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:10:55 by clanglai          #+#    #+#             */
/*   Updated: 2017/12/20 14:53:59 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/libft.h"

static int	ft_guess_power(unsigned int n, int l)
{
	__int128			i;
	int					j;

	j = 1;
	i = 1;
	while (n / (l * i) != 0)
	{
		i = i * l;
		j++;
	}
	return (j);
}

char		*ft_itoa_proper_base(unsigned int n, char *tab)
{
	int		i;
	int		power;
	char	*str;
	int		j;

	j = ft_strlen(tab);
	str = NULL;
	power = ft_guess_power(n, j);
	if (!(str = malloc(sizeof(char) * power + 1)))
		return (NULL);
	i = power - 1;
	str[power] = '\0';
	while (i >= 0)
	{
		str[i] = tab[n % j];
		n = n / j;
		i--;
	}
	return (str);
}
