/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:36:08 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/28 18:22:39 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_x(va_list ap, int i, char c, char **str)
{
	unsigned long long int d;

	d = 0;
	if (i == 1)
		d = va_arg(ap, unsigned long);
	else if (i == 2)
		d = va_arg(ap, unsigned long long);
	else if (i == 5)
		d = va_arg(ap, uintmax_t);
	else if (i == 6)
		d = va_arg(ap, size_t);
	else
		d = va_arg(ap, unsigned int);
	if (i == -1)
		d = (unsigned short)d;
	if (i == -2)
		d = (unsigned char)d;
	*str = ft_itoa_base((d > 0 ? d : -d), 16, (d > 0 ? 0 : 1));
	i = 0;
	if (c == 'x')
	{
		while ((*str)[i])
		{
			if ((*str)[i] >= 'A' && (*str)[i] <= 'F')
				(*str)[i] += 32;
			++i;
		}
	}
	return (ft_strlen(*str));
}

int		ft_i(va_list ap, int i, char c, char **str)
{
	return (ft_d(ap, i, c, str));
}

int		ft_d(va_list ap, int i, char c, char **str)
{
	long long int	d;
	char			*tmp;

	if (i == 1 || c == 'D')
		d = va_arg(ap, long int);
	else if (i == 2)
		d = va_arg(ap, long long int);
	else
		d = va_arg(ap, int);
	if (i == -1)
		d = (short)d;
	if (i == -2)
		d = (signed char)d;
	tmp = ft_itoa_base((d > 0 ? d : -d), 10, (d > 0 ? 0 : 1));
	*str = malloc(ft_strlen(tmp));
	**str = 0;
	ft_strcat(*str, tmp);
	free(tmp);
	return (ft_strlen(*str));
}

int		ft_p(va_list ap, int i, char c, char **str)
{
	return (ft_x(ap, i, c, str));
}

int		ft_israndom(va_list ap, int i, char c, char **str)
{
	i = 42 * 42 / 42 - 42 + 42;
	*str = malloc(2);
	(*str)[0] = c;
	(*str)[1] = '\0';
	if (ap)
		;
	return (ft_strlen(*str));
}
