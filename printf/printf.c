/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 12:15:45 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/22 14:09:54 by mleclair         ###   ########.fr       */
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
	char	*res;
	void 	(**format);
	char	*pos = "sSpdDioOuUxXcC%";

	format = ft_type();
	i = ft_strlen(str);
	j = 0;
	while (str[j] != pos[j])
		++j;
	res = format[j](ap, 0, 0);
	
}

char 	*ft_findpara(char **str)
{
	int		i;
	int		j;
	char	*pos = "sSpdDioOuUxXcC%";
	char	*res;

	j = 0;
	i = 14;
	while (str[j] && i == 14 && (*str)[j] != '%')
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
	while ((*str)[0] != pos[i])
	{
		res[i] = (*str)[0];
		++i;
		++(*str);
	}
	res[i] = '\0';
	*str = *str + j;
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
	amod = ft_findpara(&pute);
	transfo(amod, ap);
	return (ft_addprint(0));
}

// int main(void)
// {
// 	int d = 0;
// 	d = printf("%ld\n", -25);
// 	printf("%d\n",d );
// }