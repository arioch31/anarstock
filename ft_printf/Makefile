NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./src/

INC_PATH = ./includes/

INC_LIB_PATH = ../libft/includes

OBJ_PATH = ../libft/obj/

SRC_FILES =	checker.c converter.c ft_printf.c ft_wchar.c padder.c param.c utils.c buff_arg.c

OBJ = $(addprefix $(OBJ_PATH),$(SRC_FILES:.c=.o))

SRC = $(addprefix $(SRC_PATH),$(SRC_FILES))

INC = $(addprefix -I,$(INC_PATH))

INC_LIB = $(addprefix -I,$(INC_LIB_PATH))

all: lib_make $(NAME)

lib_make:
	make -C ../libft/
lib_re:
	make -C ../libft/ re
lib_fclean:
	make -C ../libft/ fclean
$(NAME):
	gcc -c $(FLAGS) $(SRC) $(INC) $(INC_LIB)
	mkdir -p ../libft/obj
	mv $(SRC_FILES:.c=.o) ../libft/obj
	cp ../libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
clean:
	rm -rf $(OBJ)
fclean:	clean lib_fclean
	rm -rf $(NAME)
re:	fclean all
