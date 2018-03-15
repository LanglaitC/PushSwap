/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanglai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:11:03 by clanglai          #+#    #+#             */
/*   Updated: 2018/03/15 12:49:10 by clanglai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int len)
{
	int	i;
	int	k;
	int	tmp;

	i = 0;
	while (i < len)
	{
		k = i + 1;
		while (k < len)
		{
			if (tab[i] > tab[k])
			{
				tmp = tab[i];
				tab[i] = tab[k];
				tab[k] = tmp;
			}
			k++;
		}
		i++;
	}
}
