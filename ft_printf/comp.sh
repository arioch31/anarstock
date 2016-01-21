make -C libft/ fclean && make -C libft/
gcc -o test ft_printf.c -Ilibft/includes/ -Llibft/ -lft
