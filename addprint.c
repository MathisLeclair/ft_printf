/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addprint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:45:32 by mleclair          #+#    #+#             */
/*   Updated: 2016/12/03 18:54:09 by mleclair         ###   ########.fr       */
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

// char	*strresize(char *s, int k)
// {
// 	int		len;
// 	char	*tmp;

// 	len = ft_strlen(s);
// 	tmp = malloc(sizeof(char) * (k + len + 1));
// 	tmp[0] = 0;
// 	ft_strcat(tmp, s);
// 	free(s);
// 	return (tmp);
// }

// int		ft_print(char *str, int k, int bool)
// {
// 	static char	*buff;
// 	static int	i;
// 	int			u;

// 	if (buff == NULL)
// 	{
// 		buff = malloc(1);
// 		buff[0] = 0;
// 	}
// 	if (bool == 1)
// 	{
// 		u = i + k;
// 		write(1, buff, u);
// 		ft_bzero(buff, u);
// 		i = 0;
// 		return (u);
// 	}
// 	else
// 	{
// 		i += k;
// 		buff = strresize(buff, k);
// 		ft_strlcat(buff, str, i + 1);
// 		buff[i] = 0;
// 	}
// 	return (i);
// }

///////////////////////////////////////////////////////////////////////
// int		ft_memlcat(char *dst, const char *src, int start, int end)
// {
// 	int i;

// 	i = 0;
// 	while (start < end)
// 	{
// 		dst[start] = src[i];
// 		++i;
// 		++start;
// 	}
// 	dst[start] = '\0';
// 	return (0);
// }


// char	*strresize(char *s, int k, char *opt, int *i)
// {
// 	char	*tmp;

// 	if (opt && opt[ft_strlen(opt) - 1] != 'C' && opt[ft_strlen(opt) - 1] != 'S')
// 	{
// 		tmp = malloc(k + *i);
// 		ft_memcpy(tmp, s, k);
// 		free(s);
// 		return (tmp);
// 	}
// 	else if (opt && opt[ft_strlen(opt) - 1] == 'C' && opt[ft_strlen(opt) - 1] == 'S')
// 	{
// 		tmp = malloc(k * 4 + *i);
// 		ft_memcpy(tmp, s, *i);
// 		*i += k * 4;
// 		free(s);
// 		return(tmp);
// 	}
// 	else
// 	{
// 		tmp = malloc(k + ft_strlen(s));
// 		ft_memcpy(tmp, s, k);
// 		free(s);
// 		return (tmp);
// 	}
// }

// int		ft_print(char *str, int k, int bool, char *opt)
// {
// 	static int	i;
// 	static char *buff;
// 	int			m;

// 	if (buff == NULL)
// 	{
// 		buff = malloc(1);
// 		buff[0] = 0;
// 	}
// 	if (bool == 1)
// 	{
// 		write(1, buff, i);
// 		ft_bzero(buff, i);
// 		m = i + k;
// 		i = 0;
// 		return (m);
// 	}
// 	else
// 	{
// 		i = i + k;
// 		buff = strresize(buff, k, opt, &i);
// 		ft_memlcat(buff, str, i - k , i);
// 	}
// 	return (i);
// }
