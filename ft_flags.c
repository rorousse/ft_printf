/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:12:58 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/02 11:55:45 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include "libft/libft.h"

void		ft_alternate_form(t_var *myvar)
{
	if ((myvar->type == 'o' || myvar->type == 'O') && *(myvar->data) != '0')
		ft_insert_str(0, &(myvar->data), "0");
	else if (myvar->type == 'x' && *(myvar->data)
			&& ft_strcmp(myvar->data, "0") != 0)
		ft_insert_str(0, &(myvar->data), "0x");
	else if (myvar->type == 'X' && *(myvar->data)
			&& ft_strcmp(myvar->data, "0") != 0)
		ft_insert_str(0, &(myvar->data), "0X");
	return ;
}

void		ft_gestion_flags(t_var *myvar)
{
	int		i;

	i = 0;
	if (myvar->type != 'c' && myvar->type != 's' && myvar->type != '%' && myvar->type != 'C' && myvar->type != 'S')
	{
		if (myvar->flag == ' ' && *(myvar->data) != '-' && myvar->type != 'u')
			ft_insert_str(0, &(myvar->data), " ");
		if (myvar->flag == '+' && *(myvar->data) != '-' && myvar->type != 'u'
			&& myvar->type != 'U')
			ft_insert_str(0, &(myvar->data), "+");
	}
}
