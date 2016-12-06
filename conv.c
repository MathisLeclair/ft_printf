/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:49:52 by bfrochot          #+#    #+#             */
/*   Updated: 2016/12/05 21:17:39 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int		ft_count(int len)
{
	if (len < 8)
		return (0);
	else if (len < 12)
		return (1);
	else if (len < 17)
		return (2);
	else
		return (3);
}

int		plus(int i)
{
	if (i == 3)
		return (240);
	else if (i == 2)
		return (224);
	else if (i == 1)
		return (192);
	else
		return (0);
}

int		conv(int nb, char *new)
{
	char	*nbr;
	int		len;
	int		k;
	int		i;

	nbr = ft_itoa_base(nb, 2, 0);
	len = ft_strlen(nbr);
	if (len < 22)
	{
		k = 6;
		i = ft_count(len);
		while (i > 0)
		{
			new[i] = ft_atoi_base_printf(nbr + len - k, 2, 0) + 128;
			nbr[len - k] = 0;
			--i;
			k += 6;
		}
		new[0] = ft_atoi_base_printf(nbr, 2, 0) + plus(k / 6 - 1);
	}
	else
		return (-1);
	return (ft_count(len) + 1);
}