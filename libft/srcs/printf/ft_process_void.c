/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_void.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 10:28:17 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/05 10:45:45 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_process_void(t_config *config, va_list *args)
{
	char *res;
	char *tmp;

	if (!(res = ft_putadress(va_arg(*args, void*), "0123456789abcdef")))
		return (-1);
	if (!(tmp = ft_handle_flag(config, res)))
		return (-1);
	return (ft_putstr_size(tmp));
}

int	ft_process_percent(t_config *config)
{
	char *str;
	char *tmp;

	if (!(str = ft_strdup("%")))
		return (-1);
	if (!(tmp = ft_handle_flag(config, str)))
		return (-1);
	return (ft_putstr_size(tmp));
}

int	ft_process_invalid(const char *str, int *i, char c)
{
	t_config	*config;
	char		*spaces;

	if (!(config = ft_getstruct(str, *i)))
		return (-1);
	if (config->width > 1 && (c = config->flag[3] == 1 ? '0' : ' '))
		if (!(spaces = ft_strnew_fill(config->width - 1, c)))
			return (-1);
	if (config->width < 2)
		if (!(spaces = ft_strnew(1)))
			return (-1);
	if (config->flag[2] == 1)
	{
		ft_putchar_print(str[*i]);
		ft_putstr(spaces);
	}
	if (config->flag[2] == 0)
	{
		ft_putstr(spaces);
		ft_putchar_print(str[*i]);
	}
	*i = (str[*i] == '\0') ? *i : *i + 1;
	ft_delconfig(config);
	free(spaces);
	return (ft_strlen(spaces) - (config->size - 1));
}
