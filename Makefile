# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 20:41:52 by jberredj          #+#    #+#              #
#    Updated: 2021/01/26 11:06:44 by jberredj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
CC				=	clang
CFLAGS			=	-Wall -Werror -Wextra -g
BUFFER_SIZE		=	64

HEADERS			=	includes/

PARSER			=	main_parser.c flag_parser.c width_parser.c precision_parser.c type_parser.c length_parser.c
	
CHECKER			=	check_parser.c c_type_illegal.c s_type_illegal.c p_type_illegal.c d_i_type_illegal.c \
					u_type_illegal.c n_type_illegal.c x_type_illegal.c flag_illegal.c

CONVERTER		=	convert_int.c convert_int_utils.c process_width.c copy_printed_char.c convert_char.c convert_str.c \
					convert_hex.c

PRINTER			=	ft_printf.c clear_flags.c buffer.c

MODULE			=	parser checker converter printer

LIBS			=	libft

BONUS			=	-D BONUS=1

all: $(NAME)

$(NAME): $(LIBS) $(MODULE) lib

bonus: all

parser: objs libft.a
	echo "Compiling Parser functions"
	$(CC) -I $(HEADERS) -c $(addprefix srcs/parser/, $(PARSER)) $(CFLAGS) $(BONUS)
	mv *.o objs/

checker: objs libft.a
	echo "Compiling Checker functions"
	$(CC) -I $(HEADERS) -c $(addprefix srcs/check_parser/, $(CHECKER)) $(CFLAGS) $(BONUS)
	mv *.o objs/

converter: objs libft.a
	echo "Compiling Converter functions"
	$(CC) -I $(HEADERS) -c $(addprefix srcs/converter/, $(CONVERTER)) $(CFLAGS) $(BONUS)
	mv *.o objs/

printer: objs libft.a
	echo "Compiling Printer functions"
	$(CC) -I $(HEADERS) -c $(addprefix srcs/, $(PRINTER)) $(CFLAGS) $(BONUS) -D BUFFER_SIZE=$(BUFFER_SIZE)
	mv *.o objs/

libft.a: 
	echo "Compiling libft"
	make -C libft ft_string ft_to ft_ctype lib
	cp libft/libft.a libft.a
	cp libft.a $(NAME)

lib:
	echo "Creating $(NAME)"
	ar cr $(NAME) objs/*.o

debug: CFLAGS	= -Wall -Wextra -g
debug:
	echo "COMPILING DEBUG EXECUTABLE"
	$(CC) -I $(HEADERS) -g main_parser_test.c $(NAME) -o debug.out
objs:
	mkdir -p objs

clean:
	echo "Cleaning objects in objs and delete objs/"
	rm -rf libft.a
	rm -rf *.o
	rm -rf objs
	make -C libft clean

fclean:
	echo "Deleting $(NAME)"
	rm -rf $(NAME)
	make clean
	make -C libft fclean

re:
	make fclean
	make all
.SILENT:

