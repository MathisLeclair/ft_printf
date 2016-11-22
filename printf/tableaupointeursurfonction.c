/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tableaupointeursurfonction.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:32:47 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/22 20:32:08 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_fun	*ft_type(void)
{
	static t_fun *fcts = NULL;

	if (fcts == NULL)
	{
		fcts = malloc(sizeof(ft_s) * 14);
		fcts[0] = ft_s;
		fcts[2] = ft_p;
		fcts[3] = ft_d;
		fcts[4] = ft_o;
		fcts[6] = ft_u;
		fcts[8] = ft_x;
		fcts[10] = ft_c;
		fcts[12] = ft_g;
		fcts[13] = ft_f;
	}
	return (fcts);
}

t_fun	*ft_options(void)
{
	static t_fun *penis = NULL;

	if (penis == NULL)
	{
		penis = malloc(sizeof(ft_pourcentage) * 12);
		penis[0] = ft_pourcentage;
		penis[1] = ft_hastag;
		penis[2] = ft_number;
		penis[3] = ft_zero;
		penis[4] = ft_minus;
		penis[5] = ft_plus;
		penis[6] = ft_h;
		penis[7] = ft_hh;
		penis[8] = ft_z;
		penis[9] = ft_e;
	}
	return (penis);
}
