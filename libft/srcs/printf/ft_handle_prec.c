/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:42:34 by clanglai          #+#    #+#             */
/*   Updated: 2018/01/05 12:25:45 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

char	*ft_handle_prec_int(t_config *config, char *str, int len)
{
	char *zeros;
	char *tmp;

	len = (str && config->flag[4] == 1 && len != 2 &&
			(config->spec == 'x' || config->spec == 'X')) ? ft_lenx(str) : len;
	config->flag[3] = 0;
	if (ft_issign(str[0]))
		len--;
	if (config->prec == 0 && config->flag[4] == 1 && (config->spec == 'o' ||
				config->spec == 'O') && str[1] == '\0')
		return (ft_strnew_fill(1, '0'));
	if (config->prec == 0 && ((ft_isvalid(config->spec)
					!= 4 && ft_isvalid(config->spec) != 5) || (str[0] == '0' &&
					str[1] == '\0')))
		return (ft_strnew(1));
	if (len > config->prec || config->prec == 1)
		return (str);
	if (!(zeros = ft_strnew_fill(config->prec - len + 1, '0')))
		return (NULL);
	if (!(tmp = ft_strjoin(zeros, str)))
		return (NULL);
	ft_memdel((void**)&zeros);
	ft_memdel((void**)&str);
	return (tmp);
}

char	*ft_handle_prec_adr(t_config *config, char *s, int len)
{
	char *zeros;
	char *tmp;

	(void)len;
	config->flag[3] = 0;
	if (config->prec == 0 && s[2] == '0' && s[3] == '\0')
		if (!(tmp = ft_strdup("0x")))
			return (NULL);
	if (config->prec == 0 && s[2] != '0' && s[3] != '\0')
		return (s);
	if (config->prec > 0)
		if (config->prec + 2 <= (int)ft_strlen(s))
			if (!(tmp = ft_strdup(s)))
				return (NULL);
	if (config->prec + 2 > (int)ft_strlen(s))
	{
		if (!(zeros = ft_strnew_fill(config->prec + 2 - ft_strlen(s), '0')))
			return (NULL);
		if (config->flag[2] == 0 || config->flag[2] == 1)
			if (!(tmp = ft_strjoin(zeros, s)))
				return (NULL);
		ft_memdel((void**)&zeros);
	}
	ft_memdel((void**)&s);
	return (tmp);
}
