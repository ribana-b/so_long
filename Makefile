# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 15:52:12 by ribana-b          #+#    #+# Malaga       #
#    Updated: 2024/05/21 13:22:31 by ribana-b         ###   ########.com       #
#                                                                              #
# **************************************************************************** #


# @--------------------------------------------------------------------------@ #
# |                                 Colors                                   | #
# @--------------------------------------------------------------------------@ #

T_BLACK = \033[30m
T_RED = \033[31m
T_GREEN = \033[32m
T_YELLOW = \033[33m
T_BLUE = \033[34m
T_MAGENTA = \033[35m
T_CYAN = \033[36m
T_WHITE = \033[37m

BOLD = \033[1m
ITALIC = \033[2m
UNDERLINE = \033[3m
STRIKETHROUGH = \033[4m

CLEAR_LINE = \033[1F\r\033[2K

RESET = \033[0m

# @--------------------------------------------------------------------------@ #
# |                                 Macros                                   | #
# @--------------------------------------------------------------------------@ #

NAME = so_long 

CC = cc

ifdef WITH_DEBUG
	CFLAGS = -Wall -Wextra -Werror -ggdb
else
	CFLAGS = -Wall -Wextra -Werror
endif

CPPFLAGS = -I./$(INCLUDE_DIR) -I$(BFL_DIR)include -I$(MLX42_DIR)include/MLX42
LDFLAGS = -L./$(BFL_DIR) -L./$(MLX42_DIR)
LDLIBS = -lBFL -lmlx42 -ldl -lglfw -pthread -lm

RM = rm -rf

INCLUDE_DIR = ./include/
BFL_DIR = $(INCLUDE_DIR)BFL/
MLX42_DIR = $(INCLUDE_DIR)MLX42/
SRC_DIR = src/
PARSER_DIR = $(SRC_DIR)parser/
TEXTURE_DIR = $(SRC_DIR)texture/
UTILS_DIR = $(SRC_DIR)utils/
OBJ_DIR = obj/
BIN_DIR = bin/

DEBUG_DIR = src/debug/

SRC_FILES = main.c
UTILS_FILES := fill_map.c \
				ft_exit.c \
				manage_file.c \
				ft_random.c \
				movement.c \
				handler.c \
				game_logic.c
PARSER_FILES = parse_line.c \
				parse_map.c \
				parse_name.c
TEXTURE_FILES = get_texture_path.c \
				open_textures.c \
				load_textures.c \
				draw_textures.c \
				reload_textures.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
UTILS = $(addprefix $(UTILS_DIR), $(UTILS_FILES))
PARSER = $(addprefix $(PARSER_DIR), $(PARSER_FILES))
TEXTURE = $(addprefix $(TEXTURE_DIR), $(TEXTURE_FILES))

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC)) \
		$(patsubst $(UTILS_DIR)%.c, $(OBJ_DIR)%.o, $(UTILS)) \
		$(patsubst $(PARSER_DIR)%.c, $(OBJ_DIR)%.o, $(PARSER)) \
		$(patsubst $(TEXTURE_DIR)%.c, $(OBJ_DIR)%.o, $(TEXTURE)) \

COMPILE_MSG = @echo "$(CLEAR_LINE)🧩 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
OBJ_MSG = @echo "✅ 🦔 $(T_YELLOW)$(BOLD)Objects $(RESET)$(T_GREEN)created successfully!$(RESET)"
OUTPUT_MSG = @echo "✅ 🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_GREEN)created successfully!$(RESET)"
CLEAN_MSG = @echo "🗑️  🦔 $(T_YELLOW)$(BOLD)Objects $(RESET)$(T_RED)destroyed successfully!$(RESET)"
FCLEAN_MSG = @echo "🗑️  🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_RED)destroyed successfully!$(RESET)"

# @--------------------------------------------------------------------------@ #
# |                                 Targets                                  | #
# @--------------------------------------------------------------------------@ #

all: $(BIN_DIR) $(BIN_DIR)$(NAME)

ifdef WITH_DEBUG
$(BIN_DIR)$(NAME): $(MLX42_DIR) $(OBJ_DIR) $(OBJ)
	@make -s debug -C $(BFL_DIR)
	@make -s -C $(MLX42_DIR)
	$(OBJ_MSG)
	@$(CC) -o $@ $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	$(OUTPUT_MSG)
else
$(BIN_DIR)$(NAME): $(MLX42_DIR) $(OBJ_DIR) $(OBJ)
	@make -s -C $(BFL_DIR)
	@make -s -C $(MLX42_DIR)
	$(OBJ_MSG)
	@$(CC) -o $@ $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	$(OUTPUT_MSG)
endif

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(MLX42_DIR):
	@git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_DIR) > /dev/null 2>&1
	@cd $(MLX42_DIR) && git checkout da6e420 > /dev/null 2>&1

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(UTILS_DIR)%.c
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(PARSER_DIR)%.c
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(TEXTURE_DIR)%.c
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@if [ -d $(MLX42_DIR) ]; then \
		make clean -s -C $(MLX42_DIR); \
	fi
	@make clean -s -C $(BFL_DIR)
	$(CLEAN_MSG)

fclean: clean
	@$(RM) $(BIN_DIR) tags
	@if [ -d $(MLX42_DIR) ]; then \
		make fclean -s -C $(MLX42_DIR); \
	fi
	@make fclean -s -C $(BFL_DIR)
	$(FCLEAN_MSG)

re:
	@make -s fclean
	@echo
	@make -s all

debug:
	@make -s WITH_DEBUG=1

tags:
	@$(shell find . -path ./bonus_part -prune -o -print -type f \( -name "*c" -o -name "*.h" \) > temp)
	@ctags -F $(shell cat temp)
	@$(RM) temp

bonus:
	@make -s -C bonus_part

.PHONY = all bonus clean debug fclean re tags

# ========================================================================== #
