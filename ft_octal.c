/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 17:37:29 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/22 17:48:33 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <inttypes.h>

void	ft_gestion_octal(va_list *ap, t_var *myvar)
{
	int	i;

	i = 0;
	if (ft_strcmp(myvar->treatment, "l") == 0 || myvar->type == 'O')
		myvar->data = unsigned_itoa_base(va_arg(*ap, unsigned long int), 8);
	else if (ft_strcmp(myvar->treatment, "ll") == 0)
		myvar->data = unsigned_itoa_base(va_arg(*ap, unsigned long long), 8);
	else if (ft_strcmp(myvar->treatment, "j") == 0)
		myvar->data = unsigned_itoa_base(va_arg(*ap, uintmax_t), 8);
	else
		myvar->data = unsigned_itoa_base(va_arg(*ap, unsigned int), 8);
}
