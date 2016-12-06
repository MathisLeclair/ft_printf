/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:52:29 by mleclair          #+#    #+#             */
/*   Updated: 2016/12/06 16:56:50 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_wstrlen(wchar_t *str)
{
	wchar_t *tmp;

	tmp = str;
	while (*tmp != 0)
		tmp++;
	return (tmp - str);
}

int		ft_s(va_list ap, int i, char c, char **str)
{
	wchar_t	*t;
	char	*tmp;
	int		u;
	int		k;

	if (c == 'S' || i == 1)
	{
		u = 0;
		i = 0;
		t = va_arg(ap, wchar_t *);
		if (t == NULL)
		{
			*str = malloc(7);
			**str = 0;
			ft_strcat(*str, "(null)");
			return (6);
		}
		*str = malloc((ft_wstrlen(t) + 1) * sizeof(wchar_t));
		ft_bzero(*str, (ft_wstrlen(t) + 1));
		while (t[i])
		{
			k = conv(t[i], *str + u);
			u += k;
			++i;
		}
		return (u);
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
	wint_t t;

	if (c == 'C' || i == 1)
	{
		*str = malloc(4);
		conv(t = va_arg(ap, wint_t), *str);
		if (t <= 0x7F)
			return (1);
		else if (t <= 0x7FF)
			return (2);
		else if (t <= 0xFFFF)
			return (3);
		else if (t <= 0x10FFFF)
			return (4);
		return (-1);
	}
	*str = malloc(2);
	*str[0] = (char)va_arg(ap, int);
	(*str)[1] = '\0';
	return (1);
}

int		ft_o(va_list ap, int i, char c, char **str)
{
	uintmax_t	d;
	char		*tmp;

	if (i == 1 || c == 'O')
		d = va_arg(ap, long unsigned int);
	else if (i == 2)
		d = va_arg(ap, unsigned long long int);
	else if (i == -2)
		d = (unsigned char)va_arg(ap, int);
	else if (i == 5)
		d = va_arg(ap, uintmax_t);
	else if (i == 6)
		d = va_arg(ap, size_t);
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

	if (i == 1 || c == 'U')
		d = va_arg(ap, unsigned long int);
	else if (i == 2)
		d = va_arg(ap, unsigned long long int);
	else if (i == 5)
		d = va_arg(ap, uintmax_t);
	else if (i == 6)
		d = va_arg(ap, size_t);
	else if (i == -2)
		d = (unsigned char)va_arg(ap, int);
	else
		d = va_arg(ap, unsigned int);
	tmp = ft_itoa_base(d, 10, 0);
	*str = malloc(ft_strlen(tmp));
	**str = 0;
	ft_strcat(*str, tmp);
	free(tmp);
	return (ft_strlen(*str));
}
