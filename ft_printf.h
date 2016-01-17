/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:21:39 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/17 18:36:06 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>

struct var_t
{
	char *data;
	char type;
};

typedef struct var_t var_t;

int			ft_lecture(const char *restrict str, va_list *ap);
void		ft_printf(const char * restrict format, ...);
void		ft_gestion_params(va_list *ap, var_t *myvar, char flag);
void		ft_gestion_flags(var_t *myvar, const char *restrict str);
void		ft_insert_str(char **dst, char *insertion);
void		ft_alternate_form(const char *restrict str, var_t *myvar);
int			ft_extend(var_t *myvar, const char *restrict str);

#endif
