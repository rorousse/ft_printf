/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 17:26:42 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/22 17:29:18 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <inttypes.h>

void	ft_gestion_hexa(va_list *ap, t_var *myvar)
{
	int	i;

	i = 0;
	if (ft_strcmp(myvar->treatment, "l") == 0)
		myvar->data = unsigned_itoa_base(va_arg(*ap, unsigned long int), 16);
	else if (ft_strcmp(myvar->treatment, "ll") == 0)
		myvar->data = unsigned_itoa_base(va_arg(*ap, unsigned long long), 16);
	else if (ft_strcmp(myvar->treatment, "j") == 0)
		myvar->data = unsigned_itoa_base(va_arg(*ap, uintmax_t), 16);
	else
		myvar->data = unsigned_itoa_base(va_arg(*ap, unsigned int), 16);
	if (myvar->type == 'X')
		while (myvar->data[i])
		{
			myvar->data[i] = ft_toupper(myvar->data[i]);
			i++;
		}
}
