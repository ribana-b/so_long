# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 15:47:45 by ribana-b          #+#    #+# Malaga       #
#    Updated: 2024/03/22 15:47:47 by ribana-b         ###   ########.com       #
#                                                                              #
# **************************************************************************** #

# ========================================================================== #

# <-- Color Library --> #

# <-- Text Color --> #
T_BLACK = \033[30m
T_RED = \033[31m
T_GREEN = \033[32m
T_YELLOW = \033[33m
T_BLUE = \033[34m
T_MAGENTA = \033[35m
T_CYAN = \033[36m
T_WHITE = \033[37m

# <-- Text Style --> #
BOLD = \033[1m
ITALIC = \033[2m
UNDERLINE = \033[3m
STRIKETHROUGH = \033[4m

# <-- Background Color --> #
B_BLACK = \033[40m
B_RED = \033[41m
B_GREEN = \033[42m
B_YELLOW = \033[43m
B_BLUE = \033[44m
B_MAGENTA = \033[45m
B_CYAN = \033[46m
B_WHITE = \033[47m

# <-- Reset Everything --> #
RESET = \033[0m

# ========================================================================== #

# <-- Library's Name --> #
NAME = libbfl.a

# <-- Compilation Command --> #
CC = cc

# <-- Compilation Flags --> #
ifdef WITH_DEBUG
CFLAGS = -Wall -Wextra -Werror -ggdb
else
CFLAGS = -Wall -Wextra -Werror
endif

# <-- Include Library -->#
INCLUDE = -I ./include

# <-- Remove Command -->#
RM = rm -rf

# <-- Directories --> #
BOOL_DIR = bool/
CHAR_DIR = char/
DATA_STRUCTURE_DIR = linked_list/
FD_DIR = fd/
FT_PRINTF_DIR = ft_printf/
GET_NEXT_LINE_DIR = get_next_line/
MATH_DIR = math/
MEMORY_DIR = memory/
STRING_DIR = string/
OBJ_DIR = obj/

# <-- Files --> #
BOOL_FILES = ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isblank.c \
				ft_isdigit.c \
				ft_islower.c \
				ft_isprint.c \
				ft_isupper.c \
				ft_isxdigit.c

CHAR_FILES = ft_tolower.c \
				ft_toupper.c

DATA_STRUCTURE_FILES = ll_create.c \
						ll_destroy.c

FD_FILES = ft_putaddress_fd.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_puthexl_fd.c \
			ft_puthexu_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_putunbr_fd.c

FT_PRINTF_FILES = ft_printf.c \
					ft_fprintf.c

GET_NEXT_LINE_FILES = get_next_line.c

MATH_FILES = ft_gcd.c \
			 ft_lcm.c \
			 ft_pow.c

MEMORY_FILES = ft_bzero.c \
				ft_calloc.c \
				ft_free.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c 

STRING_FILES = ft_atoi.c \
				ft_atol.c \
				ft_itoa.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_split.c \
				ft_splitlen.c \
				ft_strrchr.c \
				ft_substr.c

# <-- Directories + Files --> #
BOOL = $(addprefix $(BOOL_DIR), $(BOOL_FILES))
CHAR = $(addprefix $(CHAR_DIR), $(CHAR_FILES))
DATA_STRUCTURE = $(addprefix $(DATA_STRUCTURE_DIR), $(DATA_STRUCTURE_FILES))
FD = $(addprefix $(FD_DIR), $(FD_FILES))
FT_PRINTF = $(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_FILES))
GET_NEXT_LINE = $(addprefix $(GET_NEXT_LINE_DIR), $(GET_NEXT_LINE_FILES))
MATH = $(addprefix $(MATH_DIR), $(MATH_FILES))
MEMORY = $(addprefix $(MEMORY_DIR), $(MEMORY_FILES))
STRING = $(addprefix $(STRING_DIR), $(STRING_FILES))

# <-- Objects --> #
OBJ = $(patsubst $(BOOL_DIR)%.c, $(OBJ_DIR)%.o, $(BOOL)) \
		$(patsubst $(CHAR_DIR)%.c, $(OBJ_DIR)%.o, $(CHAR)) \
		$(patsubst $(DATA_STRUCTURE_DIR)%.c, $(OBJ_DIR)%.o, $(DATA_STRUCTURE)) \
		$(patsubst $(FD_DIR)%.c, $(OBJ_DIR)%.o, $(FD)) \
		$(patsubst $(FT_PRINTF_DIR)%.c, $(OBJ_DIR)%.o, $(FT_PRINTF)) \
		$(patsubst $(GET_NEXT_LINE_DIR)%.c, $(OBJ_DIR)%.o, $(GET_NEXT_LINE)) \
		$(patsubst $(MATH_DIR)%.c, $(OBJ_DIR)%.o, $(MATH)) \
		$(patsubst $(MEMORY_DIR)%.c, $(OBJ_DIR)%.o, $(MEMORY)) \
		$(patsubst $(STRING_DIR)%.c, $(OBJ_DIR)%.o, $(STRING)) \

# ========================================================================== #

# <-- Main Target --> #
all: $(NAME)

# <-- Library Creation --> #
$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "✅ 🦔 $(T_YELLOW)$(BOLD)Objects $(RESET)$(T_GREEN)created successfully$(RESET)"
	@ar rcs $@ $(OBJ)
	@echo "✅ 🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_GREEN)created successfully$(RESET)"

# <-- Object Directory Creation --> #
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# <-- Objects Creation --> #
$(OBJ_DIR)%.o: $(BOOL_DIR)%.c
	@echo "🧩 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "🔨 🦔 $(T_BLUE)$(BOLD)$@ $(RESET)$(T_GREEN)created!$(RESET)"

$(OBJ_DIR)%.o: $(CHAR_DIR)%.c
	@echo "🧩 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "🔨 🦔 $(T_BLUE)$(BOLD)$@ $(RESET)$(T_GREEN)created!$(RESET)"

$(OBJ_DIR)%.o: $(DATA_STRUCTURE_DIR)%.c
	@echo "🧩 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "🔨 🦔 $(T_BLUE)$(BOLD)$@ $(RESET)$(T_GREEN)created!$(RESET)"

$(OBJ_DIR)%.o: $(FD_DIR)%.c
	@echo "🧩 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "🔨 🦔 $(T_BLUE)$(BOLD)$@ $(RESET)$(T_GREEN)created!$(RESET)"

$(OBJ_DIR)%.o: $(FT_PRINTF_DIR)%.c
	@echo "🧩 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "🔨 🦔 $(T_BLUE)$(BOLD)$@ $(RESET)$(T_GREEN)created!$(RESET)"

$(OBJ_DIR)%.o: $(GET_NEXT_LINE_DIR)%.c
	@echo "🧩 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "🔨 🦔 $(T_BLUE)$(BOLD)$@ $(RESET)$(T_GREEN)created!$(RESET)"

$(OBJ_DIR)%.o: $(MATH_DIR)%.c
	@echo "🧩 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "🔨 🦔 $(T_BLUE)$(BOLD)$@ $(RESET)$(T_GREEN)created!$(RESET)"

$(OBJ_DIR)%.o: $(MEMORY_DIR)%.c
	@echo "🧩 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "🔨 🦔 $(T_BLUE)$(BOLD)$@ $(RESET)$(T_GREEN)created!$(RESET)"

$(OBJ_DIR)%.o: $(STRING_DIR)%.c
	@echo "🧩 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "🔨 🦔 $(T_BLUE)$(BOLD)$@ $(RESET)$(T_GREEN)created!$(RESET)"

# <-- Objects Destruction --> #
clean:
	@$(RM) $(OBJ_DIR)
	@echo "🗑️  🦔 $(T_YELLOW)$(BOLD)Objects $(RESET)$(T_RED)destroyed successfully$(RESET)"

# <-- Clean Execution + Library Destruction --> #
fclean: clean
	@$(RM) $(NAME)
	@echo "🗑️  🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_RED)destroyed successfully$(RESET)"

# <-- Fclean Execution + All Execution --> #
re: fclean all

# <-- Testers -->
test: all
	@$(CC) $(CFLAGS) $(INCLUDE) test/main_test.c $(NAME)
	@./a.out
	@rm ./a.out *.txt

# <-- Debug --> #
debug: fclean
	@make -s WITH_DEBUG=1

# <-- Targets Declaration --> #
.PHONY = all clean debug fclean re test

# ========================================================================== #
