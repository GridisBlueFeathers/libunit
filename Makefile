# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 17:37:40 by svereten          #+#    #+#              #
#    Updated: 2024/08/29 15:48:51 by svereten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libunit.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -g
INCLUDE = -I./include -I./libft/include
PROJECT_INCLUDE = -I../include

SRCS_DIR = src
OBJS_DIR = obj
LIBFT_DIR = libft
RUNNERS_DIR = ../run
TESTS_DIR = ../tests

SRCS = assert/assert \
	   assert/int/asserts/equal \
	   assert/int/data_dup \
	   assert/str_arr/asserts/equal \
	   assert/str_arr/data_dup \
	   assert/assert_state \
	   assert/assert_node \
	   assert/assert_state_list \
	   test/test \
	   group/group \
	   group/groups \
	   group/groups_state \
	   group/group_test \
	   start_up \
	   teardown \

PROJECT_OBJS = ${filter-out ../obj/dev/dev.o ../obj/main.o, ${patsubst ../src/%.c, ../obj/%.o, ${shell find ../src/ -type f -name "*.c"}}}
TESTS_OBJS = ${patsubst ../tests/%.c, ../obj/%.o, ${wildcard ../tests/*.c}}

OBJS = ${SRCS:%=${OBJS_DIR}/%.o}

OBJ_DIRS = ${sort ${dir ${OBJS}}}
PROJECT_OBJS_DIRS = ${sort ${dir ${PROJECT_OBJS}}}
RUNNERS_DIRS = ${sort ${dir ${patsubst ../tests/%.c, ../run/%, ${shell find ../tests/ -type f -name "*.c"}}}}

LIBFT = ${LIBFT_DIR}/libft.a

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
	${MAKE} re -C ${LIBFT_DIR}

${LIBFT}:
	${MAKE} -C ${LIBFT_DIR}

../obj/%_tests.o: ${TESTS_DIR}/%_tests.c | ../obj
	${CC} ${CFLAGS} ${INCLUDE} ${PROJECT_INCLUDE} -c $< -o $@

../obj/%.o:
	${MAKE} -C ../ obj/$*.o

${RUNNERS_DIR}/%: ../obj/%.o ${PROJECT_OBJS} ${NAME} ${LIBFT} | ${RUNNERS_DIRS}
	${CC} ${CFLAGS} ${PROJECT_INCLUDE} ${INCLUDE} $^ -o $@
	
${RUNNERS_DIRS}:
	mkdir -p $@

${PROJECT_OBJS_DIRS}:
	mkdir -p $@

print:
	@echo ${RUNNERS_DIR}

.PHONY: all clean fclean re
