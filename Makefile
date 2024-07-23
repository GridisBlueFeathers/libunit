# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 17:37:40 by svereten          #+#    #+#              #
#    Updated: 2024/07/23 16:42:40 by svereten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libunit.a

CC = cc

CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I./include

SRCS_DIR = src
OBJS_DIR = obj
RUNNERS_DIR = ../run
TESTS_DIR = ../tests

SRCS = asserts/assert_int_equal

OBJS = ${SRCS:%=${OBJS_DIR}/%.o}

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

runners: ${RUNNERS}

.PHONY: all clean fclean re
