#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main ()
{
	char *x = (char *)malloc(sizeof(char) * 4096);
	char **p = &x;

	int fd = open("texto.txt", O_RDONLY);
	int n;
	while ((n = get_next_line(fd, p)) > 0)
	{
		//printf("Linea: %s\n", *p);
		free(*p);
	}
	if (n == 0)
		//printf("Última linea: %s\n", *p);
	
	close(fd);
	return 0;
}
