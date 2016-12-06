/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tobecontinued.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 17:16:29 by mleclair          #+#    #+#             */
/*   Updated: 2016/12/06 18:24:33 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_number(int k, int i, int bool, char **str)
{
	char	*tmp;

	if (i == 0 && (*str)[0] == '0' && (*str)[1] == 0)
	{
		**str = 0;
		return (0);
	}
	if (i < 0)
		i *= -1;
	if (k < i)
		tmp = malloc(i + 1);
	else
		return (k);
	tmp = ft_memset(tmp, (bool == 1 ? '0' : ' '), i);
	if ((*str)[1] == 'x' && (*str)[0] == '0' && bool == 1)
	{
		tmp[i - k + 2] = 0;
		ft_strcat(tmp + i - k + 2, *str + 2);
		tmp[1] = 'x';
		free(*str);
		*str = tmp;
		return (i);
	}
	tmp[i - k] = '\0';
	ft_strcat(tmp + i - k, *str);
	k = 0;
	while (tmp[k])
	{
		if (tmp[k] == '-' && k > 0 && tmp[k - 1] == '0')
		{
			tmp[k] = '0';
			tmp[0] = '-';
		}
		++k;
	}
	free(*str);
	*str = tmp;
	return (i);
}

int		ft_plus(int k, int i, int bool, char **str)
{
	char *tmp;

	i = bool;
	if ((*str)[0] == '0' && (*str)[1] != 0 && bool == 0)
		(*str)[0] = '+';
	if ((*str)[0] == '0' && (*str)[1] == 0)
		return (k);
	if (ft_isdigit((*str)[0]))
	{
		(*str)[k] = '\0';
		tmp = malloc(k + 2);
		tmp = ft_memset(tmp, '\0', 2);
		ft_strcat(tmp + 1, *str);
		if ((*str)[ft_strlen(*str) - 1] == ' ' && --k)
			tmp[k + 1] = 0;
		tmp[0] = '+';
		free(*str);
		*str = tmp;
		return (k + 1);
	}
	return (k);
}

int		ft_moncul(char *opt, char **str, int i)
{
	size_t	k;
	char	*tmp;

	tmp = malloc(i + 2);
	if (opt[ft_strlen(opt) - 1] == 'd' || opt[ft_strlen(opt) - 1] == 'i')
	{
		k = 0;
		while (ft_isdigit((*str)[k]))
			++k;
		if ((*str)[ft_strlen(*str) - 1] == ' ' || k == ft_strlen(*str))
		{
			if ((*str)[0] == '0' && k == ft_strlen(*str))
			{
				(*str)[0] = ' ';
				return (i);
			}
			else
			{
				tmp[0] = ' ';
				k = 0;
				while (str[k])
				{
					tmp[k + 1] = (*str)[k];
					++k;
				}
				tmp[k + 1] = 0;
				free(*str);
				*str = tmp;
				return (i + 1);
			}
		}
	}
	return (i);
}

int		ft_minus(int k, int i, int bool, char **str)
{
	char *tmp;

	i = 0;
	if ((*str)[i] == '-')
		++i;
	while ((*str)[i] == ' ' || ((*str)[i] == '0' && bool == -1))
		++i;
	if ((*str)[i] == 0 && (*str)[i - 1] == '0')
	{
		(*str)[i - 1] = ' ';
		(*str)[0] = '0';
		return (k);
	}
	tmp = malloc(k + 1);
	if ((*str)[0] == '-')
		tmp[0] = '-';
	tmp[((*str)[0] == '-' ? 1 : 0)] = 0;
	tmp = ft_strcat(tmp, *str + i + ((*str)[i] == 'x' ? -1 : 0));
	free(*str);
	*str = tmp;
	while (i--)
		(*str)[i + ft_strlen(tmp)] = ' ';
	return (k);
}
