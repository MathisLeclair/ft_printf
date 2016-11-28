/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:26:39 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/28 18:25:09 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int main(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("%%s:\n");
	ret1 = printf("vrai = %   5d\n", 57);
	ret2 = ft_printf("notr = %   5d\n", 57);
	printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);
}
