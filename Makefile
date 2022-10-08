# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 10:39:10 by hkhater           #+#    #+#              #
#    Updated: 2022/10/08 10:39:17 by hkhater          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		=	cc

CFLAGS	=	-Wall -Werror -Wextra

MFLAGS	=	-lXext -lm -lX11 -lz

RM 		=	rm -rf

NAME	=	fractol

INC		=	fractol.h

SRCS	=	./*.c

OBJS 	=	${SRCS:.c=.o}

.c.o:
		${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

${NAME}:	$(OBJS)
				$(CC) $(FLAGS) $(OBJS) -o $(NAME) -I$(INC)

all:		${NAME}

clean:
				${RM} $(OBJS)

fclean:		clean
				${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean c.o re
