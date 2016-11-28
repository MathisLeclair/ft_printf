/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:36:08 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/28 14:26:50 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_x(va_list ap, int i, char c, char **str)
{
	unsigned long long int d;

	if (i == 1)
		d = va_arg(ap, unsigned long int);
	if (i == 2)
		d = va_arg(ap, unsigned long long int);
	if (i == 4)
		d = va_arg(ap, uintmax_t);
	if (i == 6)
		d = va_arg(ap, size_t);
	else
		d = va_arg(ap, unsigned int);
	*str = ft_itoa_base(d, 16);
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
	if (i == 2)
		d = va_arg(ap, long long int);
	else
		d = va_arg(ap, int);
	tmp = ft_itoa_base(d, 10);
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
