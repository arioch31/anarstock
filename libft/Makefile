NAME = libft.a

FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./src/

INC_PATH = ./include/

OBJ_PATH = ./obj/

SRC_FILES =	ft_lstapp.c		\
			ft_memcpy.c		\
			ft_putstr.c		\
			ft_striter.c	\
			ft_strnequ.c	\
			ft_atoi.c		\
			ft_lstdel.c		\
			ft_memdel.c		\
			ft_putstr_fd.c	\
			ft_striteri.c	\
			ft_strnew.c		\
			ft_bzero.c		\
			ft_lstdelone.c	\
			ft_memmove.c	\
			ft_strcat.c		\
			ft_strjoin.c	\
			ft_strnstr.c	\
			ft_isalnum.c	\
			ft_lstiter.c	\
			ft_memset.c		\
			ft_strchr.c		\
			ft_strlcat.c	\
			ft_strrchr.c	\
			ft_isalpha.c	\
			ft_lstmap.c		\
			ft_putchar.c	\
			ft_strclr.c		\
			ft_strlen.c		\
			ft_strsplit.c	\
			ft_isascii.c	\
			ft_lstnew.c		\
			ft_putchar_fd.c	\
			ft_strcmp.c		\
			ft_strmap.c		\
			ft_strstr.c		\
			ft_isdigit.c	\
			ft_memalloc.c	\
			ft_putendl.c	\
			ft_strcpy.c		\
			ft_strmapi.c	\
			ft_strsub.c		\
			ft_isprint.c	\
			ft_memccpy.c	\
			ft_putendl_fd.c	\
			ft_strdel.c		\
			ft_strncat.c	\
			ft_strtrim.c	\
			ft_itoa.c		\
			ft_memchr.c		\
			ft_putnbr.c		\
			ft_strdup.c		\
			ft_strncmp.c	\
			ft_tolower.c	\
			ft_lstadd.c		\
			ft_memcmp.c		\
			ft_putnbr_fd.c	\
			ft_strequ.c		\
			ft_strncpy.c	\
			ft_toupper.c	\
			ft_lstaff.c		\
			ft_lstinsert.c	\
			ft_lstrsplit.c	\
			ft_lstdelpropre.c
			
OBJ = $(addprefix $(OBJ_PATH),$(SRC_FILES:.c=.o))

SRC = $(addprefix $(SRC_PATH),$(SRC_FILES))

INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRC) $(INC)
	@mkdir -p obj
	@mv $(SRC_FILES:.c=.o) ./obj
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	
clean:
	@rm -rf $(OBJ)
fclean:	clean
	@rm -rf $(NAME)

re:	fclean all
