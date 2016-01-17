/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 16:53:20 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/17 17:44:03 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_lecture(const char *restrict str, va_list *ap)
{
	int		i;
	var_t	myvar;

	i = 0;
	while (ft_strchr("diouxXfeEgGcsp",str[i]) == NULL)
		i++;
	myvar.type = str[i];
	ft_gestion_params(ap, &myvar, myvar.type);
	ft_gestion_flags(&myvar, str);
	ft_putstr(myvar.data);
	free(myvar.data);
	return (0);
}
