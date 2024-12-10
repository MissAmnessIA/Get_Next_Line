#include "get_next_line.h"
#include "stdio.h"

int main(void)
{
	char *s;

	int	fd = open("test", O_RDONLY);
	
	while (1)
	{
		s = get_next_line(fd);
		printf("line = %s\n", s);
		if (!s)
			break;
		free(s);
	}
	return 0;
}