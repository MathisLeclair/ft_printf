/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tableaupointeursurfonction.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:32:47 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/22 14:10:47 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	**ft_type(void)
{
	static void (**fcts) = NULL;

	if (fcts == NULL)
	{
		fcts = malloc(sizeof(ft_s) * 14);
		fcts[0] = &ft_s;
		fcts[1] = &ft_S;
		fcts[2] = &ft_p;
		fcts[3] = &ft_d;
		fcts[4] = &ft_o;
		fcts[5] = &ft_O;
		fcts[6] = &ft_u;
		fcts[7] = &ft_U;
		fcts[8] = &ft_x;
		fcts[9] = &ft_X;
		fcts[10] = &ft_c;
		fcts[11] = &ft_C;
		fcts[12] = &ft_g;
		fcts[13] = &ft_f;
	}
	return (fcts);
}

void	*ft_options(void)
{
	static void (*penis)(va_list, int, char) = NULL;

	if (penis == NULL)
	{
		penis = malloc(sizeof(ft_pourcentage) * 12);
		penis[0] = &ft_pourcentage;
		penis[1] = &ft_hastag;
		penis[2] = &ft_number;
		penis[3] = &ft_zero;
		penis[4] = &ft_minus;
		penis[5] = &ft_plus;
		penis[6] = &ft_h;
		penis[7] = &ft_hh;
		penis[8] = &ft_l;
		penis[9] = &ft_ll;
		penis[10] = &ft_z;
		penis[11] = &ft_e;
	}
	return (penis);
}
