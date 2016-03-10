/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   couleur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:00:51 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/10 16:50:59 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int	comparaison(char *temp)
{
	if (ft_strcmp(temp, "noir") == 0)
		write(1, "\033[30m", 5);
	else if (ft_strcmp(temp, "rouge") == 0)
		write(1, "\033[31m", 5);
	else if (ft_strcmp(temp, "vert") == 0)
		write(1, "\033[32m", 5);
	else if (ft_strcmp(temp, "jaune") == 0)
		write(1, "\033[33m", 5);
	else if (ft_strcmp(temp, "bleu") == 0)
		write(1, "\033[34m", 5);
	else if (ft_strcmp(temp, "magenta") == 0)
		write(1, "\033[35m", 5);
	else if (ft_strcmp(temp, "cyan") == 0)
		write(1, "\033[36m", 5);
	else if (ft_strcmp(temp, "blanc") == 0)
		write(1, "\033[37m", 5);
	else if (ft_strcmp(temp, "eoc") == 0)
		write(1, "\033[0m", 4);
	else if (ft_strcmp(temp, "shiny") == 0)
		write(1, "\033[5m", 4);
	else
		return (0);
	return (1);
}

int			coloration(const char *restrict str)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char*)malloc((ft_strlen(str) + 1) * sizeof(char));
	ft_strcpy(temp, (char*)str);
	while (temp[i])
	{
		if (temp[i] == '}')
		{
			temp[i] = '\0';
			i--;
		}
		i++;
	}
	i = comparaison(temp);
	free(temp);
	return (i);
}
