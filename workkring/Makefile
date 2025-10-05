# Nom de l'exécutable
NAME    = game

# Dossiers
SRC_DIR = srcs
INC_DIR = includes
OBJ_DIR = objs

# Fichiers sources et objets
SRCS    = $(wildcard $(SRC_DIR)/*.c)
OBJS    = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compilateur et options
CC      = gcc
CFLAGS  = -Wall -Wextra -I$(INC_DIR) -g

# Librairies (raylib + dépendances sous WSL/Linux)
LIBS    = -lraylib -lm -ldl -lpthread -lGL -lX11

# Règle par défaut
all: $(NAME)

# Link final
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LIBS)

# Compilation des .c -> .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Création du dossier objs si besoin
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Nettoyage
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
