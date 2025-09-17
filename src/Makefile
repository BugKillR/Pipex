NAME	= pipex.a

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

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re