#!/usr/bin/make -f
NAME = libft_memmgr.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INC = -I inc
SRC_DIR = src
SRC = \
	ft_mchain\
	ft_memalloc\
	ft_memdel\
	ft_memset\
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
	ft_stpcpy\
	ft_stpncpy\
	ft_strcmp
OBJ_DIR = $(SRC_DIR)/obj
OBJ = $(patsubst %, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $@ $(OBJ)
	@echo "$(NAME) compiled."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) removed."

re: fclean all
