/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 106:11:27 by mleclair          #+#    #+#             */
/*   Updated: 2016/12/03 19:23:47 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <locale.h>

int   main()
{
  int ret1 = 0;
  int ret2 = 0;
  char c[5];


//  printf("Locale is: %s\n", setlocale(LC_ALL, "en_US"));
  ret1 = printf("vrai = %c\n", 'a');
    c[0] = 0xf0;
    c[1] = 0x81;
    c[2] = 0x88;
    c[3] = 0xb4;
    c[4] = 0x00;
    write(1, c, 5);
 // ret2 = ft_printf("notr = %lc\n", L'莨');
  printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);
}
