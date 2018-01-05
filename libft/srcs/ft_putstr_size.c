/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:26:43 by clanglai          #+#    #+#             */
/*   Updated: 2017/12/19 14:05:18 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../inc/libft.h"

int	ft_putstr_size(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	ft_memdel((void**)&s);
	return (i);
}
