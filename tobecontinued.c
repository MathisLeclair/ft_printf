/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tobecontinued.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 17:16:29 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/26 19:09:15 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_number(int k, int i, int bool, char **str)
{
	char	*tmp;
	int		len;

	len = ft_strlen(*str);
	if (len < i)
		tmp = malloc(i + 1);
	else
		return k;
	tmp = ft_memset(tmp, (bool == 1 ? '0' : ' '), i - len);
	tmp[i - len] = '\0';
	ft_strcat(tmp + i - len, *str);
	free(*str);
	*str = tmp;
	return (i);
}

int		ft_plus(int k, int i, int bool, char **str)
{
	char *tmp;

	i = bool;
	if (ft_isdigit((*str)[0]))
	{
		tmp = malloc(k + 2);
		tmp = ft_memset(tmp, '\0', 2);
		ft_strcat(tmp + 1, *str);
		tmp[0] = '+';
		free(*str);
		*str = tmp;
		return (k + 1);
	}
	return (k);
}

int		ft_minus(int k, int i, int bool, char **str)
{
	char *tmp;

	i = bool;
	while((*str)[i] == ' ' || (*str)[i] == '0')
		++i;
	tmp = malloc(k + 1);
	*tmp = 0;
	tmp[k] = 0;
	tmp = ft_strcat(tmp, *str + i);
	free(*str);
	*str = tmp;
	while (i--)
		(*str)[i + ft_strlen(tmp)] = ' ';
	return(k);
}

int		main()
{
	char *str;
	int d;

	d = 4;
	str = malloc(5);
	str[0] = '1';
	str[1] = '2';
	str[2] = '3';
	str[3] = '4';
	str[4] = '\0';
	d = ft_plus(d, 0, 0, &str);
	ft_putstr(str);
	ft_putstr("\n");
	d = ft_number(d, 8, 1, &str);
	ft_putstr(str);
	ft_putstr("\n");
	d = ft_number(d, 12, 0, &str);
	ft_putstr(str);
	ft_putstr("\n");
	d = ft_minus(d, 0, 0, &str);
	ft_putstr(str);
}


















