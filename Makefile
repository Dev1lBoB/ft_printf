# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 11:28:16 by wpersimm          #+#    #+#              #
#    Updated: 2020/11/20 17:23:22 by wpersimm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_printf.c \
			  ft_func1.c \
			  ft_func2.c \
			  ft_func3.c \
			  ft_func4.c \
			  ft_func5.c \
			  ft_func6.c \
			  ft_func7.c \
			  ft_func8.c \
			  ft_func9.c \

OBJS		= ${SRCS:.c=.o}

HEAD		= ft_printf.h

LIBM		= make -C ${LIB}

LIBH		= libft/libft.h

LIBA		= ./libft/libft.a

LIB			= ./libft

LOBJS		= ./libft/ft_atoi.o \
			  ./libft/ft_strlen.o \
			  ./libft/ft_isdigit.o \
			  ./libft/ft_putchar_fd.o \
			  ./libft/ft_putnbr_fd.o \
			  ./libft/ft_putstr_fd.o \

LIBC		= make clean -C ${LIB}

LIBFC		= make fclean -C ${LIB}

GCC			= gcc -Wall -Wextra -Werror -c

all:		${NAME}

${LIBA}:
			${LIBM}

${NAME}:	${LIBA} ${LOBJS} ${OBJS} ${HEAD}
			${GCC} ${SRCS}
			ar rc ${NAME} ${OBJS} ${LOBJS}
			ar rc ${NAME} ${LIBH} ${HEAD}

clean:
			rm -f ${OBJS}
			${LIBC}

fclean:		clean
			rm -f ${NAME}
			${LIBFC}

re:			fclean all
