/*
  ** main.c for main in /u/all/lepage_b/cu/test/printf
  ** 
  ** Made by barbara lepage
  ** Login   
  ** 
  ** Started on  Mon Nov  9 14:50:10 2009 barbara lepage
** Last update Sat Dec 12 20:37:18 2009 barbara lepage
*/

#include "printf.h"

int   main()
{
  int ret1 = 0;
  int ret2 = 0;
  int i;
  i =58;

  printf("%%s:\n");
  ret1 = printf("vrai = %.2d\n", -1);
  ret2 = ft_printf("notr = %.2d\n", -1);
  printf("ret1 = %d, ret2 = %d\n\n", ret1, ret2);
}