/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:49:59 by rorousse          #+#    #+#             */
/*   Updated: 2015/12/08 15:00:22 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if ((**alst).next != NULL)
		ft_lstdel(&((**alst).next), (*del));
	(*del)((**alst).content, (**alst).content_size);
	free(*alst);
	*alst = NULL;
}
