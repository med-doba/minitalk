# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 19:08:16 by med-doba          #+#    #+#              #
#    Updated: 2021/12/21 12:12:08 by med-doba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HDR = ft_printf.h

FCT = ft_hexa.c	ft_printf.c	ft_putnbr.c	ft_length.c ft_putchar.c ft_putstr.c ft_putnbrun.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJ = $(FCT:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar -rc $(NAME) $(OBJ)

%.o : %.c $(HDR)
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
