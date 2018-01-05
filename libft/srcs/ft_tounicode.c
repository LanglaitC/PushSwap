/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tounicode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:04:18 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/05 12:21:02 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_unicode_2(wchar_t c, int i)
{
	unsigned char	d;

	if (i >= 2 || i < 0)
	{
		d = (c >> 6 | 0xC0);
		write(1, &d, 1);
		d = (c & 0x3F) | 0x80;
		write(1, &d, 1);
	}
	return ((i >= 2 || i < 0) ? 2 : 0);
}

static int	ft_unicode_3(wchar_t c, int i)
{
	unsigned char	d;

	if (i >= 3 || i < 0)
	{
		d = (c >> 12 | 0xE0);
		write(1, &d, 1);
		d = (c >> 6 & 0x3F) | 0x80;
		write(1, &d, 1);
		d = (c & 0x3F) | 0x80;
		write(1, &d, 1);
	}
	return ((i >= 3 || i < 0) ? 3 : 0);
}

static int	ft_unicode_4(wchar_t c, int i)
{
	unsigned char d;

	if (i >= 4 || i < 0)
	{
		d = (c >> 18 | 0xF0);
		write(1, &d, 1);
		d = (c >> 12 & 0x3F) | 0x80;
		write(1, &d, 1);
		d = (c >> 6 & 0x3F) | 0x80;
		write(1, &d, 1);
		d = (c & 0x3F) | 0x80;
		write(1, &d, 1);
	}
	return ((i >= 4 || i < 0) ? 4 : 0);
}

int			ft_tounicode(wchar_t c, int i)
{
	if (c > -1 && c < 128 && (i >= 1 || i < 0))
	{
		write(1, &c, 1);
		return (1);
	}
	else if (c < 2048)
		return (ft_unicode_2(c, i));
	else if (c < 65536 && (c < 56320 || c > 57343))
		return (ft_unicode_3(c, i));
	else if (c < 1114111)
		return (ft_unicode_4(c, i));
	return (-1);
}

int			ft_unicode_value(wint_t c)
{
	if (c < 128)
		return (1);
	else if (c < 2048)
		return (2);
	else if (c < 65536 && (c < 56320 || c > 57343))
		return (3);
	else if (c < 1114111)
		return (4);
	return (-1);
}
