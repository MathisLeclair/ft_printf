/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:26:39 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/29 14:22:10 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int main(void)
{
	int ret1 = 0;
	int ret2 = 0;
  int i;
  i =58;

	printf("%%s:\n");
	ret1 = printf("vrai = %s\n", 0);
	ret2 = ft_printf("notr = %s\n", 0);
	printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);
}
