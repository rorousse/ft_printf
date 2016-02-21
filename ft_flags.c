/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:12:58 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/21 14:30:12 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include "libft/libft.h"

void		ft_alternate_form(var_t *myvar)
{
	if (myvar->type == 'o')
		ft_insert_str(0, &(myvar->data), "0");
	else if (myvar->type == 'x' && *(myvar->data)
			&& ft_strcmp(myvar->data, "0") != 0)
		ft_insert_str(0, &(myvar->data), "0x");
	else if (myvar->type == 'X' && *(myvar->data)
			&& ft_strcmp(myvar->data, "0") != 0)
		ft_insert_str(0, &(myvar->data), "0X");
	return ;
}
