#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rorousse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 03:14:08 by rorousse          #+#    #+#              #
#    Updated: 2016/03/08 11:57:06 by rorousse         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
HEADER = ft_printf.h libft/libft.h
SRC_PATH=./
OBJ_PATH=./
LIBS= libft/libft.a
SRC = ft_flags.c ft_largeur.c ft_lecture.c ft_params.c ft_printf.c ft_precision.c ft_insertion.c ft_extension.c ft_treatment.c ft_integer.c ft_hexa.c ft_octal.c ft_affichage.c ft_double.c

OBJ = $(SRC:.c=.o )

all : lib $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	libtool -static -o $(NAME) $(NAME) $(LIBS)

lib :
	make -C libft/

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	gcc -Wall -Werror -Wextra -o $@ -c $<

clean :
	/bin/rm -f $(OBJ)
	make clean -C libft/

fclean : clean
	/bin/rm -f $(NAME)
	make fclean -C libft/

re : fclean all
