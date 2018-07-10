#!/usr/bin/make -f

################################################################################
# SETTINGS                                                                     #
################################################################################

NAME = libft_memmgr.a
CC = gcc
CFLAGS += -Wall -Werror -Wextra
CFLAGS += -Ofast
CFLAGS += #-g -fsanitize=address
INC = -I inc
SRC_DIR = src
OBJ_DIR = obj

# [ BASE ]

SRC = \
	ft_mchain\
	ft_mladd\
	ft_mlalloc\
	ft_mlappend\
	ft_mlarray\
	ft_mldel\
	ft_mlfind\
	ft_mlpop\
	ft_mlremove\
	ft_mlrev\
	ft_mlxfer\

# [ LIBFT ]

SRC += \
	ft_memalloc\
	ft_memdel\
	ft_memset\
	ft_stpcpy\
	ft_stpncpy\
	ft_strcmp

OBJ = $(patsubst %, $(OBJ_DIR)/%.o, $(SRC))

################################################################################
# COLORS                                                                       #
################################################################################

NC = \033[0m
GREEN = \033[1;32m
RED = \033[1;31m
YELLOW = \033[1;33m

################################################################################
# RULES                                                                        #
################################################################################

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $@ $(OBJ)
	@echo "$(GREEN)$(NAME) compiled.$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) removed.$(NC)"

re: fclean all
