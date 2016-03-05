/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:12:58 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/05 15:26:17 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft/libft.h"

void		ft_insert_str(int pos, char **dst, char *insertion)
{
	int		i;
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
	ft_strcpy(temp, *dst);
	free(*dst);
	*dst = ft_strjoin(temp, temp2);
	free(temp);
	free(temp2);
}

void		ft_insert_end(char **dst, char *insertion)
{
	char	*temp;

	temp = (char*)malloc((ft_strlen(*dst) + 1) * sizeof(char));
	ft_strcpy(temp, *dst);
	free(*dst);
	*dst = ft_strjoin(temp, insertion);
	free(temp);
}

void		ft_uni_insert_str(int pos, wchar_t **dst, wchar_t *insertion)
{
	int			i;
	wchar_t		*temp;
	wchar_t		*temp2;

	i = 0;
	temp = (wchar_t*)malloc((pos + 1) * sizeof(wchar_t));
	temp2 = (wchar_t*)malloc((ft_uni_strlen(*dst) - pos + 1) * sizeof(wchar_t));
	while (i < pos)
	{
		temp[i] = dst[0][i];
		i++;
	}
	temp[i] = '\0';
	ft_uni_strcpy(temp2, *dst + pos);
	free(*dst);
	*dst = ft_uni_strjoin(temp, insertion);
	free(temp);
	temp = (wchar_t*)malloc((ft_uni_strlen(*dst) + 1) * sizeof(wchar_t));
	ft_uni_strcpy(temp, *dst);
	free(*dst);
	*dst = ft_uni_strjoin(temp, temp2);
	free(temp);
	free(temp2);
}

void		ft_uni_insert_end(wchar_t **dst, wchar_t *insertion)
{
	wchar_t		*temp;

	temp = (wchar_t*)malloc((ft_uni_strlen(*dst) + 1) * sizeof(wchar_t));
	ft_uni_strcpy(temp, *dst);
	free(*dst);
	*dst = ft_uni_strjoin(temp, insertion);
	free(temp);
}
