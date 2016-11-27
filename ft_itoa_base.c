/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:58:50 by exam              #+#    #+#             */
/*   Updated: 2016/11/27 11:15:18 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_power(long long int value, int power)
{
	if (power == 0)
		return (1);
	while (power > 1)
		value *= value;
	return (value);
}

char	*sol(int i, char neg, long long int save, int base)
{
	char	*str;
	char	*slo;
	int		j;

	str = "0123456789ABCDEF";
	slo = malloc(i + neg + 1);
	slo[i + neg] = '\0';
	if (neg == 1)
		slo[0] = '-';
	if (save == 0)
		slo[0] = '0';
	while (save < 0)
	{
		j = -1 * (save % base);
		slo[i - 1] = str[j];
		save = save / base;
		i--;
	}
	return (slo);
}

char	*ft_itoa_base(long long int value, int base)
{
	int				i;
	long long int	save;
	char			neg;

	i = 0;
	neg = 0;
	if (base == 10 && value < 0)
	{
		i++;
		neg = 1;
	}
	if (value == 0)
		i++;
	if (value > 0)
		value *= -1;
	save = value;
	while (value < 0)
	{
		value = value / base;
		i++;
	}
	return (sol(i, neg, save, base));
}
