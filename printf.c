/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 12:15:45 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/23 16:09:21 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#include "printf.h"

void	transfo(char *str, va_list ap, int j)
{
	int		i;
	int		k;
	char	*res;
	char	*pos[2];

	pos[0] = "sdouxcefgip";
	pos[1] = "SDOUXCEFG\0\0";
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
	res = ft_type()[j](ap, k, str[j]);
	ft_apliopt(res, str);
}

char 	*ft_findpara(char **str)
{
	char	*res;
	int		j;
	int		i;

	j = 1;
	while ((*str)[j] && (ft_isokay((*str)[j])))
		++j;
	res = malloc(j + 1);
	i = 0;
	while (i < j)
	{
		res[i] = (*str)[0];
		++i;
		++(*str);
	}
	res[i] = '\0';
	return (res);
}

char	*troncage(char *str)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (str[i] != '%' && str[i])
		i++;
	ft_print(str, i);
	return (str + i);
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	char	*pute;
	char	*amod;

	pute = ft_strdup(str);
	va_start(ap, str);
	while (pute[0])
	{
	pute = troncage(pute);
	amod = ft_findpara(&pute);
	transfo(amod, ap, 0);
	}
	return (ft_print(0, 0));
}
