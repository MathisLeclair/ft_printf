/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 11:31:41 by mleclair          #+#    #+#             */
/*   Updated: 2016/12/07 18:57:23 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_opts2(char *tab, char *opt, char **str, int i)
{
	if (tab[5] != 0 && opt[ft_strlen(opt) - 1] != 'p')
	{
		if (opt[ft_strlen(opt) - 1] != 's' && opt[ft_strlen(opt) - 1] != 'S')
			i = ft_prec(i, ft_atoi_base_printf(opt + tab[5], 10, 0), opt[ft_strlen(opt) - 1], str);
		else
		{
			if (ft_atoi_base_printf(opt + tab[5], 10, 0) < i)
				i = ft_atoi_base_printf(opt + tab[5], 10, 0);
		}
	}
	if (tab[4])
		i = ft_number(i, ft_atoi_base_printf(opt, 10, 0),
			(tab[5] == 0 ? tab[3] : 0), str);
	if (tab[2])
		ft_minus(i, 0, tab[5] - 1, str);
	if (tab[0] == 1 && opt[ft_strlen(opt) - 1] != 'c' && ((*str)[0] != '0'
		|| (*str)[1] != 0) && (i != 0 || opt[ft_strlen(opt) - 1] != 'x'))
	{
		if (opt[ft_strlen(opt) - 1] == 'o' || opt[ft_strlen(opt) - 1] == 'O')
			i = ft_hastag(0, i, 0, str);
		else
			i = ft_hastag(0, i, 1, str);
		if (opt[ft_strlen(opt) - 1] == 'X')
			(*str)[1] = 'X';
	}
	if (tab[1] == 1 && opt[ft_strlen(opt) - 1] != 'u'
		&& opt[ft_strlen(opt) - 1] != 'o' && opt[ft_strlen(opt) - 1] != 'O')
		i = ft_plus(i, 0, tab[5], str);
	if (tab[6])
		i = ft_moncul(opt, str, i);
	return (i);
}

int		ft_opts(char *opt, char **str, int i)
{
	char	done;
	int		k;
	int		len;
	char	tab[7];

	ft_memset(tab, 0, 7);
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
		if (opt[k] == '.' && opt[len - 1] != 'c' && opt[len - 1] != 'C')
			tab[5] = k + 1;
		if (opt[k] == '0' && done == 0)
			tab[3] = 1;
		if (opt[k] == ' ')
			tab[6] = 1;
		if (tab[2] == 1)
			tab[3] = 0;
	}
	return (ft_opts2(tab, opt, str, i));
}
