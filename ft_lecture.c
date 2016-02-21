/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 16:53:20 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/21 14:39:46 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_init_var(var_t *myvar)
{
	myvar->flag_precision = 0;
	myvar->flag_largeur = 0;
	myvar->alternate = 0;
	myvar->negation = 0;
	myvar->flag = 0;
	myvar->precision = -1;
	myvar->largeur = 0;
}

static void	ft_search_flags(const char *restrict str, var_t *myvar)
{
	int		i;

	i = 0;
	while ((ft_strchr("-+ #.*hlLjz", str[i]) != NULL
	|| ft_isdigit(str[i])) && str[i])
	{
		if (str[i] == '#')
			myvar->alternate = 1;
		if (str[i] == '-')
		{
			myvar->negation = 1;
			myvar->completion = 'r';
		}
		if (str[i] == '+')
			myvar->flag = '+';
		if (str[i] == ' ' && myvar->flag != '+')
			myvar->flag = ' ';
		i++;
	}
	myvar->type = str[i];
}

static int	ft_affichage(var_t *myvar)
{
	int		value;

	value = ft_strlen(myvar->data);
	ft_putstr(myvar->data);
	free(myvar->data);
	free(myvar->treatment);
	if (value == 0 && myvar->type == 'c')
		value = 1;
	return (value);
}

int			ft_lecture(const char *restrict str, va_list *ap)
{
	int		i;
	var_t	myvar;

	i = 0;
	ft_init_var(&myvar);
	ft_search_flags(str, &myvar);
	if (myvar.type == '\0')
		return (0);
	ft_check_completion(&myvar, str);
	ft_check_treatment(&myvar, str);
	ft_gestion_params(ap, &myvar);
	ft_extension(&myvar, str);
	ft_precision(&myvar);
	if (myvar.alternate == 1)
		ft_alternate_form(&myvar);
	ft_gestion_flags(&myvar);
	if (myvar.flag_largeur == 1 && myvar.negation == 0 && myvar.precision == -1)
		ft_largeur_comp(&myvar);
	else
		ft_largeur(&myvar);
	return (ft_affichage(&myvar));
}
