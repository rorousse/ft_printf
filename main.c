/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:23:21 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/06 15:31:47 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  //char *chaine;
       	double bonbons = 28.12345678901234567890;
	//	char c = 'z';
	//double nb = 729.151;

	//	chaine = (char*)malloc(6*sizeof(char));
	printf("%.12f",bonbons);
	//	ft_printf("le pointeur est %p et j'ai %d bonbons, %o en octal et mon char est %c et nb vaut %f\n",chaine,bonbons,bonbons,c,nb);
	//	free(chaine);
	return (0);
}
