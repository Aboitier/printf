#include <stdio.h>
#include "../printf_files/head.h"


int     main(void)
{
	char c41 = 'c';
	void *ptr40 = NULL;
	double d31 = -8629;
	double f30 = -684;
	unsigned int x21 = -13716;
	double f20 = -8590;
	unsigned int X11 = 10138;
	char str10[400] = "Hauntology (a portmanteau of haunting and ontology[1]) is a concept coined by philosopher Jacques Derrida in his 1993 book Spectres of Marx.";
	int i00 = 8760;

	printf("%#14hi\n", i00);
	printf("%s\n%+hhX\n", str10,X11);
	printf("%0llf\n%01x\n", f20,x21);
	printf("%014f\n%-4hd\n", f30,d31);
	printf("%p\n%c\n%%", ptr40,c41);
	return (0);
}
