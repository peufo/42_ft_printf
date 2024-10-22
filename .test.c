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

	TEST("%.0i", 42);
	TEST("%.i", 42);
	TEST("%5.0i", 42);
	TEST("%5.i", 42);
	TEST("%-5.0i", 42);
	TEST("%-5.i", 42);
	TEST("%.0d", 42);
	TEST("%.d", 42);
	TEST("%5.0d", 42);
	TEST("%5.d", 42);
	TEST("%-5.0d", 42);
	TEST("%-5.d", 42);
	TEST("%.0u", 42);
	TEST("%.u", 42);
	TEST("%5.0u", 42);
	TEST("%5.u", 42);
	TEST("%-5.0u", 42);
	TEST("%-5.u", 42);
	TEST("%.0x", 42);
	TEST("%.x", 42);

	TEST("%.0i", 0);
	TEST("%.i", 0);
	TEST("%5.0i", 0);
	TEST("%5.i", 0);
	TEST("%-5.0i", 0);
	TEST("%-5.i", 0);
	TEST("%.0d", 0);
	TEST("%.d", 0);
	TEST("%5.0d", 0);
	TEST("%5.d", 0);
	TEST("%-5.0d", 0);
	TEST("%-5.d", 0);
	TEST("%.0u", 0);
	TEST("%.u", 0);
	TEST("%5.0u", 0);
	TEST("%5.u", 0);
	TEST("%-5.0u", 0);
	TEST("%-5.u", 0);
	TEST("%.0x", 0);
	TEST("%.x", 0);

}
