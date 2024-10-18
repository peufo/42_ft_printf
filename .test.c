#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
	char *str = malloc(8);
	char *s1 = NULL;
	unsigned long ul = 45663;

	strcpy(str, "YOLO");

	write(1, "prout: %\n", 10);

	printf("str -> %p\n", str);
	printf("s1 -> %p\n", s1);
	printf("s1 -> %p\n", (void *)ul);

	free(str);

}
