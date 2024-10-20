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


// %[flags][width][.precision]specifier

//	[flags]
//		"0"	si ![.precision] && ![flags="-"] => padleft width "0"
//		"#"	if specifier="x" => prefix "0x", if specifier == "X" -> prefix "0X"
//		"-"	padleft devient padright
//		" "	Inclue le sign [" ",  "-"]
//		"+"	Inclue le sign ["+",  "-"] (prend le dessus sur " ")
//	[width]
//		nombre minimal de caracter imprimé
//	[.precision]
//		padleft du nombre avec des "0". signe exclue

int main()
{

	int pos = 42;
	int neg = -42;

	printf("\n d\n");
	printf("[% d]\n", pos);
	printf("[% d]\n", neg);
	printf("[123456789]\n");

	printf("\n+d\n");
	printf("[%+d]\n", pos);
	printf("[%+d]\n", neg);
	printf("[123456789]\n");

	printf("\n0d\n");
	printf("[%0d]\n", pos);
	printf("[%0d]\n", neg);
	printf("[123456789]\n");

	printf("\n8d\n");
	printf("[%8d]\n", pos);
	printf("[%8d]\n", neg);
	printf("[123456789]\n");

	printf("\n 8d\n");
	printf("[% 8d]\n", pos);
	printf("[% 8d]\n", neg);
	printf("[123456789]\n");

	printf("\n08d\n");
	printf("[%08d]\n", pos);
	printf("[%08d]\n", neg);
	printf("[123456789]\n");

	printf("\n 08d\n");
	printf("[% 08d]\n", pos);
	printf("[% 08d]\n", neg);
	printf("[123456789]\n");

	printf("\n.8d\n");
	printf("[%.8d]\n", pos);
	printf("[%.8d]\n", neg);
	printf("[123456789]\n");

	printf("\n .8d\n");
	printf("[% .8d]\n", pos);
	printf("[% .8d]\n", neg);
	printf("[123456789]\n");

	printf("\n8.5d\n");
	printf("[%8.5d]\n", pos);
	printf("[%8.5d]\n", neg);
	printf("[123456789]\n");


	printf("\n08.5d\n");
	printf("[%08.5d]\n", pos);
	printf("[%08.5d]\n", neg);
	printf("[123456789]\n");

	printf("\n2.1d\n");
	printf("[%2.1d]\n", pos);
	printf("[%2.1d]\n", neg);
	printf("[123456789]\n");

	printf("\n5.5d\n");
	printf("[%5.5d]\n", pos);
	printf("[%5.5d]\n", neg);
	printf("[123456789]\n");

	printf("\n6.5d\n");
	printf("[%6.5d]\n", pos);
	printf("[%6.5d]\n", neg);
	printf("[123456789]\n");

	printf("\n 5.5d\n");
	printf("[% 5.5d]\n", pos);
	printf("[% 5.5d]\n", neg);
	printf("[123456789]\n");

	printf("\n 6.5d\n");
	printf("[% 6.5d]\n", pos);
	printf("[% 6.5d]\n", neg);
	printf("[123456789]\n");

}
