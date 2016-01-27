make -C libft/
gcc -o test ft_printf.c checker.c param.c padder.c -I. -Ilibft/includes/ -Llibft/ -lft
