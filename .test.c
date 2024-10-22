#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "src/ft_string.c"
#include "src/ft_printf.c"
#include "src/ft_put.c"
#include "src/ft_run.c"
#include "src/ft_atoi.c"
#include "src/ft_itoa.c"
#include "src/ft_format.c"
#include "src/ft_format_c.c"
#include "src/ft_format_di.c"
#include "src/ft_format_p.c"
#include "src/ft_format_percent.c"
#include "src/ft_format_s.c"
#include "src/ft_format_u.c"
#include "src/ft_format_x.c"



// %[flags][width][.precision]specifier

//	[flags]
//		"0"	si ![.precision] && ![flags="-"] => padleft width "0"
//		"#"	if specifier="x" => prefix "0x", if specifier == "X" -> prefix "0X"
//		"-"	width padleft devient padright " "
//		" "	Inclue le sign [" ",  "-"]
//		"+"	Inclue le sign ["+",  "-"] (prend le dessus sur " ")
//	[width]
//		nombre minimal de caracter imprimé
//	[.precision]
//		padleft du nombre avec des "0". signe exclue

#define TEST(...) \
	printf("\n%s:%d\n[", __FILE__, __LINE__); \
	expected = printf(__VA_ARGS__); \
	printf("]\n"); \
	ft_printf("["); \
	received = ft_printf(__VA_ARGS__); \
	ft_printf("]\n"); \
	if (expected != received) \
		printf("expected : %d\nreceived : %d\n", expected, received); \

int main()
{
	int expected;
	int received;

	TEST("hey %d", 0)
	TEST("hoo %d", 5)

}
