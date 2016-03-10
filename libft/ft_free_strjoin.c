/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 11:58:53 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/10 16:50:24 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_free_strjoin(char **str, char *str2)
{
	char	*temp;

	temp = ft_strdup(*str);
	free(*str);
	*str = ft_strjoin(temp, str2);
	free(temp);
}
