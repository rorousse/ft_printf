#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rorousse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 03:14:08 by rorousse          #+#    #+#              #
#    Updated: 2016/01/18 15:37:35 by rorousse         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
HEADER = ft_printf.h libft/libft.h
SRC_PATH=./
OBJ_PATH=./
LIBS= libft/libft.a
SRC = ft_flags.c ft_largeur.c ft_lecture.c ft_params.c ft_printf.c  

OBJ = $(SRC:.c=.o )

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	libtool -static -o $(NAME) $(NAME) $(LIBS)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	gcc -Wall -Werror -Wextra -o $@ -c $<

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
