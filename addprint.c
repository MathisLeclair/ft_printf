/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addprint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:45:32 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/27 11:18:05 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print(char *str, int k, int bool)
{
	static int	i;
	int			u;

	if (bool == 1)
	{
		u = i;
		u = u + k;
		write(1, str, k);
		ft_bzero(str, k);
		i = 0;
		return (u);
	}
	else
	{
		i = i + k;
		write(1, str, k);
		ft_bzero(str, k);
	}
	return (i);
}
