CC = gcc
FLAGS = -g -Wall -Wextra -Werror -I includes
LIBFT = libft/libft.a
NAME = ft_ls
SRC = srcs/main.c \
	srcs/parsing_module.c \
	srcs/alloc_list.c \
	srcs/get_info_fields.c \
	srcs/extract_date_time.c \
	srcs/output_module.c \
	srcs/output_flags.c \
	srcs/error_message.c \
	srcs/handle_sngl_fl.c \
	srcs/parse_args.c \
	srcs/sort_args.c \
	srcs/extract_permissions_mode.c \
	srcs/free_list.c \
	srcs/alloc_fields.c \
	srcs/directory_no_access.c \

OBJ = $(addsuffix .o, $(basename $(SRC)))

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft/

$(NAME):$(LIBFT) $(NAME) $(OBJ)
	@echo "building binary file"
	$(CC) $(FLAGS) $(SRC) -o $(NAME) -I -lft $(LIBFT)

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
