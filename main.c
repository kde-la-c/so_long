#include "so_long.h"

void func(char *str)
{
	ft_memmove(&(*str), "hola", 5);
}

int main()
{
	char *str = NULL;

	func(str);
	printf("%s\n", str);
	return (0);
}