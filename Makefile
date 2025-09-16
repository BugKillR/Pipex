NAME	= pipex.a
EXE		= pipex

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

#	----- Libft -----	#

LIBFT_DIR	= ./Libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS	= pipex.c \
			heredoc.c \
			classic.c \
			all_paths_from_envp.c \
			find_pathname_for_command.c \
			execve_setup.c \
			free.c

OBJS	= $(SRCS:.c=.o)

all: $(EXE)

$(EXE): $(NAME)
	$(CC) $(CFLAGS) -g main.c $(NAME) $(LIBFT) -o pipex

$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME) $(EXE)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re