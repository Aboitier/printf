#include <stdio.h>
#include <fcntl.h>
#include "../../libft/libft.h"

int		main(int ac, char **av)
{
	FILE 	*fd;
	char	buf[4096];
	int 	i = 0, j = 0, k = 0, position = 0;

	if (ac > 3)
		return (0);
	if (!(fd = fopen(av[1], "r+")))
		return (0);
	while (!(ft_strchr(buf, '%')))
	{	
		fgets(buf, 75, fd);
//		position = ftell(fd);
//		buf2 = ft_strjoin(buf2, buf);
		if (ft_strchr(buf, '%'))
		{		
//			printf("ftell de 'c' = %ld\n", ftell(fd));
			position = ftell(fd);
			break ;
		}	
	}
	while (buf[i] != '%' && buf[i])
		i++;
	k = i;
	j = 1;
	while (buf[i] && ((buf[i] < 'A' && buf[i] > 'G') || 
			(buf[i] < 'a' && buf[i] > 'g') ||
			(buf[i] != 'm' && buf[i] != 'n') ||
		    (buf[i] < 'p' && buf[i] > 's')))
	{
		i++;
		j++;
	}
	printf("buf[k] == %c\n", buf[k]);
	position = k - i;
	printf("position = %d\nk = %d\ni = %d\nj = %d\n", position, k, i, j);
	fseek(fd, position, SEEK_CUR);
	printf("ftell de 'c' = %ld\n", ftell(fd));
	j = 3;
	while (j > 1)
	{
		fgetc(fd);
	
		printf("apres fgetc = %ld\n", ftell(fd));
		fputc((int)'\b', fd);
	printf("apres fputc' = %ld\n", ftell(fd));
		fflush(fd);
	printf("apres fflush = %ld\n", ftell(fd));
		j--;
	}	
	fclose(fd);
	return (0);
}
