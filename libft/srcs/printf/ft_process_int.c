/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:45:24 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/05 12:30:32 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_int(t_config *config, int number)
{
	char	*str;

	if (!(str = ft_itoa(number)))
		return (-1);
	if (!str)
		return (0);
	if (!(str = ft_handle_flag(config, str)))
		return (-1);
	return (ft_putstr_size(str));
}

int	ft_short_int(t_config *config, int number)
{
	char		*str;
	short int	nbr;

	nbr = number;
	if (!(str = ft_itoa(nbr)))
		return (-1);
	if (!str)
		return (0);
	if (!(str = ft_handle_flag(config, str)))
		return (-1);
	return (ft_putstr_size(str));
}

int	ft_long(t_config *config, long int number)
{
	char	*str;

	if (!(str = ft_itoa_long(number)))
		return (-1);
	if (!str)
		return (0);
	if (!(str = ft_handle_flag(config, str)))
		return (-1);
	return (ft_putstr_size(str));
}

int	ft_long_long(t_config *config, long long int number)
{
	char	*str;

	if (!(str = ft_itoa_long_long(number)))
		return (-1);
	if (!str)
		return (0);
	if (!(str = ft_handle_flag(config, str)))
		return (-1);
	return (ft_putstr_size(str));
}
