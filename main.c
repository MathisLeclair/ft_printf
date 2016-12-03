/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:11:27 by mleclair          #+#    #+#             */
/*   Updated: 2016/12/03 19:23:47 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <locale.h>

int   main()
{
  int ret1 = 0;
  int ret2 = 0;
  char c[4];


//  printf("Locale is: %s\n", setlocale(LC_ALL, "en_US"));
  ret1 = printf("vrai = %08x\n", L'ሴ');
    c[0] = 0xe1;
    c[1] = 0x88;
    c[2] = 0xb4;
    c[3] = 0x61;
    write(1, c, 4);
 // ret2 = ft_printf("notr = %lc\n", L'莨');
  printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);
}