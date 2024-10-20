#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "src/ft_printf.c"
#include "src/ft_put_long.c"
#include "src/ft_put_ulong.c"
#include "src/format_c.c"
#include "src/format_di.c"
#include "src/format_p.c"
#include "src/format_percent.c"
#include "src/format_s.c"
#include "src/format_u.c"
#include "src/format_x.c"

int main()
{
	char c = 'a';
	int n = 42;
	char str[] = "prout";
	int n_max = INT_MAX;
	int n_min = INT_MIN;
	int un_max = UINT32_MAX;


	write(1, "\n", 1);
	printf("bsd d:%d \t i:%i \t c:%c\n", n, n, c);
	ft_printf("ft  d:%d \t i:%i \t c:%c \n", n, n, c);

	write(1, "\n", 1);
	printf("bsd d:%d \t i:%+i\n", n_max, n_max);
	ft_printf("ft  d:%d \t i:%i \n", n_max, n_max);

	write(1, "\n", 1);
	printf("bsd u:%u \n", un_max);
	ft_printf("ft  u:%u \n", un_max);

	write(1, "\n", 1);
	printf("bsd d:%d \t i:% i\n", n_min, n_min);
	ft_printf("ft  d:%d \t i:%i \n", n_min, n_min);

	write(1, "\n", 1);
	printf("bsd s:%s percent:%%\n", str);
	ft_printf("ft  s:%s percent:%%\n", str);

	write(1, "\n", 1);
	printf("bsd s:%s\n", str);
	ft_printf("ft  s:%s\n", str);

	write(1, "\n", 1);
	printf("bsd p:%p\n", str);
	ft_printf("ft  p:%p\n", str);

	write(1, "\n", 1);
	printf("bsd x:%x\n", n_max);
	ft_printf("ft  x:%x\n", n_max);
	write(1, "\n", 1);
	printf("bsd X:%#X\n", n_max);
	ft_printf("ft  X:%X\n", n_max);

	write(1, "\n", 1);
	printf("TEST \"%-16d\"\n", n_min);
	printf("TEST \"%30d\"\n", n_min);

	write(1, "\n", 1);
	printf("%lx\n", LONG_MAX);

	n = printf("\001\002\007\v\010\f\r\n");
	printf("\n%d", n);
	n = ft_printf("\001\002\007\v\010\f\r\n");
	ft_printf("\n%d", n);

}





