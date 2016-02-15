/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 16:53:20 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/15 16:01:09 by rorousse         ###   ########.fr       */
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
	myvar.flag_precision = 0;
	myvar.flag_largeur = 0;
	myvar.alternate = 0;
	while ((ft_strchr("-+ #.*hlLjz", str[i]) != NULL || ft_isdigit(str[i])) && str[i])
		i++;
	myvar.type = str[i];
	if (myvar.type == '\0')
	{
		return (0);
	}
	i = 0;
	while (str[i] != myvar.type)
	{
		if (str[i] == '#')
			myvar.alternate = 1;
		i++;
	}
	ft_check_completion(&myvar, str);
	ft_check_treatment(&myvar, str);
	ft_gestion_params(ap, &myvar);
	ft_extend(&myvar,str);
	ft_gestion_flags(&myvar, str);
	ft_precision(&myvar);
	if(myvar.flag_largeur == 1)
		ft_largeur_comp(&myvar);
	if(myvar.flag_largeur == 0)
		ft_largeur(&myvar);
	value = ft_strlen(myvar.data);
	ft_putstr(myvar.data);
	free(myvar.data);
	free(myvar.treatment);
	if (value == 0)
		value = 1;
	return (value);
}
