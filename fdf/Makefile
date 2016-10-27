NAME = lem-in

FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./src/

INC_PATH = ./includes/

INC_LIB_PATH = ./libft/includes

SRC_FILES =	

SRC = $(addprefix $(SRC_PATH),$(SRC_FILES))

INC = $(addprefix -I,$(INC_PATH))

INC_LIB = $(addprefix -I,$(INC_LIB_PATH))

all: lib_make $(NAME)

lib_make:
	make -C libft/
lib_re:
	make -C libft/ re
lib_clean:
	make -C libft/ clean
lib_fclean:
	make -C libft/ fclean

$(NAME):
	gcc  $(FLAGS) -o $(NAME) $(SRC) $(INC) $(INC_LIB) -Llibft/ -lft

clean: lib_clean
	rm -rf $(OBJ)
fclean:	lib_fclean
	rm -rf $(NAME)
re:	fclean all
