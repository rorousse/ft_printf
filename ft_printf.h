/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:21:39 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/15 02:10:26 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>

struct var_t
{
	char *data;
	char flag;
	char *largeur;
	char *precision;
	char modificateur;
	char type;
};

typedef struct var_t var_t;

void		lecture(const char *restrict str, va_list *ap);
void		ft_printf(const char * restrict format, ...);
void		ft_gestion_params(va_list *ap, char **dst, char flag);
void		ft_gestion_flags(char *dst, const char *restrict str);
void		ft_insert_str(char **dst, char *insertion);

#endif
