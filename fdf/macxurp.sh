gcc grid.c -fsanitize=address main.c vertex.c get_next_line.c draw.c list.c -I libft/includes -L libft/ -lft  -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit
