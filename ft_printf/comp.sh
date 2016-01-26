make -C libft/
gcc -o test ft_printf.c padder.c -I. -Ilibft/includes/ -Llibft/ -lft
