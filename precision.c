/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:13:18 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/16 16:30:46 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void ft_precision(var_t *myvar)
{
    int     i;
    int     nb;

    nb = myvar->precision;
    i = 0;
    if (nb >= 0 && myvar->type != '%')
    {
        if (myvar->type == 's')
            myvar->data[nb] = '\0';
		if (nb == 0)
			myvar->data[0] = '\0';
	 }
}
