NAME = ft_ls

SRC = main.c			flags.c				stack.c\
	  fields.c			file_type.c			path.c\
	  push_ordered.c	list_stack.c		formatting.c\
	  formatting.c		output.c			log.c

OBJ = $(SRC:.c=.o)

INCLUDES = -I./libft/includes -I./includes

CFLAGS = -Wall -Wextra -Werror

LIBS = -L./libft -lft

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc $(CFLAGS) $(LIBS) $^ -o $(NAME)

%.o: srcs/%.c
	gcc $(CFLAGS) $(INCLUDES) -c $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
