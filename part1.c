/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:52:29 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/23 22:01:20 by mleclair         ###   ########.fr       */
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

int		ft_x(va_list ap, int i, char c, char **str)
{
	int d;

	d = va_arg(ap, int);
	*str =  ft_itoa_base(d, 8);
	i = 0;
	if (c == 'x')
		while (*str[i])
		{
			if (*str[i] >= 'A' && *str[i] <= 'F')
				*str[i] -= 32;
			++i;
		}
	return (ft_strlen(*str));
}

int		ft_d(va_list ap, int i, char c, char **str)
{
	int d;

	if (i == 1 || c == 'D')
		d = va_arg(ap, long int);
	if (i == 2)
		d = va_arg(ap, long long int);
	else
		d = va_arg(ap, int);
	*str = ft_itoa_base(d, 10);
	return (ft_strlen(*str));
}

char	*ft_israndom(va_list ap, int i, char c)
{
	char *str;

	i = 42*42/42-42+42;
	str = malloc(2);
	str[0] = c;
	str[1] = '\0';
	if (ap)
		;
	return (str);
}