/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 12:42:20 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/10 13:52:42 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

void	lecture(const char *restrict str, va_list *ap)
{
	char	**dst;
	int		i;

	i = 0;
	dst = (char**)malloc(sizeof(char*));
	while (str[i])
	{
		i++;
		if (ft_strchr("diouxXfeEgGcsp%", str[i]) != NULL)
		{
			ft_gestion_params(ap, dst, str[i]);
		}
	}
	write(1,*dst,ft_strlen(*dst));
	free(*dst);
	free(dst);
}
	
