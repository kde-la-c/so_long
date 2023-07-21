#include "so_long.h"

int main()
{
	// int i = 5;
	int fd = open("main.c", O_RDONLY);
	if (fd != -1)
		printf("lines :%i\n", ft_countlines(fd));
	close(fd);
	fd = open("main.c", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}