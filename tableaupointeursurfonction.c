/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tableaupointeursurfonction.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:32:47 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/26 18:04:07 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_fun	*ft_type(void)
{
	static t_fun *fcts = NULL;

	if (fcts == NULL)
	{
		fcts = malloc(sizeof(t_fun *) * 14);
		fcts[0] = ft_s;
		fcts[1] = ft_d;
		fcts[2] = ft_o;
		fcts[3] = ft_u;
		fcts[4] = ft_x;
		fcts[5] = ft_c;
		fcts[6] = ft_i;
		fcts[7] = ft_p;
		fcts[8] = ft_israndom;
	}
	return (fcts);
}

t_opt	*ft_options(void)
{
	static t_opt *penis = NULL;

	if (penis == NULL)
	{
		penis = malloc(sizeof(t_fun *) * 6);
		// penis[0] = ft_hastag;
		penis[1] = ft_number;
		// penis[2] = ft_minus;
		// penis[3] = ft_plus;
	}
	return (penis);
}
