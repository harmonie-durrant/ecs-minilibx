# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harmonie <rbryento@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 18:26:47 by harmonie          #+#    #+#              #
#    Updated: 2024/09/13 23:49:27 by harmonie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_BASE	=	put.c								\
				ecs/entity/init_entity.c			\
				ecs/entity/print_entity.c			\
				ecs/entity/handle_entity.c			\
				ecs/entity/update_entity.c			\
				ecs/component/init_component.c		\
				ecs/component/print_component.c		\
				ecs/component/handle_component.c	\

SRC	:= $(addprefix src/, $(SRC_BASE))

OBJ	=	$(SRC:.c=.o)

NAME	=	libecs.a

CFLAGS	=	-Wall -Werror -Wextra -I./include -I./minilibx-linux

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all