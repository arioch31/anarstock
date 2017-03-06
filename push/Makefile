NAME = push_swap

FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./src/

INC_PATH = ./includes/ \
 			./libft/includes

OBJ_PATH = ./obj/

SRC_FILES =	push_swap.c \
			brute.c \
			controleur.c \
			debug.c \
			operations.c \
			solver.c \
			solverv4.c \
			pusher.c \
			utils.c

OBJ = $(addprefix $(OBJ_PATH),$(SRC_FILES:.c=.o))

SRC = $(addprefix $(SRC_PATH),$(SRC_FILES))

INC = $(addprefix -I,$(INC_PATH))

all: lib_make $(NAME)

lib_make:
	make -C libft/
lib_re:
	make -C libft/ re
lib_fclean:
	make -C libft/ fclean
$(NAME):
	@gcc $(FLAGS) -o $(NAME) $(SRC) $(INC) -Llibft -lft

clean:
		rm -rf $(OBJ)
fclean:	clean lib_fclean
		rm -rf $(NAME)
re:	fclean all
