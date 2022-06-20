DIR_OBJ =./build
SRC = ${addprefix src/, main.c \
	  error.c}
OBJ=${addprefix ${DIR_OBJ}/, ${notdir${SRC:.c=.o}}}
HEAD = src/push_swap.h
NAME = push_swap
CFLAGS = -Wall -Werror -Wextra 
OFLAGS = -fsanitize=address -g3
CC = gcc

all:	${NAME}

$(NAME):	${OBJ} ${HEAD}
	${CC} ${OFLAGS} ${OBJ} ${HEAD} -o ${NAME}

${DIR_OBJ}/%.o : %.c | ${DIR_OBJ}
	${CC} ${CFLAGS} -c $< -o $@

${DIR_OBJ} :
	mkdir -p ${DIR_OBJ}

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

lldb: ${OBJ}
	${CC} ${SRC} -g -o ${NAME}
	lldb ${NAME}

norm:
	norminette ${SRC} ${HEAD}

.PHONY: all fclean clean re
