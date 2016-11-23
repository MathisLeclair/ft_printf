/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:53:34 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/23 17:41:20 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef char *(*t_fun)(va_list, int, char);

t_fun		*ft_type(void);
t_fun		*ft_options(void);
int			ft_print(char *str, int k);
size_t		ft_strlen(const char *str);
void		ft_apliopt(char *res, char *str);
char		*ft_strdup(const char *src);
int			ft_isokay(char c);
char		*ft_itoa_base(int value, int base);

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
int			ft_g(va_list ap, int k, char c, char **str);
int			ft_f(va_list ap, int k, char c, char **str);

char		*ft_israndom(va_list ap, int k, char c);
char		*ft_hastag(va_list ap, int k, char c);
char		*ft_number(va_list ap, int k, char c);
char		*ft_zero(va_list ap, int k, char c);
char		*ft_minus(va_list ap, int k, char c);
char		*ft_plus(va_list ap, int k, char c);
char		*ft_h(va_list ap, int k, char c);
char		*ft_hh(va_list ap, int k, char c);
char		*ft_l(va_list ap, int k, char c);
char		*ft_ll(va_list ap, int k, char c);
char		*ft_z(va_list ap, int k, char c);
char		*ft_e(va_list ap, int k, char c);

#endif
