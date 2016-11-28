/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 11:31:41 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/28 15:23:54 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_opts2(char *tab, char **str, int i, char *opt)
{
	int j;
	int k;
	int l;

	l = 0;
	j = 0;
	k = 0;
	if (tab[0] == 1 && tab[1] == 1)
		i = ft_number(i, ft_atoi_base_printf((tab[3] == 1
			&& tab[4] == 1 ? (opt + 1) : opt), 10, 0), 1, str);
	else if (tab[1] == 1 && tab[0] == 0)
		i = ft_number(i, ft_atoi_base_printf((tab[3] == 1
			&& tab[4] == 1 ? (opt + 1) : opt), 10, 0), 0, str);
	if (tab[4] == 1)
		i = ft_minus(i, 0, 0, str);
	while ((*str)[l])
	{
		if ((*str)[l] == '0')
			++j;
		if (ft_isdigit((*str)[l]))
			++k;
		++l;
	}
	if (tab[2] == 1 && (j != 1 || k > 1))
	{
		if (opt[ft_strlen(opt) - 1] == 'o')
			i = ft_hastag(0, i, 0, str);
		else
			i = ft_hastag(0, i, 1, str);
		if (opt[ft_strlen(opt) - 1] == 'X')
			(*str)[1] = 'X';
	}
	if (tab[3] == 1)
		i = ft_plus(i, 0, 0, str);
	return (i);
}

int		ft_opts(char *opt, char **str, int i)
{
	int		k;
	char	tab[5];

	ft_bzero(tab, 5);
	k = ft_strlen(opt);
	while (k >= 0)
	{
		while (k > -1 && ft_isdigit(opt[k]))
		{
			if (opt[k] == '0')
				if (k == 0 || !(ft_isdigit(opt[k - 1])))
					tab[0] = 1;
			tab[1] = 1;
			--k;
		}
		if (opt[k] == '#')
			tab[2] = 1;
		if (opt[k] == '+')
			tab[3] = 1;
		if (opt[k] == '-')
			tab[4] = 1;
		--k;
	}
	return (ft_opts2(tab, str, i, opt));
}
