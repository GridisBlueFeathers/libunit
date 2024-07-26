# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 17:37:40 by svereten          #+#    #+#              #
#    Updated: 2024/07/26 02:01:34 by svereten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libunit.a

CC = cc

CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I./include -I./libft/include
PROJECT_INCLUDE = -I../include

SRCS_DIR = src
OBJS_DIR = obj
RUNNERS_DIR = ../run
TESTS_DIR = ../tests

SRCS = asserts/assert_int_equal

PROJECT_OBJS = ${filter-out ../obj/main.o, ${patsubst ../src/%.c, ../obj/%.o, ${wildcard ../src/*.c}}}
TESTS_OBJS = ${patsubst ../tests/%.c, ../obj/%.o, ${wildcard ../tests/*.c}}

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

../obj/%_tests.o: ${TESTS_DIR}/%_tests.c | ../obj
	${CC} ${CFLAGS} ${INCLUDE} ${PROJECT_INCLUDE} -c $< -o $@

../obj/%.o:
	${MAKE} -C ../ obj/$*.o

${RUNNERS_DIR}/%: ../obj/%.o ${PROJECT_OBJS} ${NAME} | ${RUNNERS_DIR}
	${CC} ${CFLAGS} ${PROJECT_INCLUDE} ${INCLUDE} $^ -o $@
	
${RUNNERS_DIR}:
	mkdir -p $@

../obj:
	mkdir -p $@

print:
	@echo ${PROJECT_OBJS} ${TESTS_OBJS}

#${RUNNERS_DIR}/%: ${TESTS_DIR}
runners:
	@echo ${MAKECMDGOALS}

.PHONY: all clean fclean re
