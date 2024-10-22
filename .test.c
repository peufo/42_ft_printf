#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "src/ft_printf.c"
#include "src/ft_put_nbr.c"
#include "src/ft_put_unbr.c"
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

/**
 *
 *
 *
 */

int main()
{
	//int n = 42;
	// char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";

	printf("\n");
	printf("[%8.3u]\n", 8375);
	ft_printf("[%8.3u]\n", 8375);

	printf("\n");
	printf("[%-8.3u]\n", 8375);
	ft_printf("[%-8.3u]\n", 8375);

	printf("\n");
	printf("[%8.3u]\n", -8375);
	ft_printf("[%8.3u]\n", -8375);

	printf("\n");
	printf("[%-8.3u]\n", -8375);
	ft_printf("[%-8.3u]\n", -8375);

}
