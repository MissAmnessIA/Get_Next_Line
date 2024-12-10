#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	char *s;

	fd = open("file", O_RDONLY);
	while (1)
	{
		s = get_next_line(fd);
		printf("%s", s);
		if (!s)
			break;
		free(s);
	}
	return (0);
}