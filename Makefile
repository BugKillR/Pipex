NAME	= pipex.a
EXE		= pipex

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

#	----- Libft -----	#

LIBFT_DIR	= ./Libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS	= pipex.c

OBJS	= $(SRCS:.c=.o)

all: $(EXE)

$(EXE): $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME) $(LIBFT) -o pipex

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