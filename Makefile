# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 20:41:52 by jberredj          #+#    #+#              #
#    Updated: 2021/01/04 20:48:36 by jberredj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
CC			=	clang
CFLAGS		=	-Wall -Werror -Wextra

INCLUDES	=	-I includes/ -I libs/libft/includes/
PARSER		=	main_parser.c flag_parser.c width_parser.c precision_parser.c length_parser.c type_parser.c

MODULE		=	parser

LIBS		=	libft

all: $(NAME)

$(NAME): $(LIBS) $(MODULE) lib

parser: objs libft
	echo "Compiling Parser functions"
	$(CC) $(INCLUDES) -c $(addprefix srcs/parser/, $(PARSER)) $(CFLAGS)
	mv *.o objs/

libft: objs
	echo "Compiling libft"
	cd libs/libft && make ft_string lib
	mv libs/libft/libft.a objs/libft.a
	ar x objs/libft.a
	rm objs/libft.a

lib:
	echo "Creating $(NAME)"
	ar cr $(NAME) objs/*.o

objs:
	mkdir -p objs

clean:
	echo "Cleaning objects in objs and delete objs/"
	rm -f *.o
	rm -rf objs
	cd libs/libft && make clean

fclean:
	echo "Deleting $(NAME)"
	rm -f $(NAME)
	make clean
	cd libs/libft && make fclean

re:
	make fclean
	make all
.SILENT:

