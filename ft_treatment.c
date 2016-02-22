/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 16:26:19 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/22 15:48:28 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>

void		ft_check_treatment(t_var *myvar, const char *restrict str)
{
	int		i;
	int		taille;

	i = 0;
	taille = 0;
	while (str[i] != myvar->type && str[i])
	{
		if (ft_strchr("jhlLz", str[i]))
		{
			myvar->treatment[taille] = str[i];
			taille++;
		}
		i++;
	}
}

void		ft_check_completion(t_var *myvar, const char *restrict str)
{
	myvar->completion = 'l';
	while (*str != myvar->type)
	{
		if (*str == '-')
			myvar->completion = 'r';
		str++;
	}
}
