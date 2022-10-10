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

RM 		=	rm -rf

NAME	=	fractol

MLX_F	=	-lXext -lm -lX11 -lz

MLX_D	=	./minilibx-linux

MLX		=	$(addprefix $(MLX_D)/, libmlx.a)	

FILES	=	events \
	fractals \
	main \
	messages \
	window \

INCS_D	=	./incs

SRCS_D	=	./srcs

SRCS	=	$(addprefix $(SRCS_D)/, $(addsuffix .c, $(FILES)))
OBJS 	=	$(addprefix $(SRCS_D)/, $(addsuffix .o, $(FILES)))

.c.o:	$(SRCS) $(INCS_D)
	${CC} ${CFLAGS} -c $< -o $@ -I$(INCS_D)

all:		${NAME}

${NAME}:	$(MLX) $(OBJS)
				$(CC) $^ -o $@ -I$(INCS_D) -lmlx -L$(MLX_D) $(MLX_F)

$(MLX):
	make -C $(MLX_D)

clean:
				${RM} $(OBJS)

fclean:		clean
				${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean c.o re
