NAME	= pipex.a
EXE		= pipex

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

#	----- Libft -----	#

LIBFT_DIR	= ./Libft
LIBFT		= $(LIBFT_DIR)/libft.a

#	----- GNL ----- #

GNL_DIR		= ./get_next_line
GNL			= $(GNL_DIR)/get_next_line.a

SRCS	= pipex.c \
			heredoc.c \
			classic.c \
			all_paths_from_envp.c \
			find_pathname_for_command.c \
			execve_setup.c \
			free.c \
			flag_separator.c \
			execute_command.c \
			inputfile_to_pipe.c \
			decide_inputfile_heredoc_or_classic.c \
			decide_outputfile_settings.c

OBJS	= $(SRCS:.c=.o)

all: $(EXE)

$(EXE): $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME) $(GNL) $(LIBFT) -o pipex

$(NAME): $(OBJS) $(GNL) $(LIBFT)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(GNL):
	make -C $(GNL_DIR)

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean

fclean: clean
	rm -rf $(NAME) $(EXE)
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all clean fclean re