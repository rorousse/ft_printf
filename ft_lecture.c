/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 16:53:20 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/11 14:50:11 by rorousse         ###   ########.fr       */
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
	while ((ft_strchr("-+ #.*hlLjz", str[i]) != NULL || ft_isdigit(str[i])) && str[i])
		i++;
	myvar.type = str[i];
	if (myvar.type == '\0')
	{
		return (0);
	}
	ft_check_completion(&myvar, str);
	ft_check_treatment(&myvar, str);
	ft_gestion_params(ap, &myvar);
	ft_gestion_flags(&myvar, str);
	ft_extend(&myvar,str);
	value = ft_strlen(myvar.data);
	ft_putstr(myvar.data);
	free(myvar.data);
	free(myvar.treatment);
	if (value == 0)
		value = 1;
	return (value);
}
