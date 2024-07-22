# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 17:37:40 by svereten          #+#    #+#              #
#    Updated: 2024/07/22 18:03:15 by svereten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libunit.a

CC = cc

CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I./include

SRCS_DIR = src
OBJS_DIR = obj

FILES = asserts/assert_int_equal

SRCS = ${FILES:%=${SRCS_DIR}/%.c}
OBJS = ${FILES:%=${OBJS_DIR}/%.o}

OBJ_DIRS = ${sort ${dir ${OBJS}}}

AR = ar -rsc

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJ_DIRS}
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@ 

${OBJ_DIRS}:
	mkdir -p $@

clean:
	rm -rf ${OBJS_DIR}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
