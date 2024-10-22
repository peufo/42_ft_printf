#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "src/ft_printf.c"
#include "src/ft_put.c"
#include "src/ft_atoi.c"
#include "src/ft_itoa.c"
#include "src/handle_flag.c"
#include "src/format_c.c"
#include "src/format_di.c"
#include "src/format_p.c"
#include "src/format_percent.c"
#include "src/format_s.c"
#include "src/format_u.c"
#include "src/format_x.c"


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
		printf("expected : %d\nreceived : %d\n", expected, received) \

int main()
{
	int expected;
	int received;

	TEST("{%03.2d}", 0);
	TEST("p6 %.0d\n", 100);
	TEST("p7 %.4d\n", 100);
	TEST("p14 %.0i\n", 100);
	TEST("p15 %.4i\n", 100);
	TEST("p22 %.0x\n", 100);
	TEST("p30 %.0u\n", 100);
	TEST("%.5d\n", -2372);
	TEST("t3 %50.0d\n", 10);
	TEST("%20.5d", 1024);
	TEST("%20.5d", -1024);
	TEST("%20.5i", 1024);
	TEST("%20.5i", -1024);
	TEST("%020.5d", 1024);
	TEST("%020.5d", -1024);
	TEST("%020.5i", 1024);
	TEST("%020.5i", -1024);
	TEST("%20.0d", 1024);
	TEST("%20.d", -1024);
	TEST("%20.0i", 1024);

}
