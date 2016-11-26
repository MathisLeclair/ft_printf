/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:26:39 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/26 18:27:47 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int main(void)
{
	int ret;
	double i;

	i = 9223372036854775807;
	ret = 0;
	printf("vraie = %s = %-15o = %X = %c = %lc\n", "SSSSSSS", 215684, 1368532, 'F', 'f');
	ret = ft_printf("notre = %.5s = %d = %X = %c = %lc\n", "SSSSSSS", 2000000000, 1368532, 'F', 'f');
	return (ret);
}

// int main(void)
// {
// 	printf("%e\n",(double)0);
// }