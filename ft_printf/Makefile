# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/25 17:31:13 by cdubuque          #+#    #+#              #
#    Updated: 2019/07/16 17:55:58 by cdubuque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_int.c ft_string_and_char.c unsigned.c 

SRCLIB = libft/*.o

FLAGS = -Wall -Wextra -Werror

HEADER = libftprintf.h

OBJC = $(SRC:.c=.o)

LIBFT = libft/

$(NAME):	
	make -C $(LIBFT)	
	gcc -c $(FLAGS) $(SRC) -I $(HEADER) -I./libft/includes/libft.h
	ar rc $(NAME) $(OBJC)

all: $(NAME)
clean:
	/bin/rm -f $(OBJC)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
