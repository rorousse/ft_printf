/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 12:42:20 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/14 16:05:01 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

void	lecture(const char *restrict str, va_list *ap)
{
	char	*dst;
	int		i;

	i = 0;
	while (str[i] && (ft_strchr("diouxXfeEgGcsp",str[i]) == NULL))
	{
		i++;
		if (ft_strchr("diouxXfeEgGcsp%", str[i]) != NULL)
		{
			ft_gestion_params(ap, &dst, str[i]);
			ft_gestion_flags(dst,str);
		}
	}
	write(1,dst,ft_strlen(dst));
}
	
