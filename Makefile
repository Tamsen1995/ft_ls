CC = gcc
FLAGS = -g -Wall -Wextra -Werror -I includes
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
NAME = ft_ls
SRC = srcs/ft_ls_main.c \
	srcs/parsing_module.c \


OBJ = $(addsuffix .o, $(basename $(SRC)))

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	make -C libft/

$(PRINTF):
	make -C ft_printf/

$(NAME):$(LIBFT) $(PRINTF) $(NAME) $(OBJ)
	@echo "building binary file"
	@$(CC) $(FLAGS) $(SRC) -o $(NAME) -I -lft $(PRINTF) $(LIBFT)

%.o: %.c ft_ls.h
		clang $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make clean -C libft/
	@make clean -C ft_printf/

fclean: clean
	@echo "delete $(NAME)"
	@rm -f $(NAME)
	@make fclean -C libft/
	@make fclean -C ft_printf/
re: fclean all

.PHONY: re clean fclean all
