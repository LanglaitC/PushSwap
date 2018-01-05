/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:56:13 by clanglai          #+#    #+#             */
/*   Updated: 2017/12/20 16:55:55 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_isflag(char c)
{
	if (c == ' ')
		return (1);
	if (c == '+')
		return (2);
	if (c == '-')
		return (3);
	if (c == '0')
		return (4);
	if (c == '#')
		return (5);
	return (0);
}

int	ft_islength(char c)
{
	if (c == 'h')
		return (1);
	if (c == 'l')
		return (2);
	if (c == 'j')
		return (3);
	if (c == 'z')
		return (4);
	return (0);
}

int	ft_isvalid(char c)
{
	if (ft_isdigit(c) || c == '.')
		return (1);
	else if (ft_isflag(c))
		return (2);
	else if (ft_islength(c))
		return (3);
	else if (c == 'd' || c == 'i' || c == 'D')
		return (4);
	else if (c == 'u' || c == 'o' || c == 'x' || c == 'X' || c == 'U'
			|| c == 'O')
		return (5);
	else if (c == 'c' || c == 'C')
		return (6);
	else if (c == 's' || c == 'S')
		return (7);
	else if (c == 'p')
		return (8);
	else if (c == '%')
		return (9);
	return (0);
}
