/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:53:34 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/22 14:08:43 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

void		**ft_type(void);
void		*ft_options(void);
int			ft_addprint(char c);
size_t		ft_strlen(const char *str);
void		*ft_s(va_list ap, int k, char c);
void		*ft_S(va_list ap, int k, char c);
void		*ft_p(va_list ap, int k, char c);
void		*ft_d(va_list ap, int k, char c);
void		*ft_D(va_list ap, int k, char c);
void		*ft_i(va_list ap, int k, char c);
void		*ft_o(va_list ap, int k, char c);
void		*ft_O(va_list ap, int k, char c);
void		*ft_u(va_list ap, int k, char c);
void		*ft_U(va_list ap, int k, char c);
void		*ft_x(va_list ap, int k, char c);
void		*ft_X(va_list ap, int k, char c);
void		*ft_C(va_list ap, int k, char c);
void		*ft_c(va_list ap, int k, char c);
void		*ft_g(va_list ap, int k, char c);
void		*ft_f(va_list ap, int k, char c);

char		*ft_pourcentage(va_list ap, int k, char c);
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