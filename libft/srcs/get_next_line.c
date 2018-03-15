/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:36:30 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/15 12:31:46 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static	int	ft_concat_to_line(char **tmp, char **line, char **buff)
{
	if (!(*tmp = ft_strjoin(*line, *buff)))
		return (0);
	free(*line);
	if (!(*line = ft_strdup(*tmp)))
		return (0);
	free(*tmp);
	ft_strclr(*buff);
	return (1);
}

static	int	ft_readfile(const int fd, char **line, char **save, int state)
{
	int		ret;
	char	*tmp;
	char	*buff;

	buff = ft_strnew(BUFF_SIZE);
	while (state == 1)
		if ((ret = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[ret] = '\0';
			if (ft_strchr(buff, '\n'))
			{
				*save = ft_strcpy(*save, ft_strchr(buff, '\n') + 1);
				state = 2;
				buff[ret - ft_strlen(ft_strchr(buff, '\n'))] = '\0';
			}
			if (!(ft_concat_to_line(&tmp, line, &buff)))
				return (-1);
		}
		else if (ret == 0)
			state = 0;
		else
			return (-1);
	free(buff);
	return (state);
}

int			get_line(const int fd, char **line, int ret)
{
	static char	*save;

	if (!save)
		save = ft_strnew(BUFF_SIZE);
	if (ft_strchr(save, '\n') != NULL)
	{
		*line = ft_strsub(save, 0, ft_strlen(save) -
				ft_strlen(ft_strchr(save, '\n')));
		save = ft_strcpy(save, ft_strchr(save, '\n') + 1);
		ret = 1;
	}
	else
	{
		*line = ft_strdup(save);
		ft_strclr(save);
	}
	if (ft_strlen(save) == 0 && ret != 1)
		if ((ret = ft_readfile(fd, line, &save, 1)) == -1)
			return (-1);
	if ((ft_strlen(*line)) == 0 && ret == 0)
		return (0);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	if (fd < 0 || !line)
		return (-1);
	return (get_line(fd, line, 0));
}
