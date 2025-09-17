EXE     = pipex

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

# ----- Libft ----- #

LIBFT_DIR   = ./Libft
LIBFT       = $(LIBFT_DIR)/libft.a

# ----- GNL ----- #

GNL_DIR     = ./get_next_line
GNL         = $(GNL_DIR)/get_next_line.a

# ----- Source Code ----- #

SRC_DIR     = ./src
SRC_LIB     = $(SRC_DIR)/pipex.a

all: $(EXE)

$(EXE): $(SRC_LIB) $(GNL) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_DIR)/main.c $(SRC_LIB) $(GNL) $(LIBFT) -o $(EXE)

$(SRC_LIB):
	make -C $(SRC_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(GNL):
	make -C $(GNL_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean
	make -C $(SRC_DIR) clean

fclean: clean
	rm -f $(EXE)
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean
	make -C $(SRC_DIR) fclean

re: fclean all

.PHONY: all clean fclean re