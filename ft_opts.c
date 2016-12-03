/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 11:31:41 by mleclair          #+#    #+#             */
/*   Updated: 2016/12/01 15:55:43 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_opts2(char *tab, char *opt, char **str, int i)
{
	if (tab[5] != 0)
	{
		if (opt[ft_strlen(opt) - 1] != 's')
			i = ft_number(i, ft_atoi_base_printf(opt + tab[5], 10, 0), 1, str);
		else
		{
			if (ft_atoi_base_printf(opt + tab[5] + 1, 10, 0) < i)
			{
				(*str)[ft_atoi_base_printf(opt + tab[5], 10, 0)] = 0;
				i = ft_strlen(*str);
			}
		}
	}
	if (tab[4] == 1)
		i = ft_number(i, ft_atoi_base_printf(opt, 10, 0), (tab[5] == 0 ? tab[3] : 0), str);
	if (tab[2] == 1)
		ft_minus(i, 0, tab[5] - 1, str);
	if (tab[0] == 1 && ((*str)[0] != '0' || (*str)[1] != 0))
	{
		if(opt[ft_strlen(opt) - 1] == 'o')
			i = ft_hastag(0, i, 0, str);
		else
			i = ft_hastag(0, i, 1, str);
		if (opt[ft_strlen(opt) - 1] == 'X')
			(*str)[1] = 'X';
	}
	if (tab[1] == 1 && opt[ft_strlen(opt) - 1] != 'u')
		i = ft_plus(i, 0, tab[5], str);
	return (i);
}

int		ft_opts(char *opt, char **str, int i)
{
	char	done;
	int		k;
	int		len;
	char	tab[6];

	ft_memset(tab, 0, 6);
	len = ft_strlen(opt);
	done = 0;
	k = -1;
	while (++k < len)
	{
		if (opt[k] == '#')
			tab[0] = 1;
		if (opt[k] == '+')
			tab[1] = 1;
		if (opt[k] == '-')
			tab[2] = 1;
		if (ft_isdigit(opt[k]))
			if (opt[k] != '0' && (done = 1) && tab[5] == 0)
				tab[4] = 1;
		if (opt[k] == '.')
			tab[5] = k + 1;
		if (opt[k] == '0' && done == 0)
			tab[3] = 1;
	}
	return (ft_opts2(tab, opt, str, i));
}
