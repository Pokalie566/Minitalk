CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

INC_DIR = includes
INCS = -I ./$(INC_DIR) -I lib/libft/$(INC_DIR) -I lib/ft_printf/$(INC_DIR)

LIBFT_DIR := lib/libft
LIBFT := $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR := lib/ft_printf
FT_PRINTF := $(FT_PRINTF_DIR)/libftprintf.a

SRC_PATH = src/
OBJ_PATH = obj/

# Couleurs pour les messages
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
BLUE = \033[38;2;15;101;214m
RESET = \033[0m

SERVER = server
CLIENT = client

SERVER_Bonus = server_bonus
CLIENT_Bonus = client_bonus

SV_SRCS = $(SRC_PATH)server.c
CLIENT_SRCS = $(SRC_PATH)client.c

SV_OBJS = $(OBJ_PATH)server.o
CLIENT_OBJS = $(OBJ_PATH)client.o

# Bonus Sources
SV_SRCS_Bonus = $(SRC_PATH)server_bonus.c
CLIENT_SRCS_Bonus = $(SRC_PATH)client_bonus.c

SV_OBJS_Bonus = $(OBJ_PATH)server_bonus.o
CLIENT_OBJS_Bonus = $(OBJ_PATH)client_bonus.o

# Default target
all: $(SERVER) $(CLIENT)
	@echo "$(BLUE)=== Compilation terminée ==="
	@echo " █████╗ ██╗     ██╗     "
	@echo "██╔══██╗██║     ██║     "
	@echo "███████║██║     ██║     "
	@echo "██╔══██║██║     ██║     "
	@echo "██║  ██║███████╗███████╗"
	@echo "╚═╝  ╚═╝╚══════╝╚══════╝"
	@echo "$(RESET)"

# Bonus target
bonus: $(CLIENT_Bonus) $(SERVER_Bonus)
	@echo "$(BLUE)=== Compilation terminée ==="
	@echo " _														"
	@echo "|_|_ _        _ _       _ _ _       _     _      _ _ _   "
	@echo "|_|_|_|_    _|_|_|_    |_|_|_|     |_|   |_|   _|_|_|_|	"
	@echo "|_|    _|  |_|   |_|  |_|   |_|    |_|   |_|  |_|_| _    "
	@echo "|_|_ _ _|  |_|_ _|_|  |_|   |_|    |_| _ |_|  _ _|_|_|	"
	@echo "|_|_|_|      |_|_|    |_|   |_|     |_|_|_|  |_|_|_|		"
	@echo "															"
	@echo "$(RESET)"

# Library rules
$(LIBFT):
	make --no-print-directory -C $(LIBFT_DIR) -s -j all
	
$(FT_PRINTF):
	make --no-print-directory -C $(FT_PRINTF_DIR) -s -j all

# Client and Server compilation
$(CLIENT): $(CLIENT_OBJS) $(FT_PRINTF) $(LIBFT) 
	$(CC) $(CFLAGS) $(INCS) $^ -o $@

$(SERVER): $(SV_OBJS) $(FT_PRINTF) $(LIBFT) 
	$(CC) $(CFLAGS) $(INCS) $^ -o $@

# Bonus compilation
$(CLIENT_Bonus): $(CLIENT_OBJS_Bonus) $(FT_PRINTF) $(LIBFT)
	@echo "Compiling client bonus..."
	$(CC) $(CFLAGS) $(INCS) $^ -o $@
	@echo "Client bonus compiled!"

$(SERVER_Bonus): $(SV_OBJS_Bonus) $(FT_PRINTF) $(LIBFT)
	@echo "Compiling server bonus..."
	$(CC) $(CFLAGS) $(INCS) $^ -o $@
	@echo "Server bonus compiled!"

# Object compilation
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

# Clean up object files
clean:
	@echo "$(RED)"
	make --no-print-directory -C $(LIBFT_DIR) -s -j clean
	make --no-print-directory -C $(FT_PRINTF_DIR) -s -j clean
	$(RM) $(SV_OBJS) $(CLIENT_OBJS) $(CLIENT_OBJS_Bonus) $(SV_OBJS_Bonus)
	$(RM) $(OBJ_PATH)
	@echo "$(RED)"
	@echo " ▄▄· ▄▄▌  ▄▄▄ . ▄▄▄·  ▐ ▄ "
	@echo "▐█ ▌▪██•  ▀▄.▀·▐█ ▀█ •█▌▐█"
	@echo "██ ▄▄██▪  ▐▀▀▪▄▄█▀▀█ ▐█▐▐▌"
	@echo "▐███▌▐█▌▐▌▐█▄▄▌▐█ ▪▐▌██▐█▌"
	@echo "·▀▀▀ .▀▀▀  ▀▀▀  ▀  ▀ ▀▀ █▪"
	@echo "$(RESET)"

# Full clean including executables
fclean: clean
	@echo "$(RED)=== Suppression de l'exécutable... ==="
	make --no-print-directory -C $(LIBFT_DIR) -s -j fclean
	make --no-print-directory -C $(FT_PRINTF_DIR) -s -j fclean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)
	$(RM) $(SERVER_Bonus)
	$(RM) $(CLIENT_Bonus)
	@echo "$(RED)"
	@echo "░       ░░░░      ░░░  ░░░░░░░░        ░░░      ░░░   ░░░  ░"
	@echo "▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒    ▒▒  ▒"
	@echo "▓      ▓▓▓▓  ▓▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓▓      ▓▓▓▓  ▓▓▓▓  ▓▓  ▓  ▓  ▓"
	@echo "█  ████████  ████  ██  ████████  ████████        ██  ██    █"
	@echo "█  █████████      ███       ███       ███  ████  ██  ███   █"
	@echo "$(RESET)"

# Rebuild all from scratch
re: fclean all
	@echo "$(GREEN)=== Réinitialisation terminée ==="
	@echo "░▒▓███████▓▒░░▒▓████████▓▒░"
	@echo "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░░░░░░░"
	@echo "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░░░░░░░"
	@echo "░▒▓███████▓▒░░▒▓██████▓▒░░░"
	@echo "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░░░░░░░"
	@echo "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░░░░░░░" 
	@echo "░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░"
	@echo "$(RESET)"

.PHONY: all clean fclean re bonus

