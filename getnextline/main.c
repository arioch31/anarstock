#include "get_next_line.h"

int main(int ac, char **av)
{
	int fd;
	int res;
	char *str;

	res = 0;
	if (ac == 2)
	{
		fd= open(av[1], O_RDONLY);
		while ((res =get_next_line(fd, &str)) &&res != -1)
		{
			ft_putnbr(res);
			ft_putendl(str);
		}
		close(fd);
		ft_putnbr(res);
		ft_putendl(str);

	}
	if (ac ==1)
	{
		while ((res =get_next_line(0, &str)) &&res != -1)
		{
			ft_putnbr(res);
			ft_putendl(str);
		}
		close(0);
		ft_putnbr(res);
		ft_putendl(str);

	}
	return (0);
}
