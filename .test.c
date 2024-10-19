#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "ft_printf.h"




int main()
{
	char c = 'a';
	int n = 42;
	char str[] = "prout";
	int n_max = INT_MAX;
	int n_min = INT_MIN;

	write(1, "\n", 1);
	printf("bsd d:%d \t i:%i \t c:%c\n", n, n, c);
	ft_printf("ft  d:%d \t i:%i \t c:%c \n", n, n, c);

	write(1, "\n", 1);
	printf("bsd d:%d \t i:%i\n", n_max, n_max);
	ft_printf("ft  d:%d \t i:%i \n", n_max, n_max);

	write(1, "\n", 1);
	printf("bsd d:%d \t i:%i\n", n_min, n_min);
	ft_printf("ft  d:%d \t i:%i \n", n_min, n_min);

	write(1, "\n", 1);
	printf("bsd s:%s percent:%%\n", str);
	ft_printf("ft  s:%s percent:%%\n", str);

	write(1, "\n", 1);
	printf("bsd s:%s\n", str);
	ft_printf("ft  s:%s\n", str);

}





