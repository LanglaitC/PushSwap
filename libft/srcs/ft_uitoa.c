/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:10:55 by clanglai          #+#    #+#             */
/*   Updated: 2017/12/14 15:15:31 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_guess_power(unsigned int n)
{
	unsigned long int	i;
	int					j;

	j = 1;
	i = 1;
	while (n / (10 * i) != 0)
	{
		i = i * 10;
		j++;
	}
	return (j);
}

char		*ft_uitoa(unsigned int n)
{
	int		i;
	int		power;
	char	*str;

	str = NULL;
	power = ft_guess_power(n);
	if (!(str = malloc(sizeof(char) * power + 1)))
		return (NULL);
	i = power - 1;
	str[power] = '\0';
	while (i >= 0)
	{
		str[i] = (n % 10 + '0');
		n = n / 10;
		i--;
	}
	return (str);
}
