/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 16:53:20 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/20 11:52:16 by rorousse         ###   ########.fr       */
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
	myvar.negation = 0;
	myvar.flag = 0;
	myvar.precision = -1;
	myvar.largeur = 0;
	while ((ft_strchr("-+ #.*hlLjz", str[i]) != NULL || ft_isdigit(str[i])) && str[i])
	{
		if (str[i] == '#')
			myvar.alternate = 1;
		if (str[i] == '-')
		{
			myvar.negation = 1;
			myvar.completion = 'r';
		}
		if (str[i] == '+')
			myvar.flag = '+';
		if (str[i] == ' ' && myvar.flag != '+')
			myvar.flag = ' ';
		i++;
	}
	myvar.type = str[i];
	if (myvar.type == '\0')
		return (0);
	i = 0;
	ft_check_completion(&myvar, str);
	ft_check_treatment(&myvar, str);
	ft_gestion_params(ap, &myvar);
	ft_extend(&myvar,str);
	ft_precision(&myvar);
	if (myvar.alternate == 1)
		ft_alternate_form(&myvar);
	ft_gestion_flags(&myvar);
	if(myvar.flag_largeur == 1 && myvar.negation == 0)
		ft_largeur_comp(&myvar);
	else
		ft_largeur(&myvar);
	value = ft_strlen(myvar.data);
	ft_putstr(myvar.data);
	free(myvar.data);
	free(myvar.treatment);
	if (value == 0 && myvar.type == 'c')
		value = 1;
	return (value);
}
