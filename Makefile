CC = gcc
FLAGS = -g -Wall -Wextra -Werror -I includes
LIBFT = libft/libft.a
NAME = ft_ls
SRC = srcs/main.c \
	srcs/parsing_module.c \
	srcs/insert_fls_into_lst.c \


OBJ = $(addsuffix .o, $(basename $(SRC)))

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	make -C libft/

$(NAME):$(LIBFT) $(PRINTF) $(NAME) $(OBJ)
	@echo "building binary file"
	@$(CC) $(FLAGS) $(SRC) -o $(NAME) -I -lft $(LIBFT)

%.o: %.c ft_ls.h
		clang $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make clean -C libft/

fclean: clean
	@echo "delete $(NAME)"
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all

.PHONY: re clean fclean all
