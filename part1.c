/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:52:29 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/24 11:36:37 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_s(va_list ap, int i, char c, char **str)
{
	wchar_t *T;

	if (c == 'S' || i == 1)
	{
		i = 0;
		T = va_arg(ap, wchar_t *);
		while (T[i])
			++i;
		*str = (char *)T;
		return (4 * i);
	}
	*str = va_arg(ap, char *);
	return (ft_strlen(*str));
}

int		ft_c(va_list ap, int i, char c, char **str)
{
	wchar_t T;

	if (c == 'S' || i == 1)
	{
		i = 0;
		T = va_arg(ap, wchar_t);
		*str = (char *)&T;
		return (4);
	}
	*str[0] = va_arg(ap, int);
	*str[1] = '\0';
	return (1);
}

int		ft_o(va_list ap, int i, char c, char **str)
{
	int d;

	if (i == 1 || c == 'O')
		d = va_arg(ap, long int);
	else
		d = va_arg(ap, int);
	*str = ft_itoa_base(d, 8);
	return (ft_strlen(*str));
}

int		ft_u(va_list ap, int i, char c, char **str)
{
	int d;

	if (i == 1 || c == 'D')
		d = va_arg(ap, unsigned long int);
	if (i == 2)
		d = va_arg(ap, unsigned long long int);
	else
		d = va_arg(ap, unsigned int);
	*str = ft_itoa_base(d, 10);
	return (ft_strlen(*str));
}

int		ft_e(va_list ap, int i, char c, char **str)
{
	int d;
	int bool;
	char tmp[14];

	bool = '0';
	d = va_arg(ap, int);
	if (d < 0)
		c = '1';
	i = 0;
	while (tmp[i])
		tmp[i] = 0;
	if (bool == 1)
		tmp[bool - 1] = '-';
	tmp[bool] = ft_itoa_base(d, 10)[1];
	tmp[bool + 1] = '.';
	i = 1;
	while (i < 7)
		tmp[bool + 1 + i] = ft_itoa_base(d, 10)[i + 1];
	tmp[bool + 8] = 'e';
	tmp[bool + 9] = '+';
	tmp[bool + 10] = ft_itoa_base(ft_strlen(ft_itoa_base(d, 10)),10)[0];
	tmp[bool + 11] = ft_itoa_base(ft_strlen(ft_itoa_base(d, 10)),10)[1];
	ft_strncpy(*str, tmp, 13);
	return (12);
}
