/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 18:52:27 by exam              #+#    #+#             */
/*   Updated: 2016/11/27 11:15:54 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi_base(const char *str, int str_base)
{
	int		i;
	int		j;
	int		nb;
	char	*str1;
	char	*str2;

	nb = 0;
	i = 0;
	str1 = "0123456789abcdef";
	str2 = "0123456789ABCDEF";
	if (str[0] == '+' || str[0] == '-')
		++i;
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f')
	|| (str[i] >= 'A' && str[i] <= 'F'))
	{
		j = 0;
		while (str[i] != str1[j] && str[i] != str2[j])
			++j;
		if (j >= str_base)
			return (nb * (str[0] == '-' ? -1 : 1));
		nb = nb * str_base + j;
		++i;
	}
	return (nb * (str[0] == '-' ? -1 : 1));
}
