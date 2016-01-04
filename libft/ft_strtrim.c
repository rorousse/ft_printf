/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 02:08:50 by rorousse          #+#    #+#             */
/*   Updated: 2015/12/15 22:01:17 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_last_word(const char *s)
{
	while (*s)
	{
		if (*s != ' ' && *s != '\n' && *s != '\t')
			return (0);
		s++;
	}
	return (1);
}

static int	check_size(const char *s)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i] && check_last_word(&s[i]) == 0)
	{
		i++;
		len++;
	}
	return (len + 1);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		y;
	char	*str;

	i = 0;
	y = 0;
	if (s == NULL)
		return (NULL);
	str = (char*)malloc(check_size(s) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (check_last_word(s + i) == 0)
	{
		str[y] = s[i];
		i++;
		y++;
	}
	str[y] = '\0';
	return (str);
}
