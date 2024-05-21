# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 15:47:45 by ribana-b          #+#    #+# Malaga       #
#    Updated: 2024/05/21 13:25:46 by ribana-b         ###   ########.com       #
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

NAME = libBFL.a

CC = cc

ifdef WITH_DEBUG
CFLAGS = -Wall -Wextra -Werror -ggdb
else
CFLAGS = -Wall -Wextra -Werror
endif

INCLUDE = -I ./include

RM = rm -rf

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
				ft_memset.c \
				ft_realloc.c

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

BOOL = $(addprefix $(BOOL_DIR), $(BOOL_FILES))
CHAR = $(addprefix $(CHAR_DIR), $(CHAR_FILES))
DATA_STRUCTURE = $(addprefix $(DATA_STRUCTURE_DIR), $(DATA_STRUCTURE_FILES))
FD = $(addprefix $(FD_DIR), $(FD_FILES))
FT_PRINTF = $(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_FILES))
GET_NEXT_LINE = $(addprefix $(GET_NEXT_LINE_DIR), $(GET_NEXT_LINE_FILES))
MATH = $(addprefix $(MATH_DIR), $(MATH_FILES))
MEMORY = $(addprefix $(MEMORY_DIR), $(MEMORY_FILES))
STRING = $(addprefix $(STRING_DIR), $(STRING_FILES))

OBJ = $(patsubst $(BOOL_DIR)%.c, $(OBJ_DIR)%.o, $(BOOL)) \
		$(patsubst $(CHAR_DIR)%.c, $(OBJ_DIR)%.o, $(CHAR)) \
		$(patsubst $(DATA_STRUCTURE_DIR)%.c, $(OBJ_DIR)%.o, $(DATA_STRUCTURE)) \
		$(patsubst $(FD_DIR)%.c, $(OBJ_DIR)%.o, $(FD)) \
		$(patsubst $(FT_PRINTF_DIR)%.c, $(OBJ_DIR)%.o, $(FT_PRINTF)) \
		$(patsubst $(GET_NEXT_LINE_DIR)%.c, $(OBJ_DIR)%.o, $(GET_NEXT_LINE)) \
		$(patsubst $(MATH_DIR)%.c, $(OBJ_DIR)%.o, $(MATH)) \
		$(patsubst $(MEMORY_DIR)%.c, $(OBJ_DIR)%.o, $(MEMORY)) \
		$(patsubst $(STRING_DIR)%.c, $(OBJ_DIR)%.o, $(STRING)) \

COMPILE_MSG = @echo "$(CLEAR_LINE)🧩 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
OBJ_MSG = @echo "✅ 🦔 $(T_YELLOW)$(BOLD)Objects $(RESET)$(T_GREEN)created successfully!$(RESET)"
OUTPUT_MSG = @echo "✅ 🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_GREEN)created successfully!$(RESET)"
CLEAN_MSG = @echo "🗑️  🦔 $(T_YELLOW)$(BOLD)Objects $(RESET)$(T_RED)destroyed successfully!$(RESET)"
FCLEAN_MSG = @echo "🗑️  🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_RED)destroyed successfully!$(RESET)"

# @--------------------------------------------------------------------------@ #
# |                                 Targets                                  | #
# @--------------------------------------------------------------------------@ #

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(OBJ_MSG)
	@ar rcs $@ $(OBJ)
	$(OUTPUT_MSG)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(BOOL_DIR)%.c
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(CHAR_DIR)%.c
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(DATA_STRUCTURE_DIR)%.c
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(FD_DIR)%.c
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(FT_PRINTF_DIR)%.c
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(GET_NEXT_LINE_DIR)%.c
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(MATH_DIR)%.c
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(MEMORY_DIR)%.c
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(STRING_DIR)%.c
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	$(CLEAN_MSG)

fclean: clean
	@$(RM) $(NAME)
	$(FCLEAN_MSG)

re:
	@make -s fclean
	@echo
	@make -s all

debug: fclean
	@make -s WITH_DEBUG=1

.PHONY: all clean debug fclean re
