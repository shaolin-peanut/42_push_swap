# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 14:19:55 by ebennace          #+#    #+#              #
#    Updated: 2022/08/16 16:24:37 by sbars            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

SRCS		= 	./src/main.c \
				./src/processing.c \
				./src/operations.c \
				./src/operations_bis.c \
				./src/memory_utils.c \
				./src/list_utils.c \
				./src/small_algorithms.c \
				./src/algorithm.c \
				./src/descretize_stack.c \
				./src/utils.c \
				./src/utils2.c

OBJS			= $(SRCS:.c=.o)
CC				= clang
FLAGS 			= -g
SANITIZE		= -fsanitize=address

$(NAME) : 		$(OBJS)
				make -C libft
				$(CC) $(FLAGS) $(OBJS) libft/libft.a -o $(NAME)

all : 			$(NAME)

%.o: %.c
				$(CC) -c $(FLAGS) -o $@ $^

clean :
				make clean -C libft
				/bin/rm -rf $(OBJS)

fclean : clean
				make fclean -C libft
				/bin/rm -rf $(NAME)
sanitize : 		$(OBJS)
				$(CC) $(FLAGS) $(SANITIZE) $(OBJS) libft/libft.a -o $(NAME)
				./$(NAME) "6 -769 2 165"
				

test : 
				./$(NAME)  `python3 visualiser_generator/generator.py 0 1000 200`

lldb:
				$(CC) -g $(SRCS) libft/libft.a -o $(NAME)
				lldb $(NAME)

re : fclean all
.PHONY			: all clean fclean re
