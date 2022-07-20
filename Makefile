NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

AR = ar -rc

SRCS_DIR = ./src

OBJS_DIR = ./objs
INC_DIR = .
LIBFT_DIR = ./libft
LIBFT = libft.a

SRCS = main.c \
		processing.c \
		operations.c \
		operations_bis.c \
		memory_utils.c \
		list_utils.c \
		small_algorithms.c \
		utils.c

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c $(SRCS_DIR)

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	echo "Compling libft..."
	@$(MAKE) -C $(LIBFT_DIR)
	echo "Libft has been compiled..."
	echo "Compiling push_swap"
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft
	echo "push_swap has been compiled..."

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -I $(INC_DIR) -I$(LIBFT_DIR) -c $^

clean :
	@$(MAKE) -C $(LIBFT_DIR) fclean
	#@$(MAKE) -C fclean
	@$(RM) -r $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all
