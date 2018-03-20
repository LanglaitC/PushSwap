/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:10:30 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/29 17:47:14 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strlchr(char *str, char c)
{
	if (ft_strchr(str, c) == NULL)
		return (str);
	else
		return (ft_strlchr(ft_strchr(str, c) + 1, c));
}
