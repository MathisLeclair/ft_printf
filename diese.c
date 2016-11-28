/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diese.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 18:53:34 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/28 15:07:12 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_2long(int k, int i, char **str)
{
	char *tmp;

	tmp = NULL;
	if (k == 1 || k == 0)
	{
		tmp = malloc(i + 3 - k);
		tmp[0] = '0';
		tmp[1] = 'x';
		tmp[2] = '\0';
		ft_strcat(tmp, *str + k);
		if (tmp[i] == ' ')
			tmp[i] = '\0';
	}
	else
	{
		if ((*str)[0] == '0')
			(*str)[1] = 'x';
		else
		{
			(*str)[k - 1] = 'x';
			(*str)[k - 2] = '0';
		}
	}
	return (tmp);
}

char	*ft_2long2(int k, int i, char **str)
{
	char *tmp;

	tmp = NULL;
	if (k == 1)
		**str = '0';
	else if (k == 0)
	{
		tmp = malloc(i + 2);
		tmp[0] = '0';
		tmp[1] = '\0';
		ft_strcat(tmp, *str);
		if (tmp[i] == ' ')
			tmp[i] = 0;
	}
	else if ((*str)[0] == ' ')
		(*str)[k - 1] = '0';
	return (tmp);
}

int		ft_hastag(int k, int i, int bool, char **str)
{
	char *tmp;

	tmp = NULL;
	while ((*str)[k] == ' ' || (*str)[k] == '0')
		++k;
	if (bool == 1)
		tmp = ft_2long(k, i, str);
	else
		tmp = ft_2long2(k, i, str);
	if (tmp != NULL)
		free(*str);
	if (tmp != NULL)
		*str = tmp;
	return (ft_strlen(*str));
}
