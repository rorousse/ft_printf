/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:23:21 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/17 18:10:50 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *chaine;
       	int bonbons = 28;
		char c = 'z';

		chaine = (char*)malloc(6*sizeof(char));
		ft_printf("le pointeur est %p et j'ai %d bonbons, %o en octal et mon char est %c\n",chaine,bonbons,bonbons,c);
		printf("%10d\n",1234);
		free(chaine);
	return (0);
}
