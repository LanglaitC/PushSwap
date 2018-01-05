/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:53:41 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/05 11:12:57 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static int	*ft_flagtable(const char *s, int i)
{
	int j;
	int *table;
	int c;

	if (!(table = (int*)malloc(sizeof(int) * 6)))
		return (NULL);
	j = 0;
	while (j < 5)
	{
		table[j] = 0;
		j++;
	}
	table[j] = -1;
	while (s[--i] != '%')
		if ((c = ft_isflag(s[i])))
		{
			if (c == 4)
			{
				if (ft_isdigit(s[i - 1]) == 0 && s[i - 1] != '-')
					table[c - 1] = 1;
			}
			else
				table[c - 1] = 1;
		}
	return (table);
}

static int	ft_getprec(const char *s, int i, int res)
{
	int j;
	int state;

	state = 0;
	j = i;
	while (s[j] != '%')
		j--;
	j++;
	while (j < i)
	{
		if (s[j] == '.' && state != 1)
			state = 1;
		else if (state == 1 && ft_isdigit(s[j]) == 1)
			res = res * 10 + s[j] - '0';
		else if (state == 1 && s[j] == '.')
			res = 0;
		else if (state == 1)
			return (res);
		else
			state = 0;
		j++;
	}
	if (state == 1)
		return (res);
	return (-1);
}

static int	ft_getwidth(const char *s, int i, int tmp, int res)
{
	int j;
	int state;

	state = 1;
	j = i - 1;
	while (s[j] != '%')
		j--;
	while (j <= i)
	{
		if (state == 1 && ft_isdigit(s[j]) == 1 && (s[j] != '0' || res != 0))
			res = res * 10 + s[j] - '0';
		else if (state == 1 && ft_isdigit(s[j]) != 1 && res != 0)
		{
			tmp = res;
			res = 0;
			state = (s[j] == '.') ? 0 : 1;
		}
		else if (s[j] == '.')
			state = 0;
		else if (ft_isdigit(s[j]) == 0 && state == 0)
			state = 1;
		j++;
	}
	return ((tmp != res && res != 0) ? res : tmp);
}

static int	ft_getlength(const char *s, int i, int e, int c)
{
	int j;

	j = i;
	while (s[j] != '%')
		j--;
	while (++j < i + 1)
		if (((c = ft_islength(s[j])) || ft_isvalid(s[j])))
		{
			if (c == 1 && e != 1)
				e = (!e || e == 5) ? 1 : e;
			else if (c == 2 && e != 2)
				e = (!e || (e == 5 || e == 1 || e == 4)) ? 2 : e;
			else if (c == 3)
				e = 3;
			else if (c == 4)
				e = (!e || (e == 5 || e == 1)) ? 4 : e;
			else if (c == 1 && e == 1)
				e = (e == 0 || e == 1) ? 5 : e;
			else if (c == 2 && e == 2)
				e = (e < 6 && e != 3) ? 6 : e;
		}
	return (e);
}

t_config	*ft_getstruct(const char *s, int i)
{
	t_config	*config;
	int			j;

	j = 0;
	if (!(config = (t_config*)malloc(sizeof(t_config) * 1)))
		return (NULL);
	config->flag = ft_flagtable(s, i);
	if (config->flag[2] == 1)
		config->flag[3] = 0;
	config->prec = ft_getprec(s, i, 0);
	config->width = ft_getwidth(s, i, 0, 0);
	config->len = ft_getlength(s, i, 0, 0);
	config->spec = s[i];
	i--;
	while (s[i - j] != '%')
		j++;
	config->size = j + 2;
	return (config);
}
