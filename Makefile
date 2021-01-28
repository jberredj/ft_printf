# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 20:41:52 by jberredj          #+#    #+#              #
#    Updated: 2021/01/28 13:21:35 by jberredj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
CC				=	clang
CFLAGS			=	-Wall -Werror -Wextra
BUFFER_SIZE		=	64

HEADERS			=	includes/

PARSER			=	main_parser.c flag_parser.c width_parser.c precision_parser.c type_parser.c length_parser.c
	
CHECKER			=	check_parser.c c_type_illegal.c s_type_illegal.c p_type_illegal.c d_i_type_illegal.c \
					u_type_illegal.c n_type_illegal.c x_type_illegal.c flag_illegal.c

CONVERTER		=	convert_int.c convert_int_utils.c process_width.c copy_printed_char.c convert_char.c convert_str.c \
					convert_hex.c

PRINTER			=	ft_printf.c clear_flags.c buffer.c

MINILIBFT		=	check_base.c ft_atoi.c ft_bzero.c ft_calloc.c ft_intlen.c ft_isdigit.c \
					ft_isspace.c ft_lllen.c ft_lltoa.c ft_memset.c ft_strlcpy.c ft_strlen.c \
					ft_substr.c ft_ulllen_base.c ft_ulllen.c ft_ulltoa_base.c ft_ulltoa.c

MODULE			=	parser checker converter printer

all: $(NAME)

bonus: all

$(NAME): minilibft $(MODULE) lib

parser: objs
	$(CC) -I $(HEADERS) -c $(addprefix srcs/parser/, $(PARSER)) $(CFLAGS)
	mv *.o objs/

checker: objs
	$(CC) -I $(HEADERS) -c $(addprefix srcs/check_parser/, $(CHECKER)) $(CFLAGS)
	mv *.o objs/

converter: objs
	$(CC) -I $(HEADERS) -c $(addprefix srcs/converter/, $(CONVERTER)) $(CFLAGS)
	mv *.o objs/

printer: objs
	$(CC) -I $(HEADERS) -c $(addprefix srcs/, $(PRINTER)) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE)
	mv *.o objs/

minilibft: objs
	$(CC) -I $(HEADERS) -c $(addprefix srcs/minilibft/, $(MINILIBFT)) $(CFLAGS)
	mv *.o objs/

lib:
	ar cr $(NAME) objs/*.o

objs:
	mkdir -p objs

clean:
	rm -rf *.o
	rm -rf objs

fclean:
	rm -rf $(NAME)
	make clean

re:
	make fclean
	make all

