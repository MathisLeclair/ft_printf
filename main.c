/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:23:47 by mleclair          #+#    #+#             */
/*   Updated: 2016/12/06 13:32:34 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "printf.h"
#include <locale.h>
#include <limits.h>

int   main()
{
  int ret1 = 0;
  int ret2 = 0;

  // printf("Locale is: %s\n", setlocale(LC_ALL, "en_US"));
  ret1 = printf("vrai = % i\n", 9999);
  ret2 = ft_printf("notr = % i\n", 9999);
  printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);
}
