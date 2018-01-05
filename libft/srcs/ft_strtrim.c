/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:38:43 by clanglai          #+#    #+#             */
/*   Updated: 2017/11/10 14:16:51 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_ispace(char const c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\f' || c == '\v')
		return (1);
	if (c == '\r')
		return (1);
	return (0);
}

static int	ft_count_blank(char const *s)
{
	int i;
	int space;
	int state;

	state = 1;
	i = 0;
	space = 0;
	while (s[i])
	{
		if (ft_ispace(s[i]) == 1 && state == 1)
			space++;
		else
			state = 0;
		i++;
	}
	return (space);
}

static int	ft_count_reverse_blank(char const *s)
{
	int i;
	int space;
	int state;

	i = 0;
	while (s[i])
		i++;
	i--;
	state = 1;
	space = 0;
	while (i >= 0)
	{
		if (ft_ispace(s[i]) && state == 1)
			space++;
		else
			state = 0;
		i--;
	}
	if (state == 1)
		return (0);
	return (space);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;
	int		len;

	if (!s)
		return (NULL);
	j = ft_count_reverse_blank(s) + ft_count_blank(s);
	i = 0;
	len = 0;
	while (s[len])
		len++;
	if (!(str = (char*)malloc(sizeof(char) * (len - j) + 1)))
		return (NULL);
	i = ft_count_blank(s);
	j = 0;
	len = len - ft_count_reverse_blank(s);
	while (i < len)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
