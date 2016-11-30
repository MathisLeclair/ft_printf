/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addprint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:45:32 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/30 11:38:54 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*strresize(char *s, int k)
{
	int		len;
	char	*tmp;

	len = ft_strlen(s);
	tmp = malloc(sizeof(char) * (k + len + 1));
	tmp[0] = 0;
	ft_strcat(tmp, s);
	free(s);
	return (tmp);
}

int		ft_print(char *str, int k, int bool)
{
	static int	i;
	static char *buff;
	int			u;

	if (buff == NULL)
	{
		buff = malloc(1);
		buff[0] = 0;
	}
	if (bool == 1)
	{
		u = i + k;
		write(1, buff, u);
		ft_bzero(buff, u);
		i = 0;
		return (u);
	}
	else
	{
		i = i + k;
		buff = strresize(buff, k);
		ft_strlcat(buff, str, i + 1);
		buff[i] = 0; 
	}
	return (i);
}
