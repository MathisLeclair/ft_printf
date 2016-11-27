/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 12:15:45 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/27 19:30:53 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	transfo(char *str, va_list ap, int j, char **machin)
{
	int		i;
	int		k;
	char	*pos[2];

	pos[0] = "sdouxcip";
	pos[1] = "SDOUXC\0\0";
	i = ft_strlen(str);
	k = 0;
	while (str[i - 1] != pos[0][j] && str[i - 1] != pos[1][j] && pos[0][j])
		++j;
	if (i > 2 && str[i - 2] == 'l')
	{
		k = 1;
		if (i > 3 && str[i - 3] == 'l')
			k = 2;
	}
	else if (i > 2 && str[i - 2] == 'h')
	{
		k = -1;
		if (i > 3 && str[i - 3] == 'h')
			k = -2;
	}
	i = ft_type()[j](ap, k, str[i - 1], machin);
	i = ft_opts(str, machin, i);
	ft_print(*machin, i, 0);
}

char	*ft_findpara(char **str)
{
	char	*res;
	int		j;
	int		i;

	(*str) += 1;
	j = 0;
	while ((*str)[j] && (ft_isokay((*str)[j])))
		++j;
	if ((*str)[j])
		j++;
	res = malloc(j + 1);
	i = 0;
	while (i < j)
	{
		res[i] = *(*str);
		++i;
		++(*str);
	}
	res[i] = '\0';
	return (res);
}

char	*troncage(char *str)
{
	int i;

	i = 0;
	while (str[i] != '%' && str[i])
		i++;
	ft_print(str, i, 0);
	return (str + i);
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	char	*str4;
	char	*amod;
	char	*machin;
	int		temp;

	machin = NULL;
	str4 = ft_strdup(str);
	va_start(ap, str);
	while (str4[0])
	{
		str4 = troncage(str4);
		if (str4[0] == 0)
			break ;
		amod = ft_findpara(&str4);
		if (*amod != 0)
			transfo(amod, ap, 0, &machin);
	}
	temp = ft_print(0, 0, 1);
	return (temp);
}
