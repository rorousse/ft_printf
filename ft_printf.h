/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:21:39 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/15 11:44:16 by rorousse         ###   ########.fr       */
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
	char *treatment;
	char completion;
	int alternate;
	int	flag_precision;
	int	flag_largeur;
	unsigned long long int precision;
	unsigned long long int largeur;
};

typedef struct var_t var_t;

int			ft_lecture(const char *restrict str, va_list *ap);
int			ft_printf(const char * restrict format, ...);
void		ft_gestion_params(va_list *ap, var_t *myvar);
void		ft_gestion_flags(var_t *myvar, const char *restrict str);
void		ft_insert_str(char **dst, char *insertion);
void		ft_alternate_form(var_t *myvar);
int			ft_extend(var_t *myvar, const char *restrict str);
void		ft_largeur(var_t *myvar);
void		ft_largeur_comp(var_t *myvar);
void		ft_precision(var_t *myvar, int nb);
int			ft_extend(var_t *myvar, const char *restrict str);
void		ft_check_completion(var_t *myvar, const char *restrict str);
void		ft_check_treatment(var_t *myvar, const char *restrict str);
void		ft_insert_end(char **dst, char *insertion);

#endif
