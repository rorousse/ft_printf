/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 16:53:20 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/18 16:10:40 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_lecture(const char *restrict str, va_list *ap)
{
	int		value;
	int		i;
	var_t	myvar;

	i = 0;
	while (ft_strchr("diouxXfeEgGcsp%",str[i]) == NULL && str[i])
		i++;
	myvar.type = str[i];
	if (myvar.type == '\0')
	{
		free(myvar.data);
		return (0);
	}
	ft_gestion_params(ap, &myvar, myvar.type);
	ft_gestion_flags(&myvar, str);
	ft_extend(&myvar,str);
	value = ft_strlen(myvar.data);
	ft_putstr(myvar.data);
	free(myvar.data);
	return (value);
}
