# Répertoire principal
PUSH_DIR = .

# Répertoire pour la bibliothèque libft
LIBFT_DIR = $(PUSH_DIR)/libft

# Nom de l'exécutable à générer
PUSH_SWAP = push_swap

# Fichiers sources
SRCS = pushes.c stack_init.c swaps.c rotates.c rev_rotates.c sort_small_stack.c main.c checks.c memory.c sort_large_stack.c

# Fichiers objets
OBJS = $(SRCS:.c=.o)

# Bibliothèque libft
LIBFT = $(LIBFT_DIR)/libft.a

# Options de compilation
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR) -g
LDFLAGS = -L$(LIBFT_DIR)
LDLIBS = -lft

# Compilateur
CC = gcc

# Règles de compilation
all: $(LIBFT) $(PUSH_SWAP)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PUSH_SWAP): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

# Compilation des fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(PUSH_SWAP)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

