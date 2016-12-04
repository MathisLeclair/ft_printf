/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:23:47 by mleclair          #+#    #+#             */
/*   Updated: 2016/12/04 16:59:51 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "printf.h"
#include <locale.h>

int   main()
{
  int ret1 = 0;
  int ret2 = 0;

  printf("Locale is: %s\n", setlocale(LC_ALL, "en_US"));
  ret1 = printf("vrai = %C\n", L'莨');
  ret2 = ft_printf("notr = %C\n", L'莨');
  printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);
}
