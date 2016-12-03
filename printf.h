/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:53:34 by mleclair          #+#    #+#             */
/*   Updated: 2016/12/03 16:40:10 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include "./libft/libft.h"

#include <stdio.h>

typedef int (*t_fun)(va_list, int, char, char **);
typedef int (*t_opt)(int, int, int, char **);

void		ft_error(void);
t_fun		*ft_type(void);
t_opt		*ft_options(void);
int			ft_isokay(char c);
int			ft_printf(const char *str, ...);
void		ft_apliopt(char *res, char *str);
int			ft_opts(char *opt, char **str, int i);
int			ft_print(char *str, int k, int u);
char		*ft_itoa_base(uintmax_t value, int base, char neg);
int			ft_atoi_base_printf(const char *str, int str_base, int i);

int			ft_s(va_list ap, int k, char c, char **str);
int			ft_S(va_list ap, int k, char c, char **str);
int			ft_p(va_list ap, int k, char c, char **str);
int			ft_d(va_list ap, int k, char c, char **str);
int			ft_D(va_list ap, int k, char c, char **str);
int			ft_i(va_list ap, int k, char c, char **str);
int			ft_o(va_list ap, int k, char c, char **str);
int			ft_O(va_list ap, int k, char c, char **str);
int			ft_u(va_list ap, int k, char c, char **str);
int			ft_U(va_list ap, int k, char c, char **str);
int			ft_x(va_list ap, int k, char c, char **str);
int			ft_X(va_list ap, int k, char c, char **str);
int			ft_C(va_list ap, int k, char c, char **str);
int			ft_c(va_list ap, int k, char c, char **str);
int			ft_israndom(va_list ap, int i, char c, char **str);

int			ft_hastag(int k, int i, int boul, char **str);
int			ft_number(int k, int i, int boul, char **str);
int			ft_minus(int k, int i, int boul, char **str);
int			ft_plus(int k, int i, int boul, char **str);

#endif
