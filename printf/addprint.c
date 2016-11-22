/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addprint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:45:32 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/22 10:54:00 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_addprint(char c)
{
	static char str[2048];
	static int 	printtotal;
	static int	count;
	if (c == 0)
		return (printtotal);
	if (count < 2048)
	{
		str[count] = c;
		++count;
		++printtotal;
	}
	else
	{
		write(1, str, 2048);
		count = 0;
	}
	return (printtotal);
}