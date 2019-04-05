# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lskrauci <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/16 13:04:01 by lskrauci      #+#    #+#                  #
#    Updated: 2019/02/16 13:04:03 by lskrauci      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ./srcs/ft_printf.c ./srcs/ft_node.c ./srcs/ft_format_fields.c \
./srcs/ft_print.c ./srcs/ft_print_f.c ./srcs/ft_print_support.c \
./srcs/ft_print_di.c ./srcs/ft_print_o.c ./srcs/ft_print_unum.c \
./srcs/ft_print_hex.c ./srcs/ft_print_ptr.c ./srcs/ft_wchar.c \
./srcs/ft_print_char.c ./srcs/ft_print_wstr.c ./srcs/ft_print_str.c \
./srcs/ft_print_hex2.c ./srcs/ft_print_f2.c ./srcs/ft_print_o2.c \
./srcs/ft_print_di2.c ./srcs/ft_format_fields2.c \

OBJECTS = ft_printf.o ft_node.o ft_format_fields.o \
ft_print.o ft_print_f.o ft_print_support.o \
ft_print_di.o ft_print_o.o ft_print_unum.o \
ft_print_hex.o ft_print_ptr.o ft_wchar.o ft_print_char.o \
ft_print_wstr.o ft_print_str.o ft_print_hex2.o \
ft_print_f2.o ft_print_o2.o ft_print_di2.o ./libft/*.o \
ft_format_fields2.o

HEADER = ./includes/

all: $(NAME)

$(NAME):
	make -C ./libft
	gcc -c $(SRCS) -I $(HEADER) -Wall -Wextra -Werror
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
clean:
	make -C ./libft/ clean
	rm -f *.o

fclean: clean
	make -C ./libft/ fclean
	rm -f $(NAME)

re: fclean all
