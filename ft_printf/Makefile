
CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRC = 	check_alph_parsing.c \
		check_width_parsing.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_printf.c \
		ft_printf_two.c \
		ft_printf_three.c \
		ft_printf_four.c \
		cap_hex_case.c \
		cap_hex_case_ll.c \
		unsigned_int_case.c \
		octal_case.c \
		char_case.c \
		hex_long_case.c \
		hex_case.c \
		hex_case_two.c \
		perc_case.c \
		ptrcase.c \
		ptrcase_sub.c \
		strcase.c \
		cases.c \
		cases_two.c \
		cases_three.c \
		nbr_case.c \
		nbr_case_two.c \
		nbr_case_three.c \
		nbr_case_four.c \
		nbr_case_five.c \
		nbr_case_six.c \
		wide_char_case.c \
		print_chars.c \


OBJ = $(addsuffix .o, $(basename $(SRC))) 

all: $(NAME) 


$(NAME):
	@ echo "building libftprint.a"
	@ $(CC) $(FLAGS) -c $(SRC)
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)

clean:
	rm -f $(OBJ)	

fclean: clean
	@echo "delete $(NAME)"
	@rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY: re clean fclean all