make -C libft/
gcc -o test main.c ft_printf.c converter.c checker.c param.c padder.c -I. -Ilibft/includes/ -Llibft/ -lft
