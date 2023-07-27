#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

void leaks() {
	system("leaks ye");
}

void f() {
	char *str = strdup("asda~");
	printf("%s\n", str);
}

int main() {
	atexit(leaks);
	f();
	exit(1);
}