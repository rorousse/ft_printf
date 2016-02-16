/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:12:58 by rorousse          #+#    #+#             */
/*   Updated: 2016/02/16 13:37:28 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include "libft/libft.h"

void		ft_insert_str(int pos, char **dst, char *insertion)
{
	int i;
	char	*temp;
	char	*temp2;

	i = 0;
	temp = (char*)malloc((pos + 1) * sizeof(char));
	temp2 = (char*)malloc((ft_strlen(*dst) - pos + 1) * sizeof(char));
	while (i < pos)
	{
		temp[i] = dst[0][i];
		i++;
	}
	temp[i] = '\0';
	ft_strcpy(temp2, *dst + pos);
	free(*dst);
	*dst = ft_strjoin(temp, insertion);
	free(temp);
	temp = (char*)malloc((ft_strlen(*dst) + 1) * sizeof(char));
	ft_strcpy(temp,*dst);
	free(*dst);
	*dst = ft_strjoin(temp,temp2);
	free(temp);
	free(temp2);
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
		ft_insert_str(0, &(myvar->data),"0");
	else if (myvar->type == 'x' && ft_strcmp(myvar->data,"0") != 0)
		ft_insert_str(0, &(myvar->data),"0x");
	else if (myvar->type == 'X')
		ft_insert_str(0, &(myvar->data),"0X");
	return ;	
}
