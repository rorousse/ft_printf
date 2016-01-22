/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:12:58 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/19 13:49:05 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include "libft/libft.h"

void		ft_insert_str(char **dst, char *insertion)
{
	char	*temp;

	temp = (char*)malloc((ft_strlen(*dst) + 1) * sizeof(char));
	ft_strcpy(temp, *dst);
	free(*dst);
	*dst = ft_strjoin(insertion, temp);
	free(temp);
}

void		ft_insert_end(char **dst, char *insertion)
{
	char    *temp;

	temp = (char*)malloc((ft_strlen(*dst) + 1) * sizeof(char));
	ft_strcpy(temp, *dst);
	free(*dst);
	*dst = ft_strjoin(temp, insertion);
	free(temp);
}

void		ft_alternate_form(var_t *myvar)
{
	if (myvar->type == 'o')
		ft_insert_str(&(myvar->data),"0");
	else if (myvar->type == 'x' && ft_strcmp(myvar->data,"0") != 0)
		ft_insert_str(&(myvar->data),"0x");
	else if (myvar->type == 'X')
		ft_insert_str(&(myvar->data),"0X");
	return ;	
}
