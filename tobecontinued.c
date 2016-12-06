/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tobecontinued.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 17:16:29 by mleclair          #+#    #+#             */
/*   Updated: 2016/12/06 13:34:04 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_number(int k, int i, int bool, char **str)
{
	char	*tmp;
	int		len;

	if (i == 0 && (*str)[0] == '0' && (*str)[1] == 0)
	{
		**str = 0;
		return (0);
	}
	if (i < 0)
		i *= -1;
	len = ft_strlen(*str);
	if (len < i)
		tmp = malloc(i + 1);
	else
		return (k);
	tmp = ft_memset(tmp, (bool == 1 ? '0' : ' '), i - len);
	tmp[i - len] = '\0';
	ft_strcat(tmp + i - len, *str);
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
	if (ft_isdigit((*str)[0]))
	{
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
	tmp = malloc(k + 1);
	if ((*str)[0] == '-')
		tmp[0] = '-';
	tmp[((*str)[0] == '-' ? 1 : 0)] = 0;
	tmp = ft_strcat(tmp, *str + i);
	free(*str);
	*str = tmp;
	while (i--)
		(*str)[i + ft_strlen(tmp)] = ' ';
	return (k);
}
