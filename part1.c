/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:52:29 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/29 19:08:29 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_s(va_list ap, int i, char c, char **str)
{
	wchar_t	*t;
	char	*tmp;

	if (c == 'S' || i == 1)
	{
		i = 0;
		t = va_arg(ap, wchar_t *);
		if (!ft_isascii((int)(*t)))
			return (-1);
		while (t[i])
			++i;
		*str = malloc(sizeof(wchar_t) * i);
		*str = (char *)t;
		return (sizeof(wchar_t) * i);
	}
	tmp = va_arg(ap, char *);
	if (tmp == NULL)
		tmp = "(null)";
	*str = malloc(ft_strlen(tmp) + 1);
	i = 0;
	while (tmp[i])
	{
		(*str)[i] = tmp[i];
		++i;
	}
	(*str)[i] = '\0';
	return (i);
}

int		ft_c(va_list ap, int i, char c, char **str)
{
	wchar_t t;

	if (c == 'S' || i == 1)
	{
		i = 0;
		t = va_arg(ap, wchar_t);
		*str = malloc(sizeof(wchar_t));
		*str = (char *)&t;
		return (4);
	}
	*str = malloc(2);
	*str[0] = va_arg(ap, int);
	(*str)[1] = '\0';
	return (1);
}

int		ft_o(va_list ap, int i, char c, char **str)
{
	long unsigned int	d;
	char				*tmp;

	if (i == 1 || c == 'O')
		d = va_arg(ap, long unsigned int);
	else
		d = va_arg(ap, unsigned int);
	tmp = ft_itoa_base(d, 8, 0);
	*str = malloc(ft_strlen(tmp));
	**str = 0;
	ft_strcat(*str, tmp);
	free(tmp);
	return (ft_strlen(*str));
}

int		ft_u(va_list ap, int i, char c, char **str)
{
	uintmax_t	d;
	char		*tmp;

	if (i == 1 || c == 'D')
		d = va_arg(ap, unsigned long int);
	else if (i == 2)
		d = va_arg(ap, unsigned long long int);
	else if (i == 5)
		d = va_arg(ap, uintmax_t);
	else
		d = va_arg(ap, unsigned int);
	tmp = ft_itoa_base(d, 10, 0);
	*str = malloc(ft_strlen(tmp));
	**str = 0;
	ft_strcat(*str, tmp);
	free(tmp);
	return (ft_strlen(*str));
}
