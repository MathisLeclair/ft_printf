/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 12:15:45 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/30 16:54:57 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_findmod(int i, char *str, int k)
{
	if (i > 1 && str[i - 2] == 'l')
	{
		k = 1;
		if (i > 2 && str[i - 3] == 'l')
			k = 2;
	}
	else if (i > 1 && str[i - 2] == 'h')
	{
		k = -1;
		if (i > 2 && str[i - 3] == 'h')
			k = -2;
	}
	else if(i > 1 && str[i - 2] == 'j')
		k = 5;
	else if (i > 1 && str[i - 2] == 'z')
		k = 6;
	return (k);
}

int		transfo(char *str, va_list ap, int j, char **machin)
{
	int		i;
	int		k;
	char	*pos[2];

	pos[0] = "sdouxcip";
	pos[1] = "SDOUXC\0\0";
	i = ft_strlen(str);
	while (str[i - 1] != pos[0][j] && str[i - 1] != pos[1][j] && pos[0][j])
		++j;
	k = ft_findmod(i, str, 0);
	i = ft_type()[j](ap, k, str[i - 1], machin);
	if (i == -1)
		return (-1);
	i = ft_opts(str, machin, i);
	ft_print(*machin, i, 0);
	return (0);
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
	int		i;

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
			i = transfo(amod, ap, 0, &machin);
	}
	if (i == -1)
		return (-1);
	temp = ft_print(0, 0, 1);
	return (temp);
}
