#include <stdio.h>
#include "../printf_files/head.h"

int		main(int ac, char **av)
{
		printf("%hh o%hhd%ll#X", o00,d01,X02);
		printf("%hh0i", i10);
		printf("%hh0d%p", d20,ptr21);
		printf("%h0x", x30);
		printf("%o%p%o", o00,ptr01,o02);
		printf("%p", ptr10);
		printf("%x%X", x20,X21);
		printf("%d%d%s%u", d30,d31,str32,u33);
	return (0);
}
