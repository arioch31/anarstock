NAME = libft.a

FLAGS = -Wall -Werror -Wextra

SRC_PATH = src/

SRC_CONV_PATH = conv/
SRC_LST_PATH = lst/
SRC_PRINT_PATH = print/
SRC_MEM_PATH = mem/
SRC_STR_PATH = str/

INC_PATH = includes/
OBJ_PATH = obj/

SRC_LST_FILES = ft_lstapp.c		\
			ft_lstlen.c 	\
			ft_lstdelone.c	\
			ft_lstdel.c		\
			ft_lstiter.c	\
			ft_lstmap.c		\
			ft_lstaff.c		\
			ft_lstinsert.c	\
			ft_lstrsplit.c	\
			ft_lstdelpropre.c\
			ft_lstcat.c 	\
			ft_lstcpy.c 	\
			ft_lstnew.c		\
			ft_lstget.c	\
			ft_lstadd.c		\
			ft_lstcmp.c		\
			ft_lstmove.c	\
			ft_lst_tri.c

SRC_MEM_FILES = ft_memalloc.c	\
			ft_memcmp.c		\
			ft_memcpy.c		\
			ft_bzero.c		\
			ft_memmove.c	\
			ft_memset.c		\
			ft_memccpy.c	\
			ft_memchr.c		\
			ft_memdel.c		\

SRC_PRINT_FILES =	ft_putstr.c		\
			ft_putnbr_fd.c	\
			ft_putstr_fd.c	\
			ft_putfloat.c	\
			ft_putdouble.c	\
			ft_putchar.c	\
			ft_putendl.c	\
			ft_putchar_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr.c

SRC_STR_FILES =	ft_striter.c	\
			ft_strnequ.c	\
			ft_striteri.c	\
			ft_strnew.c		\
			ft_strcat.c		\
			ft_strjoin.c	\
			ft_strnstr.c	\
			ft_strchr.c		\
			ft_strlcat.c	\
			ft_strrchr.c	\
			ft_strclr.c		\
			ft_strlen.c		\
			ft_strsplit.c	\
			ft_strcmp.c		\
			ft_strmap.c		\
			ft_strstr.c		\
			ft_strcpy.c		\
			ft_strmapi.c	\
			ft_strsub.c		\
			ft_strdel.c		\
			ft_strncat.c	\
			ft_strtrim.c	\
			ft_strdup.c		\
			ft_strncmp.c	\
			ft_strequ.c		\
			ft_strncpy.c	\
			ft_strseekc.c

SRC_CONV_FILES = ft_isalnum.c	\
			ft_isalpha.c	\
			ft_atoi.c		\
			ft_atoli.c		\
			ft_ispace.c		\
			ft_isascii.c	\
			ft_lenword.c	\
			ft_isdigit.c	\
			ft_isprint.c	\
			ft_itoa.c		\
			ft_ultoa.c		\
			ft_umaxtoa.c		\
			ft_tolower.c	\
			ft_toupper.c	\

SRC_FILES = $(SRC_MAIN_FILES) \
			$(addprefix $(SRC_LST_PATH),$(SRC_LST_FILES))\
			$(addprefix $(SRC_MEM_PATH),$(SRC_MEM_FILES)) \
			$(addprefix $(SRC_STR_PATH),$(SRC_STR_FILES)) \
			$(addprefix $(SRC_PRINT_PATH),$(SRC_PRINT_FILES)) \
			$(addprefix $(SRC_CONV_PATH),$(SRC_CONV_FILES))

OBJ_FILES = $(SRC_FILES:.c=.o)

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_FILES))

SRC = $(addprefix $(SRC_PATH),$(SRC_FILES))

INC = $(addprefix -I,$(INC_PATH))

all: $(OBJ) $(NAME)

obj/%.o: src/%.c
		@mkdir -p $(OBJ_PATH)
		@mkdir -p $(addprefix $(OBJ_PATH),$(SRC_CONV_PATH))
		@mkdir -p $(addprefix $(OBJ_PATH),$(SRC_LST_PATH))
		@mkdir -p $(addprefix $(OBJ_PATH),$(SRC_PRINT_PATH))
		@mkdir -p $(addprefix $(OBJ_PATH),$(SRC_MEM_PATH))
		@mkdir -p $(addprefix $(OBJ_PATH),$(SRC_STR_PATH))
		gcc $(FLAGS) $(INC) -c $< -o $@

$(NAME):
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	@rm -rf $(OBJ_PATH)
fclean:	clean
	@rm -rf $(NAME)

re:	fclean all
