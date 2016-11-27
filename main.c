/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:26:39 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/27 19:25:32 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int main(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("############################################################\n");
	printf("                    test de base\n");

	printf("%%s:\n");
	ret1 = printf("vraie = %s\n","Salut");
	ret2 = ft_printf("notre = %s\n","Salut");
	printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

	printf("%%d:\n");
	ret1 = printf("vraie = max = %d min = %d\n", 2147483647, -2147483647);
	ret2 = ft_printf("notre = max = %d min = %d\n",2147483647, -2147483647);
	printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

	printf("%%o:\n");
	ret1 = printf("vraie = max = %o min = %o\n", 2147483647, 0);
	ret2 = ft_printf("notre = max = %o min = %o\n",2147483647, 0);
	printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

	printf("%%u:\n");
	ret1 = printf("vraie = max = %u min = %u\n", 2147483647, 0);
	ret2 = ft_printf("notre = max = %u min = %u\n",2147483647, 0);
	printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

	printf("%%x:\n");
	ret1 = printf("vraie = max = %x min = %x\n", 2147483647, 0);
	ret2 = ft_printf("notre = max = %x min = %x\n",2147483647, 0);
	printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

	printf("%%c:\n");
	ret1 = printf("vraie = a = %c & = %c\n", 'a', '&');
	ret2 = ft_printf("notre = a = %c & = %c\n", 'a', '&');
	printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

	printf("############################################################\n");
	printf("                       options\n");

	printf("%%option 15:\n");
	ret1 = printf("vraie = %15s\n","Salut");
	ret2 = ft_printf("notre = %15s\n","Salut");
	printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

	printf("%%option 15 + 0:\n");
	ret1 = printf("vraie = %015d\n", 123456);
	ret2 = ft_printf("notre = %015d\n", 123456);
	printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

	printf("%%option #:\n");
	ret1 = printf("vraie = %#10x\n", 987654);
	ret2 = ft_printf("notre = %#10x\n",987654);
	printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

	ret1 = printf("vraie = %#06x\n", 987654);
	ret2 = ft_printf("notre = %#06x\n",987654);
	printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

	ret1 = printf("vraie = %#010x\n", 987654);
	ret2 = ft_printf("notre = %#010x\n",987654);
	printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

	ret1 = printf("vraie = %#5x\n", 987654);
	ret2 = ft_printf("notre = %#5x\n",987654);
	printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);

	ret1 = printf("vraie = %5%\n");
	ret2 = ft_printf("notre = %5%\n");
	printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);
}

// int main(void)
// {
// 	printf("%e\n",(double)0);
// }