/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 12:42:20 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/12 14:05:14 by rorousse         ###   ########.fr       */
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
	printf("startup\n");
	while (str[i] && (ft_strchr("diouxXfeEgGcsp",str[i]) == NULL))
	{
		printf("up\n");
		i++;
		if (ft_strchr("diouxXfeEgGcsp%", str[i]) != NULL)
		{
			ft_gestion_params(ap, &dst, str[i]);
		}
	}
	printf("endup\n");
	write(1,dst,ft_strlen(dst));
}
	
