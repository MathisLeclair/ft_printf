/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:26:39 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/25 12:07:02 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int main(void)
{
	int ret;

	ret = 0;
	ret = ft_printf("test%o\n", 75);
	return (ret);
}

// int main(void)
// {
// 	printf("%e\n",(double)0);
// }