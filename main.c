/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:23:47 by mleclair          #+#    #+#             */
/*   Updated: 2016/12/05 23:12:03 by mleclair         ###   ########.fr       */
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
  ret1 = printf("vrai = {%- 5d}\n", -12);
  ret2 = ft_printf("notr = {%- 5d}\n", -12);
  printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);
}
