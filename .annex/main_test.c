#include <stdio.h>
#include "../files/includes/head.h"


int	main (void)
{
	char c41 = 'c';
	int d40 = 1119;
	unsigned int o33 = 5831;
	unsigned int o32 = 25171;
	unsigned int X31 = 23490;
	unsigned int x30 = 3150;
	char c23 = 'o';
	unsigned int X22 = 15177;
	int d21 = -9459;
	unsigned int o20 = 4924;
	unsigned int u13 = 17666;
	int i12 = -490;
	int d11 = 8197;
	unsigned int x10 = 22685;
	char str00[400] = "Hauntology (a portmanteau of haunting and ontology[1]) is a concept coined by philosopher Jacques Derrida in his 1993 book Spectres of Marx.";

	ft_printf("s Hauntology (a portmanteau of haunting and ontology[1]) is a concept coined by philosopher Jacques Derrida in his 1993 book Spectres of Marx. = %s\n", str00);
	ft_printf(""_BBLUE"x"_END" "_MAGENTA"22685"_END" >"_CYAN""_END"<; = %x\n"_BBLUE"d"_END" "_MAGENTA"8197;"_END" = %d\n"_BBLUE"i"_END" "_MAGENTA"-490"_END" >"_RED"3.15"_END"<; = %3.15i\n"_BBLUE"u"_END" "_MAGENTA"17666;"_END" = %u\n", x10,d11,i12,u13);
	ft_printf(""_BBLUE"o"_END" "_MAGENTA"4924"_END" >"_RED"l"_END"<; = %lo\n"_BBLUE"d"_END" "_MAGENTA"-9459;"_END" = %d\n"_BBLUE"X"_END" "_MAGENTA"15177"_END" >"_RED""_END"<; = %X\n"_BBLUE"c"_END" "_MAGENTA"'o';"_END" = %c\n", o20,d21,X22,c23);
	ft_printf(""_BBLUE"x"_END" "_MAGENTA"3150"_END" >"_RED".41"_END"<; = %.41x\n"_BBLUE"X"_END" "_MAGENTA"23490;"_END" = %X\n"_BBLUE"o"_END" "_MAGENTA"25171"_END" >"_CYAN""_END"<; = %o\n"_BBLUE"o"_END" "_MAGENTA"5831;"_END" = %o\n", x30,X31,o32,o33);
	ft_printf(""_BBLUE"d"_END" "_MAGENTA"1119"_END" >"_RED"-.18"_END"<; = %-.18d\n"_BBLUE"c"_END" "_MAGENTA"'c';"_END" = %c\n", d40,c41);
	return (0);
}
