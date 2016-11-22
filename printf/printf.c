/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 12:15:45 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/22 20:21:51 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#include "printf.h"

void	transfo(char *str, va_list ap)
{
	int		i;
	int		j;
	int		k;
	char	*res;
	char	*pos[2];

	pos[0] = "spdiouxc%";
	pos[1] = "SDOUXC";
	i = ft_strlen(str);
	j = 0;
	k = 0;
	while (str[j] != pos[0][j] && str[j] != pos[1][j])
		++j;
	if (i > 1 && str[j - 1] == 'l')
	{
		k = 1;
		if (i > 2 && str[j - 2] == 'l')
			k = 2;
	}
	res = ft_type()[j](ap, (pos[0][j] == str[j] ? k : k + 1), 0);
}

char 	*ft_findpara(char **str, int j, int i)
{
	char	*pos = "sSpdDioOuUxXcC%";
	char	*res;

	while (str[j] && i == 15)
	{
		i = 0;
		while (pos[i])
		{
			if ((*str)[j] == pos[i])
				break ;
			++i;
		}
		++j;
	}
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
	write(1, str, i);
	return (str + i);
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	char	*pute;
	char	*amod;

	va_start(ap, str);
	pute = troncage((char *)str);
	amod = ft_findpara(&pute, 1, 15);
	transfo(amod, ap);
	return (ft_addprint(0));
}
