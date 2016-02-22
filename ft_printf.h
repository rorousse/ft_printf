/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:21:39 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/22 17:43:44 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>

struct					s_var
{
	char				*data;
	char				type;
	char				treatment[3];
	char				completion;
	int					alternate;
	int					flag_precision;
	int					flag_largeur;
	int					negation;
	char				flag;
	int					char_null;
	long long int		precision;
	long long int		largeur;
};

typedef struct s_var	t_var;

int						ft_lecture(const char *restrict str, va_list *ap);
int						ft_printf(const char *restrict format, ...);
void					ft_gestion_params(va_list *ap, t_var *myvar);
void					ft_gestion_flags(t_var *myvar);
void					ft_insert_str(int pos, char **dst, char *insertion);
void					ft_alternate_form(t_var *myvar);
int						ft_extend(t_var *myvar, const char *restrict str);
void					ft_largeur(t_var *myvar);
void					ft_largeur_comp(t_var *myvar);
void					ft_precision(t_var *myvar);
int						ft_extension(t_var *myvar, const char *restrict str);
void					ft_check_completion(t_var *myvar,
						const char *restrict str);
void					ft_check_treatment(t_var *myvar,
						const char *restrict str);
void					ft_insert_end(char **dst, char *insertion);
void					ft_gestion_integer(va_list *ap, t_var *myvar);
void					ft_gestion_hexa(va_list *ap, t_var *myvar);
void					ft_gestion_octal(va_list *ap, t_var *myvar);

#endif
